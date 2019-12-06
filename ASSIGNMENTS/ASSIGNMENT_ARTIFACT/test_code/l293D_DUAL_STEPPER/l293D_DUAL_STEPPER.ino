#define MOTOR_EN_1_2  10
#define MOTOR_EN_3_4  11
#define MOTOR_IN1     9
#define MOTOR_IN2     8
#define MOTOR_IN3     12
#define MOTOR_IN4     13
 
#define forward  0
#define backward 1
 
#define slow   10
#define normal 5
#define fast   2
 
#define single_step   0
#define power_step    1
#define half_step     2
 
int speeed; //correct prononciation is a function
int direcshen;
int stepping;
 
void stepp(void){
  
  digitalWrite(MOTOR_EN_1_2, HIGH);
  digitalWrite(MOTOR_EN_3_4, HIGH);
  
if (direcshen==forward){
  if (stepping==single_step){
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, LOW);
    Serial.println('single step');
    delay(speeed);
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, LOW);
    delay(speeed);
    Serial.println('single step');
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN4, LOW);
    delay(speeed);
    Serial.println('single step');
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, HIGH);
    delay(speeed);
    Serial.println('single step');
  }
  if (stepping==half_step){
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, HIGH);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN4, LOW);
    delay(speeed);  
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN4, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN4, HIGH);
    delay(speeed);
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, HIGH);
    delay(speeed);
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, HIGH);
    delay(speeed);     
  }
  if (stepping==power_step){
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, HIGH);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN4, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN4, HIGH);
    delay(speeed);
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, HIGH);
    delay(speeed);        
  }  
 }
 if (direcshen==backward){
  if (stepping==single_step){
    digitalWrite(MOTOR_IN4, HIGH);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN1, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN4, LOW);
    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN1, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN4, LOW);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
    digitalWrite(MOTOR_IN1, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN4, LOW);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN1, HIGH);
    delay(speeed);  
  }
  if (stepping==half_step){
    digitalWrite(MOTOR_IN4, HIGH);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN1, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN4, HIGH);
    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN1, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN4, LOW);
    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN1, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN4, LOW);
    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN2, HIGH);
    digitalWrite(MOTOR_IN1, LOW);
    delay(speeed);  
    digitalWrite(MOTOR_IN4, LOW);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
    digitalWrite(MOTOR_IN1, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN4, LOW);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
    digitalWrite(MOTOR_IN1, HIGH);
    delay(speeed);
    digitalWrite(MOTOR_IN4, LOW);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN1, HIGH);
    delay(speeed);
    digitalWrite(MOTOR_IN4, HIGH);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN1, HIGH);
    delay(speeed);     
  }
  if (stepping==power_step){
    digitalWrite(MOTOR_IN4, HIGH);
    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN1, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN4, LOW);
    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN2, HIGH);
    digitalWrite(MOTOR_IN1, LOW);
    delay(speeed);
    digitalWrite(MOTOR_IN4, LOW);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
    digitalWrite(MOTOR_IN1, HIGH);
    delay(speeed);
    digitalWrite(MOTOR_IN4, HIGH);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN1, HIGH);
    delay(speeed);        
  }  
 }
}
 
void setup() {
  
  Serial.begin(9600);
  Serial.println("L293D Stepper motor test");
 
  pinMode(MOTOR_EN_1_2, OUTPUT);
  pinMode(MOTOR_EN_3_4, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_IN3, OUTPUT);
  pinMode(MOTOR_IN4, OUTPUT);
  
}
 
void loop() {
 
  direcshen=forward;     // choose forward or backward
  speeed=fast;           // choose slow, normal or fast
  stepping=half_step;    // choose single, power or half step
  for (int i=0;i<=60;i++)
  {stepp();}
 
  direcshen=backward;     // choose forward or backward
  speeed=normal;           // choose slow, normal or fast
  stepping=power_step;    // choose single, power or half step
  for (int i=0;i<=50;i++)
  {stepp();}
 
  direcshen=backward;     // choose forward or backward
  speeed=slow;;           // choose slow, normal or fast
  stepping=single_step;    // choose single, power or half step
  for (int i=0;i<=30;i++)
  {stepp();}
  
}
