/*
controls the servo and measures the distance
 
Source for distance code:
    HC-SR04 Ping distance sensor]
    VCC to arduino 5v GND to arduino GND
    Echo to Arduino pin 12 Trig to Arduino pin 13
    More info at: http://goo.gl/kJ8Gl
    Original code improvements to the Ping sketch sourced from Trollmaker.com
    Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
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
  if (Serial.available() > 2) {
    // Read the first byte
    startbyte = Serial.read();
    // If it's really the startbyte (255) ..
    if (startbyte == 255) {
     // get angle for the servo and set the sero to this angle
      angle = Serial.read();

      myservo.write(angle); 

      // get the distance for sensor 1
      long duration1, distance1;
      digitalWrite(trigPin1, LOW);  // Added this line
      delayMicroseconds(2); // Added this line
      digitalWrite(trigPin1, HIGH);
      delayMicroseconds(10); // Added this line
      digitalWrite(trigPin1, LOW);
      duration1 = pulseIn(echoPin1, HIGH);
      distance1 = (duration1/2) / 29.1;  
      Serial.println(distance1);

      // get the distance for sensor 2
      long duration2, distance2;     
      digitalWrite(trigPin2, LOW);  // Added this line
      delayMicroseconds(2); // Added this line
      digitalWrite(trigPin2, HIGH);
      delayMicroseconds(10); // Added this line
      digitalWrite(trigPin2, LOW);
      duration2 = pulseIn(echoPin2, HIGH);
      distance2 = (duration2/2) / 29.1;  
      Serial.println(distance2);
      delay(500);

    }
  }
}
