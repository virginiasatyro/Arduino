/***********************************************************************************
 * File: sirenBuzzer
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Agosto de 2019
 *
 * Esse programa simula o som de uma sirene utilizando um buzzer passivo - piezoeletrico.  
 * pino - -> GND     pino central -> nao conectado     pino S -> I/O
***********************************************************************************/

const int buzzerPin = 8;

float seno;
int freq;
 
void setup() {
 pinMode(buzzerPin, OUTPUT);
}
 
void loop() {
  
 for(int x = 0;x < 180;x++){
  //converte graus para radiando e depois obtém o valor do seno
  seno=(sin(x*3.1416/180));
  //gera uma frequência a partir do valor do seno
  freq = 2000 + (int(seno*1000));
  tone(buzzerPin, freq);
  delay(2);
 }
}
