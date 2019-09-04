/*  File: ky038_digital_input
 *  Arduino UNO
 *  Arduino IDE
 *  Author: Virgínia Sátyro
 *  License: Free - Open Source
 *  Created on Fevereiro de 2019
 *   
 *  Objetivo: 
 */

#define LED 13  // built-in led 
#define D0  3   // digital input from ky-038

int val = 0;  // input value 

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(D0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(D0); 
  Serial.println(val);

  if(val == HIGH){ // sound detection module detects signal - LED flashes
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}
