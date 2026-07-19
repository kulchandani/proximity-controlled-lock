#include <ESP32Servo.h>

int trigPin = 5;
int echoPin = 18;
int servoPin = 19;
int tottime;
int dt = 500;

Servo myServo;
bool isNear = false;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  tottime = pulseIn(echoPin, HIGH);
  Serial.println(tottime);

  bool nowNear = (tottime < 2000 && tottime > 0);  // second condition guards against timeout misread

  if (nowNear != isNear) {
    myServo.write(nowNear ? 180 : 0);
    isNear = nowNear;
  }

  delay(dt);
}