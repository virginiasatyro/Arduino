/***********************************************************************************
 * File: servo0to180
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Julho de 2019
 *
 * O servo inicializa na posiçao 0 e gira ate a posiçao 180. Depois faz o caminho 
 * de volta. 
 * Vermelho -> 5V    Marrom: GND    Amarelo: pino de controle
***********************************************************************************/

#include <Servo.h> 

const int pinServo = 6; // PWM pin 

Servo microServo; // object servo
int angle;        // position of the servo

void setup(){
  microServo.attach(pinServo); // attach digital pin to the object
  microServo.write(0);         // initiate in position 0 
}

void loop(){
  for(angle = 0; angle <= 180; angle++){
    microServo.write(angle);
    delay(15);
  }
  
  //delay(500);
  
  for(angle = 180; angle >= 0; angle--){
    microServo.write(angle);
    delay(15);
  }
}
