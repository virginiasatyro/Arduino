/***********************************************************************************
 * File: blinkGreenRed2
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Agosto de 2019
 * 
 * Teste do modulo led de catodo comum verde e vermelho. 
 * Muda o brilho de verde para vermelho e os dois juntos.
***********************************************************************************/

const int redLed   = 6;
const int greenLed = 5;

void setup(){
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop(){
  // red on
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  delay(1000);
  
  // green on 
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  delay(1000);
  
  // both on
  digitalWrite(redLed, HIGH);
  delay(1000);
}
