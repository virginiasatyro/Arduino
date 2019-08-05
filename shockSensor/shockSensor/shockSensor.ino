/***********************************************************************************
 * File: shockSensor
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Agosto de 2019
 * 
 * Teste do modulo "shock sensor".
***********************************************************************************/


const int shockPin = 2;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);       // on-board LED, usually pin 13
  pinMode(shockPin, INPUT);          // shock sensor pin set to input
}

void loop() {
  if (digitalRead(shockPin)) {       // shock detected?
    // shock detected with pull-down resistor
    digitalWrite(LED_BUILTIN, HIGH);  // switch LED on
    delay(2000);                      // leave LED on for period
  }
  else {
    // shock not detected with pull-down resistor
    digitalWrite(LED_BUILTIN, LOW);   // switch LED off
  }
}

