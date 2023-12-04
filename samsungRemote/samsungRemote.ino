/*
Author: Colin Wong (@monopolyroku)
Title: Samsung smart TV remote (arduino based)  
Description: 

*/


#include <IRremote.hpp>

// pin definitions
#define irTransmit 10
#define powerBut 9
#define led1 11

#define downBut 6
#define led2 7

#define upBut 5
#define rightBut 4
#define leftBut 3

// variable definitions
IRsend irsend(irTransmit);
int powerState = 0;
int downState = 0;
int upState = 0;
int rightState = 0;
int leftState = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(powerBut, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(downBut, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(upBut, INPUT);
  pinMode(rightBut, INPUT);
  pinMode(leftBut, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  powerState = digitalRead(powerBut);
  downState = digitalRead(downBut);
  upState = digitalRead(upBut);
  rightState = digitalRead(rightBut);
  leftState = digitalRead(leftBut);

  // conditional statements for diff buttons
  if (powerState == 1) {
    delay(50);
    irsend.sendSAMSUNG(0xE0E040BF,32);
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    // for debugging
    // Serial.print("Hex code: 0xE0E040BF");
    // Serial.print("Power state:");
    // Serial.println(powerState);
    // delay(500);
  }

  // Down direction 
  if (downState == 1) {
    delay(50);
    irsend.sendSAMSUNG(0xE0E08679, 32);
    Serial.println("Down button activated");
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led2, LOW);
  }

  // Up direction
  if (upState == 1) {
    delay(50);
    irsend.sendSAMSUNG(0xE0E006F9, 32);
    Serial.println("Up button activated");
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led2, LOW);
  }

    // Right direction
  if (rightState == 1) {
    delay(50);
    irsend.sendSAMSUNG(0xE0E046B9, 32);
    Serial.println("Right button activated");
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led2, LOW);
  }

    // Left direction
  if (leftState == 1) {
    delay(50);
    irsend.sendSAMSUNG(0xE0E0A659, 32);
    Serial.println("Left button activated");
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led2, LOW);
  }
  
  // for debugging
  // Serial.print("Power state:");
  // Serial.println(powerState);
  // delay(500);
}
