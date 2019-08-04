/***********************************************************************************
 * File: passiveBuzzer
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Agosto de 2019
 *
 * Esse programa testa o buzzer passivo. Esse programa toca uma melodia repetidamente. 
 * pino - -> GND     pino central -> nao conectado     pino S -> pino de controle
***********************************************************************************/

#include "pitches.h"

const int buzzerPin = 8; 

// notas da melodia 
int melody[] = {NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// duraçao das notas: 4 = um quarto, 8 = um oitavo, etc.
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup(){
  pinMode(buzzerPin, OUTPUT);
}

void loop(){
  // notas da melodia
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // calculo da duracao das notas
    // um quarto de nota = 1000/4, um oitavo = 1000/8 
    int noteDuration = 1000/noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote],noteDuration);

    // para distinguir as notas, definir um tempo entre elas
    // duracao da nota + 30% funciona bem
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // para o som
    noTone(buzzerPin);
  } 
  delay(2000);
}
