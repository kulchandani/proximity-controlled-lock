#import <Servo.h>

int trigPin = 11;
int echoPin = 12;
int tottime;
int dt = 100;
int dtt = 200;
int servoPin=10;
int servoPos;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delay(dt);
  digitalWrite(trigPin,HIGH);
  delay(dt);
  digitalWrite(trigPin,LOW);
  tottime = pulseIn(echoPin,HIGH);
  Serial.println(tottime);
  if (tottime<700){
    servoPos=180;
  }
  else{
    servoPos=0;
  }
  myServo.write(servoPos);
  delay(dtt);
}
