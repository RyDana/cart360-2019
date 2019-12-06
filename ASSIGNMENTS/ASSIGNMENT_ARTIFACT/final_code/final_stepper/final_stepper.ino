#include <Wire.h>

#define BMP085_ADDRESS 0x77  // I2C address of BMP085
//motor pins
#define DIR_PIN 3
#define STEP_PIN 4
#define EN_PIN 5
//transducer and microphone pin and constants
#define SPEAKER 9 // PWM
#define BEATTIME 5000
#define SENSOR A0 //microphone

const unsigned char OSS = 0;  // BME Oversampling Setting
// BME Calibration values
int ac1;
int ac2; 
int ac3; 
unsigned int ac4;
unsigned int ac5;
unsigned int ac6;
int b1; 
int b2;
int mb;
int mc;
int md;

//storing pressure and temperature calculation results
long b5; 

short temperature;
long pressure;

//for altitude conversions
const float p0 = 101325;     // Pressure at sea level (Pa)
float altitude;

//pressure thresholds
int thresholdBMEMin = 98000;
int thresholdBMEMax = 100000;

//transducer and microphone variables
int thresholdMic = 400;
int value = 0;
int samplesToAverage =16;
float averageSenseVal = 0;


void setup()
{  
  Serial.begin(9600);
  Wire.begin();
  bmp085Calibration();
  // Change these to suit your stepper if you want
  pinMode(STEP_PIN,OUTPUT);
  pinMode(DIR_PIN,OUTPUT);
  pinMode(EN_PIN,OUTPUT);
  digitalWrite(EN_PIN,LOW);

}

void loop()
{
    //BME pressure calculations
    temperature = bmp085GetTemperature(bmp085ReadUT());
    pressure = bmp085GetPressure(bmp085ReadUP());
    
    Serial.print(temperature, DEC);
    Serial.print(" ");
    Serial.print(pressure, DEC);
    Serial.println();

    //Microphone average calculaion
    value = calcAverage();
    Serial.println(analogRead(SENSOR));

    
    // Stepper rotation control 
    if(pressure > thresholdBMEMax){
      digitalWrite(DIR_PIN,HIGH);//direction
      digitalWrite(STEP_PIN,HIGH);
    }else if(pressure < thresholdBMEMin){
      digitalWrite(DIR_PIN,LOW);//direction
      digitalWrite(STEP_PIN,HIGH);
    }
    else{
      digitalWrite(STEP_PIN,LOW);
    }

    //transducer output control
    if(value > thresholdMic){
      tone(SPEAKER,value*0.2);  
    } else {
      noTone(SPEAKER);
    }

    delayMicroseconds(500);
}

//calculate average input from microphone
int calcAverage(){
  averageSenseVal = 0;
  for(int i=0; i<samplesToAverage;i++){
    int sensorValue = analogRead(SENSOR);
    Serial.print(analogRead(SENSOR));
    //Serial.print(sensorValue);
    //Serial.print("++");
    averageSenseVal+=sensorValue;
    //Serial.print(averageSenseVal);
    Serial.print(" ");
    delay(1);
  }
  Serial.println(averageSenseVal/samplesToAverage);
  return averageSenseVal/samplesToAverage;
}

// Calculate temperature given ut.
// Value returned will be in units of 0.1 deg C
short bmp085GetTemperature(unsigned int ut)
{
  long x1, x2;
  
  x1 = (((long)ut - (long)ac6)*(long)ac5) >> 15;
  x2 = ((long)mc << 11)/(x1 + md);
  b5 = x1 + x2;

  return ((b5 + 8)>>4);  
}

