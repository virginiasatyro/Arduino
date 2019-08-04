/***********************************************************************************
 * File: blinkGreenRed
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Agosto de 2019
 * 
 * Teste do modulo led de catodo comum verde e vermelho. 
 * Muda o brilho de verde para vermelho e assim sucessivamente.
***********************************************************************************/

const int redLed   = 6;
const int greenLed = 5;

void setup(){
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop(){
  // red on, green off
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  delay(1000);
  
  // red off, green on 
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  delay(1000);
}
