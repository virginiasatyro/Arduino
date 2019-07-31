/***********************************************************************************
 * File: recieve_serial
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Janeiro de 2019
 * 
 * Escrever um comando no terminal serial e verificar qual string foi recebida.
***********************************************************************************/

String msg; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    msg = Serial.readString();
    Serial.println(msg);
  }

  if(msg == "um")  { Serial.println("Você digitou um.");}
  if(msg == "dois"){ Serial.println("Você digitou dois.");}
  if(msg == "tres"){ Serial.println("Você digitou tres.");}
  else             { Serial.println("Mensagem não identificada!");}
  delay(400);
}
