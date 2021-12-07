/*
//- 4 ---> PWMA
//- 18 ---> AIN2
//- 17 ---> AIN1
//- 19 ---> STBY
//- 16 ---> BIN1
//- 15 ---> BIN2
//- 2 ---> PWMB

- Motor 1: A01 and A02
- Motor 2: B01 and B02
 */
int PWMA = 4;
int AIN2 = 18;
int AIN1 = 17;
int STBY = 19;
int BIN1 = 16;
int BIN2 = 15;
int PWMB = 2;

void leftMotor()
{
  ledcWrite(0,200);
  
}

void leftMotorOFF()
{
  ledcWrite(0,0);
  
}


void rightMotor()
{
  ledcWrite(1,200);

}

void rightMotorOFF()
{
  ledcWrite(1,0);

}

void both()
{
  ledcWrite(0,0);
  ledcWrite(1,0);
  
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
  for (int i=-100; i<200; i++) {
    ledcWrite(0,i);
    ledcWrite(1,i);
    delay(50);
  }
  
}

void setup() {
  Serial.begin(9600);
  
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(STBY, OUTPUT);

  ledcAttachPin(PWMA, 0);
  ledcAttachPin(PWMB, 1);
  ledcSetup(0, 5000, 8);
  ledcSetup(0, 5000, 8);
}




void loop() {

  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);

  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);

  delay(2000);
  digitalWrite(STBY, HIGH);
  leftMotor();
  rightMotor();
  delay(1000);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);

  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
  leftMotor();
  rightMotor();
  delay(1000);
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);

  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
  ledcWrite(0,0);
  ledcWrite(1,0);
  delay(1000);
  both();
  
  digitalWrite(STBY, LOW);
  delay(2000);

  while(true)
  {
    delay(1000);
  }
  
  
  
  int s1 = analogRead(36);
  int s2 = analogRead(39);
  int s3 = analogRead(34);
  int s4 = analogRead(35);
  int s5 = analogRead(32);

  int s6 = analogRead(33);
  int s7 = analogRead(25);
  int s8 = analogRead(26);
  int s9 = analogRead(27);
  int s10 = analogRead(14);


  Serial.print(s1);
  Serial.print("\t");
  Serial.print(s2);
  Serial.print("\t");
  Serial.print(s3);
  Serial.print("\t");
  Serial.print(s4);
  Serial.print("\t");
  Serial.print(s5);
  Serial.print("\t");
  Serial.print(s6);
  Serial.print("\t");
  Serial.print(s7);
  Serial.print("\t");
  Serial.print(s8);
  Serial.print("\t");
  Serial.print(s9);
  Serial.print("\t");
  Serial.println(s10);

  

}
