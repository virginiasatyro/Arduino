/***********************************************************************************
 * File: photoResistorModule
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Agosto de 2019
 * 
 * Teste do modulo push-button. Botao apertado - acende led por 2s
 * S -> 5V     Meio -> GND   negativo -> 2
***********************************************************************************/

const int buttonPin = 2;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);       // on-board LED, usually pin 13
  pinMode(buttonPin, INPUT);         // push button pin set to input
}

void loop() {
  
  if (digitalRead(buttonPin)) {       // switch closed?
    // switch closed with pull-down resistor
    delay(40);                        // switch debounce delay
    while (digitalRead(buttonPin));   // wait for switch to open
    digitalWrite(LED_BUILTIN, HIGH);  // switch LED on
    delay(2000);                      // leave LED on for period
  }
  else {
    // switch open with pull-down resistor
    digitalWrite(LED_BUILTIN, LOW);   // switch LED off
  }
}

