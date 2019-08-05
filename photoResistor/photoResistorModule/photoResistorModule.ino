/***********************************************************************************
 * File: photoResistorModule
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Agosto de 2019
 * 
 * Teste do modulo do photo-resistor. O modulo ja vem com um resistor auxiliar de 10k ohm.
***********************************************************************************/

const int photoRPin = A0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  // le o valor no photo resistor
  aux = analogRead(photoRPin);
  Serial.println(aux);
  delay(200);
}
