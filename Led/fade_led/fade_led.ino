/***********************************************************************************
 * File: fade_led
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on 18 de Janeiro de 2019
 * 
 * Utilizando PWM, aumentamos e diminuímos a intensidade luminosa do LED.
***********************************************************************************/

int LED = 10; // pino PWM 
int brilho = 0; //  intensidade/brilho do LED
int fadeQuantidade = 5; // pontos na escala do brilho 

// the setup routine runs once when you press reset:
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); // saída do LED 
}

// the loop routine runs over and over again forever:
void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED, brilho); // seta o brilho no LED

  brilho = brilho + fadeQuantidade;

  if(brilho <= 0 || brilho >= 255){ // definição se aumenta ou diminui o brilho
    fadeQuantidade = -fadeQuantidade;
  }

  delay(50); // espera x milissegundos
}
