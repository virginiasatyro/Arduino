/***********************************************************************************
 * File: knockSensor
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Agosto de 2019
 * 
 * Teste do sensor de batide. Batida detectada ativa o LED. 
 * Pino - -> 10k -> GND (pino 2) resistor de pull-down
 * pino S - +5V
***********************************************************************************/


const int knockPin = 2;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);      // on-board LED, usually pin 13
  pinMode(knockPin, INPUT);          // knock sensor pin set to input

}

void loop() {
  
  if (digitalRead(knockPin)) {       // knock detected?
    // knock detected with pull-down resistor
    digitalWrite(LED_BUILTIN, HIGH);  // switch LED on
    delay(2000);                      // leave LED on for period
  }
  else {
    // knock not detected with pull-down resistor
    digitalWrite(LED_BUILTIN, LOW);   // switch LED off
  }
}

