/***********************************************************************************
 * File: chaveMercurio
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Setembro de 2019
 * 
 * Esse programa testa o módulo sensor de inclinação com Mercúrio - Ky-017. 
 * Dependendo da inclinação o LED inbutido no módulo acende e o LED imbutido no Arduino
 * apaga e vice versa. 
 * Sinal --- S
 * Meio  --- 5V 
 * GND   --- -
***********************************************************************************/
const int led_pin = 13;   // Define the LED interface
const int switch_pin = 3; // Definition of mercury tilt switch sensor interface
int val;                  // Defines a numeric variable

void setup(){
  pinMode(led_pin, OUTPUT);
  pinMode(switch_pin, INPUT);
}

void loop()
{
  val = digitalRead(switch_pin); // check mercury switch state
  if(val == HIGH){
    digitalWrite(led_pin, HIGH);
  }
  else{
    digitalWrite(led_pin, LOW);
  }
}
