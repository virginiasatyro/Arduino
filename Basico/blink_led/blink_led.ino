/***********************************************************************************
 * File: blink_led
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on 18 de Janeiro de 2019
 * Pisca LED de 1 em 1 segundo
***********************************************************************************/
const int LED = 10;

// the setup function runs once when you press reset or power the board
void setup() {
  // put your setup code here, to run once:
  // inicializar o pino digital LED_BUILTIN como saída
  pinMode(LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH); // acende o LED
  delay(1000);             // espera 1s 
  digitalWrite(LED, LOW);  // desliga LED
  delay(1000);             // espera 1s
}
