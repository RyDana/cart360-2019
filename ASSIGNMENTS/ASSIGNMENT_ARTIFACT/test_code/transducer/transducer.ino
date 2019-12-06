// constant for pin to output for buzzer 
#define SPEAKER 9 // PWM
#define BEATTIME 5000
#define SENSOR A0

int threshold = 400;
int value = 0;
int samplesToAverage =16;
float averageSenseVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  value = calcAverage();
  Serial.println(analogRead(SENSOR));
  //Serial.println(value);
  if(value > threshold){
    tone(SPEAKER,value*0.2);
    
  }
  else {
    noTone(SPEAKER);
  }
  delay(20);

  //tone(SPEAKER, 200, BEATTIME);
//  Serial.println("sound");
//  delay(BEATTIME);



//
//  tone(SPEAKER,262,BEATTIME) ; // Do
//  delay(BEATTIME) ;
//  tone(SPEAKER,294,BEATTIME) ; // Re
//  delay(BEATTIME) ;
//  tone(SPEAKER,330,BEATTIME) ; // Mi
//  delay(BEATTIME) ;
//  tone(SPEAKER,349,BEATTIME) ; // Fa
//  delay(BEATTIME) ;
//  tone(SPEAKER,392,BEATTIME) ; // So
//  delay(BEATTIME) ;
//  tone(SPEAKER,440,BEATTIME) ; // La
//  delay(BEATTIME) ;
//  tone(SPEAKER,494,BEATTIME) ; // Si
//  delay(BEATTIME) ;
//  tone(SPEAKER,523,BEATTIME) ; // Do
//  delay(BEATTIME) ;

}

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
