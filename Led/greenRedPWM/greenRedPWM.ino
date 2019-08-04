/***********************************************************************************
 * File: GreenRedPWM
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Agosto de 2019
 * 
 * Teste do modulo led de catodo comum verde e vermelho. 
 * Muda o brilho de verde para vermelho e assim sucessivamente.
 * Muda a intensidade do brilho com PWM.
***********************************************************************************/

const int redLed   = 6;
const int greenLed = 5;

const int stepTime = 10;
int pwmValue = 0;

void setup(){
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop(){
  // red dim to bright 
  for (pwmValue = 0; pwmValue <= 255; pwmValue++) {
    analogWrite(redLed, pwmValue);
    delay(stepTime);
  }
  
  // red bright to dim
  for (pwmValue = 255; pwmValue >= 0; pwmValue--) {
    analogWrite(redLed, pwmValue);
    delay(stepTime);
  }
  
  // green dim to bright
  for (pwmValue = 0; pwmValue <= 255; pwmValue++) {
    analogWrite(greenLed, pwmValue);
    delay(stepTime);
  }
  
  // green bright to dim
  for (pwmValue = 255; pwmValue >= 0; pwmValue--) {
    analogWrite(greenLed, pwmValue);
    delay(stepTime);
  }
}
