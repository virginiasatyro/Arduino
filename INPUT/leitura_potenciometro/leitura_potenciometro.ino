/***********************************************************************************
 * File: leitura_potenciometro
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Janeiro de 2019
 * 
 * Leitura de um potenciômetro de 10k através da entrada analógica A0. 
 * O Arduino tem leitura analógica de 10 bits (0 a 1023).
***********************************************************************************/
const int pot = A0; // potenciômetro no pino A0

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int leitura = analogRead(pot); // lê o valor do potenciômetro
  Serial.println(leitura);       // valor entre 0 e 1023
  
  delay(1); // delay entre leituras - estabilidade
}
