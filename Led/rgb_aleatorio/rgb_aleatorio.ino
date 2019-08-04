/***********************************************************************************
 * File: rgb_aleatorio
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Janeiro de 2019
 * 
 * Ativa cores do LED RGB de forma aleatória utilizando a função rand() que fornece
 * um número de 0 a 255 utilizado no PWM.
***********************************************************************************/
#include <stdlib.h>

// pinos do LED
const int azul = 9;
const int verde = 10;
const int vermelho = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // pinos do LED declarados como saída
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(azul, LOW);
  analogWrite(verde, rand()%255);
  analogWrite(vermelho, rand()%255);
  delay(400);
  digitalWrite(azul, LOW);
  digitalWrite(verde, LOW);
  analogWrite(vermelho, rand()%255);
  delay(100);
  analogWrite(azul, rand()%255);
  digitalWrite(verde, LOW);
  analogWrite(vermelho, rand()%255);
  delay(400);
  analogWrite(azul, rand()%255);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, LOW);
  delay(100);
  analogWrite(azul, rand()%255);
  analogWrite(verde, rand()%255);
  digitalWrite(vermelho, LOW);
  delay(400);
  digitalWrite(azul, LOW);
  analogWrite(verde, rand()%255);
  digitalWrite(vermelho, LOW);
  delay(100);
}
