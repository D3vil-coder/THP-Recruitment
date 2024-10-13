/*
Code for Ultrasonic Distance Slave [Slave 1]
Author : Ansh Savla
Date: 13-10-2024
*/

#include <Wire.h>             //Library for I2C Protocol

#define SLAVE_1_ADDRESS 0x08  
// I2C address for Slave 1

#define THRESHOLD 140         
// UV sensor threshold for object detection

const int pingPin = 6;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm;

void setup() {
  Wire.begin(SLAVE_1_ADDRESS);  // Join I2C bus as Slave 1
  Serial.begin(9600);           //To Monitor Dist
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  Wire.onRequest(sendData);     // Register function to send data to Master
  delay(100);                   // A small delay to prevent overwhelming the I2C bus
  //Below is the logic for Ultrasonic Sensor Dist detection
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm= duration*0.034/2;
  Serial.print("Dist: ");
  Serial.println(distanceCm);
}

void sendData() {
  // When Master requests data, send the detection status
  if (distanceCm < THRESHOLD) {
    Wire.write(1);  // Send '1' to indicate object detected
  } 
  else if(distanceCm > THRESHOLD){
    Wire.write(0);  // Send '0' if no object is detected
  }
}
