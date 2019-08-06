/***********************************************************************************
 * File: ldrLed
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Agosto de 2019
 * 
 * Teste do modulo do foto-resistor (LDR). Com baixa iluminaço, o led do Arduino acende.
***********************************************************************************/

const int ldrPin = A0; // analog pin for the LDR

int threshold = 300; // trigger level
int sensorValue = 0; // ldr value read 

void setup(){
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);  // pin 13 on UNO
}

void loop(){
  sensorValue = analogRead(ldrPin);
  Serial.println(sensorValue);
  
  if(sensorValue < threshold){
    // low light - turn on led 
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(20);
}
