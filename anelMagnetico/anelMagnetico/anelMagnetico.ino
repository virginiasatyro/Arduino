 /***********************************************************************************
 * File: anelMagnetico
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Setembro de 2019
 * 
 * Teste do modulo sensor de anel magnetico. 
 * Ao detectar o campo magnetico e um ímã próximo, o LED imbutido no Arduino apaga. 
 * S    --- pino de sinal 10
 * Meio --- VCC
 * GND  --- -
***********************************************************************************/

const int LED          = 13 ;// Declaration of the LED output pin.
const int magneticRing = 10; //Declaration of the sensor input pin
int val; // Temporary variable

void setup (){
pinMode (LED, OUTPUT) ;         // Initialization output pin
pinMode (magneticRing, INPUT) ; // Initialization sensor pin
}

 
void loop (){

  val = digitalRead(magneticRing) ; // The current signal at the sensor will be read

  if (val == HIGH){ // If a signal will be detected, the LED will light up.
   digitalWrite (LED, HIGH);
  }else{
   digitalWrite (LED, LOW);
  }
}
