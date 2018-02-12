/*
Tests the servo
*/
#include <Servo.h>// Importing the Servo lybrary

#define trigPin1 13
#define echoPin1 12
#define trigPin2 11
#define echoPin2 10
#define pinServo 9

Servo myservo;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  myservo.attach(pinServo);
}

void loop() {
  int startbyte;
  int angle =90;
  
//  if (Serial.available() >1) {
    // Read the first byte
 //   startbyte = Serial.read();
    // If it's really the startbyte (255) ..
 //   if (startbyte == 255) {
 //     get angle for the servo and set the sero to this angle
  //    angle = Serial.read();

      myservo.write(angle); 
      Serial.println(angle);
//    }
//  }
}
