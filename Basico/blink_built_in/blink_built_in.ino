/***********************************************************************************
 * File: blink_built_in
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on 18 de Janeiro de 2019
 * Pisca LED imbutido de 1 em 1 segundo
***********************************************************************************/

// the setup function runs once when you press reset or power the board
void setup() {
  // put your setup code here, to run once:
  // inicializar o pino digital LED_BUILTIN como saída
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH); // acende o LED
  delay(1000);                     // espera 1s 
  digitalWrite(LED_BUILTIN, LOW); // desliga LED
  delay(1000);                     // espera 1s
}
