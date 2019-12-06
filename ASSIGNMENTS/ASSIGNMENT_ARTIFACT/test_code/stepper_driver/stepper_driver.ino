#define DIR_PIN 3
#define STEP_PIN 4
#define EN_PIN 5

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(DIR_PIN,HIGH);//direction

  //200 pulses
  for(int x=0; x<1600; x++){
    digitalWrite(STEP_PIN,HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP_PIN,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

  digitalWrite(DIR_PIN,LOW);//direction

  //200 pulses
  for(int x=0; x<1600; x++){
    digitalWrite(STEP_PIN,HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP_PIN,LOW);
    delayMicroseconds(500);
  }
  delay(1000);


}
