/***********************************************************************************
 * File: activeBuzzer
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Julho de 2019
 *
 * Esse programa testa o buzzer ativo ligando-o e desligando.
 * pino - -> GND     pino central -> nao conectado     pino S -> 5 V
***********************************************************************************/

const int buzzerPin = 3;

void setup(){
  pinMode(buzzerPin, OUTPUT);
}

void loop(){
  // pulsa o buzzer
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
  delay(1000);
}
