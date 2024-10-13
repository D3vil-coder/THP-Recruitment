/*
Code for Master Arduino
Author: Ansh Savla
Date: 13-10-2024
*/

#include <Wire.h>             //Library for I2C Protocol
#define SLAVE_1_ADDRESS 0x08  
// I2C address for Slave 1

#define SLAVE_2_ADDRESS 0x09  
// I2C address for Slave 2

void setup() 
{
  Wire.begin();            // Start I2C as master
  Serial.begin(9600);      //To monitor message sent bby ULtrasonic sensor
}

void loop() 
{
  Wire.requestFrom(SLAVE_1_ADDRESS, 1);  // Request data from Slave 1
  if (Wire.available()) 
  {
    int objectDetected = Wire.read();    // Read data from Slave 1
    if (objectDetected == 1) {
      Serial.println("Object detected! Sending Stop command to Slave 2.");
      sendStopCommandToSlave2();         // Send stop signal to Slave 2
    }
    else
    {
      Serial.println("Object not detected! Sending Run Command to Slave 1");
      sendRunCommandToSlave2();         // Send Run signal to Slave 2
    }
  }
  delay(100);  // Poll every 100ms
}

void sendRunCommandToSlave2() 
{
  Wire.beginTransmission(SLAVE_2_ADDRESS);  // Start I2C communication with Slave 2
  Wire.write(0);                            // Send '0' as a Run signal
  Wire.endTransmission();                   // End I2C transmission
}

void sendStopCommandToSlave2() 
{
  Wire.beginTransmission(SLAVE_2_ADDRESS);  // Start I2C communication with Slave 2
  Wire.write(1);                            // Send '1' as a stop signal
  Wire.endTransmission();                   // End I2C transmission
}
