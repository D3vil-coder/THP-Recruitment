/*
Code for Motor Slave[Slave 2]
Author: Ansh Savla
date: 13-10-2024
*/

#include <Wire.h>                 //Library for I2C Protocol

#define SLAVE_2_ADDRESS 0x09  
// I2C address for Slave 2

#define MOTOR_PIN 9           
// Pin where motor is connected

int command = 0;                  // Variable to store the received command

void setup() 
{
  Wire.begin(SLAVE_2_ADDRESS);    // Join I2C bus as Slave 2
  pinMode(MOTOR_PIN, OUTPUT);
  Serial.begin(9600);
  digitalWrite(MOTOR_PIN, HIGH);  // Initially start the motor (HIGH = running)
}

void loop() 
{
  // Continuously check the command and control the motor
    Wire.onReceive(receiveData);    // Register function to receive data from Master
  if (command == 1) 
  {
    // If command is 1, stop the motor
    digitalWrite(MOTOR_PIN, LOW);   // Stop the motor (LOW = stopped)
  } else {
    // If command is not 1, keep the motor running
    digitalWrite(MOTOR_PIN, HIGH);  // Run the motor (HIGH = running)
  }
	Serial.println(command);
  delay(100);                       // Small delay to avoid rapid toggling
}

void receiveData(int byteCount) 
{
  // Receive the command sent by the Master Arduino
  if (Wire.available()) 
  {
    command = Wire.read();  // Read the received command
  }
}
