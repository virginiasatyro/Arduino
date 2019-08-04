/***********************************************************************************
 * File: notesBuzzer
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Julho de 2019
 *
 * Esse programa testa tons em um buzzer passivo. 
 * pino - -> GND     pino central -> nao conectado     pino S -> I/O
***********************************************************************************/

void setup() {

}

void loop() {

  noTone(8);         // desliga			
  tone(8, 440, 200); // toca nota 440 por 200 ms
  delay(200);        // espera 200 ms

  noTone(8);
  tone(8, 494, 500);
  delay(500);
  
  noTone(8);  
  tone(8, 523, 300);
  delay(300);

}
