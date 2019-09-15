/***********************************************************************************
 * File: sensorHall
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Setembro de 2019
 * 
 * Teste do sensor de efeito Hall. Ao detectar um campo magnético, o sensor acende o 
 * LED imbutido no módulo e o imbutido no Arduino. 
 * GND  --- -
 * Meio --- VCC
 * S    --- sinal
***********************************************************************************/
const int hallSensor = 2;   // pin sensor
const int LED        = 13;  // LED built0in
  
int state      = 0;   
       
void setup() {
  pinMode(LED, OUTPUT);      
  pinMode(hallSensor, INPUT);     
}

void loop(){
  
  state = digitalRead(hallSensor);
  if (state == LOW) { // normally closed       
    digitalWrite(LED, HIGH);  
  } 
  else {
    digitalWrite(LED, LOW); 
  }
}
