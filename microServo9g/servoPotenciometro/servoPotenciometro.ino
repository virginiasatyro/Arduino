
#include <Servo.h>

Servo servo; // servo object 

const int potPin   = A5; // potentiometer - analog pin
const int servoPin = 6;  // PWM pin - servo motor

int aux; 

void setup(){
  servo.attach(servoPin); // attach digital pin to the object 
  servo.write(0);
}

void loop(){
  // read potentiometer
  aux = analogRead(potPin);
  
  // conversion
  aux = map(aux, 0, 1023, 0, 176);
  
  // write on servo
  servo.write(aux);
  
  delay(15);
}
