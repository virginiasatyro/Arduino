/***********************************************************************************
 * File: soundSensor_digital
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Julho de 2019
 * 
 * Esse programa testa o sensor sonoro KY-038 atraves de sua entrada digital.
 * Existem duas entradas nesse sensor, um digital e outro analogico.
 * A saida digital fornece um valor 1 ou 0, alto ou baixo. Esse valor depende do 
 * ajuste feito no potenciometro. 
***********************************************************************************/

const int soundPin = 8; // sound sensor pin

int sound = 0; // value of the sensor

void setup(){
  Serial.begin(9600);
  pinMode(soundPin, INPUT);
}

void loop(){
 
  sound = digitalRead(soundPin); // digital read sensor
  Serial.print("Saida D0: ");
  Serial.println(sound);
  
  delay(50);
}
