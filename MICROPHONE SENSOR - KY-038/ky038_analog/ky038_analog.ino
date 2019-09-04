/*  File: ky038_digital_input
 *  Arduino UNO
 *  Arduino IDE
 *  Author: Virgínia Sátyro
 *  License: Free - Open Source
 *  Created on Fevereiro de 2019
 *   
 *  Objetivo: 
 */
 // 400 e 600

#define microphone  A0  // digital input from ky-038
#define blue        9
#define green       10
#define red         11

int microValue = 0;  // input value 

void blue_color(){
  digitalWrite(blue, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
}

void green_color(){
  digitalWrite(blue, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
}

void red_color(){
  digitalWrite(blue, LOW);
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(blue,  OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red,   OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  microValue = analogRead(microphone);
  Serial.println(microValue, DEC);

  if(microValue < 475){
    blue_color();
  }else if(microValue > 475 && microValue < 525){
    green_color();
  }else{
    red_color();
  }
  
}