// Calculate pressure given up
// calibration values must be known
// b5 is also required so bmp085GetTemperature(...) must be called first.
// Value returned will be pressure in units of Pa.
long bmp085GetPressure(unsigned long up)
{
  long x1, x2, x3, b3, b6, p;
  unsigned long b4, b7;
  
  b6 = b5 - 4000;
  // Calculate B3
  x1 = (b2 * (b6 * b6)>>12)>>11;
  x2 = (ac2 * b6)>>11;
  x3 = x1 + x2;
  b3 = (((((long)ac1)*4 + x3)<<OSS) + 2)>>2;
  
  // Calculate B4
  x1 = (ac3 * b6)>>13;
  x2 = (b1 * ((b6 * b6)>>12))>>16;
  x3 = ((x1 + x2) + 2)>>2;
  b4 = (ac4 * (unsigned long)(x3 + 32768))>>15;
  
  b7 = ((unsigned long)(up - b3) * (50000>>OSS));
  if (b7 < 0x80000000)
    p = (b7<<1)/b4;
  else
    p = (b7/b4)<<1;
    
  x1 = (p>>8) * (p>>8);
  x1 = (x1 * 3038)>>16;
  x2 = (-7357 * p)>>16;
  p += (x1 + x2 + 3791)>>4;
  
  return p;
}

// Read the uncompensated temperature value
unsigned int bmp085ReadUT()
{
  unsigned int ut;
  
  // Write 0x2E into Register 0xF4
  // This requests a temperature reading
  Wire.beginTransmission(BMP085_ADDRESS);
  Wire.write(0xF4);
  Wire.write(0x2E);
  Wire.endTransmission();
  
  // Wait at least 4.5ms
  delay(5);
  
  // Read two bytes from registers 0xF6 and 0xF7
  ut = bmp085ReadInt(0xF6);
  return ut;
}

// Read the uncompensated pressure value
unsigned long bmp085ReadUP()
{
  unsigned char msb, lsb, xlsb;
  unsigned long up = 0;
  
  // Write 0x34+(OSS<<6) into register 0xF4
  // Request a pressure reading w/ oversampling setting
  Wire.beginTransmission(BMP085_ADDRESS);
  Wire.write(0xF4);
  Wire.write(0x34 + (OSS<<6));
  Wire.endTransmission();
  
  // Wait for conversion, delay time dependent on OSS
  delay(2 + (3<<OSS));
  
  // Read register 0xF6 (MSB), 0xF7 (LSB), and 0xF8 (XLSB)
  Wire.beginTransmission(BMP085_ADDRESS);
  Wire.write(0xF6);
  Wire.endTransmission();
  Wire.requestFrom(BMP085_ADDRESS, 3);
  
  // Wait for data to become available
  while(Wire.available() < 3)
    ;
  msb = Wire.read();
  lsb = Wire.read();
  xlsb = Wire.read();
  
  up = (((unsigned long) msb << 16) | ((unsigned long) lsb << 8) | (unsigned long) xlsb) >> (8-OSS);
  
  return up;
}

// Stores all of the bmp085's calibration values into global variables
// Calibration values are required to calculate temp and pressure
// This function should be called at the beginning of the program
void bmp085Calibration()
{
  ac1 = bmp085ReadInt(0xAA);
  ac2 = bmp085ReadInt(0xAC);
  ac3 = bmp085ReadInt(0xAE);
  ac4 = bmp085ReadInt(0xB0);
  ac5 = bmp085ReadInt(0xB2);
  ac6 = bmp085ReadInt(0xB4);
  b1 = bmp085ReadInt(0xB6);
  b2 = bmp085ReadInt(0xB8);
  mb = bmp085ReadInt(0xBA);
  mc = bmp085ReadInt(0xBC);
  md = bmp085ReadInt(0xBE);
}

// Read 1 byte from the BMP085 at 'address'
char bmp085Read(unsigned char address)
{
  unsigned char data;
  
  Wire.beginTransmission(BMP085_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  
  Wire.requestFrom(BMP085_ADDRESS, 1);
  while(!Wire.available())
    ;
    
  return Wire.read();
}

// Read 2 bytes from the BMP085
// First byte will be from 'address'
// Second byte will be from 'address'+1
int bmp085ReadInt(unsigned char address)
{
  unsigned char msb, lsb;
  
  Wire.beginTransmission(BMP085_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  
  Wire.requestFrom(BMP085_ADDRESS, 2);
  while(Wire.available()<2)
    ;
  msb = Wire.read();
  lsb = Wire.read();
  
  return (int) msb<<8 | lsb;
}
