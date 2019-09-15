/***********************************************************************************
 * File: transmInfravermelho
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Setembro de 2019
 * 
 * Teste do modulo emissor de infravermelho. 
***********************************************************************************/

#include <IRremote.h>
IRsend irsend;
// pino 3 - no arduino UNO 

void setup(){
 Serial.begin(9600);
}

void loop(){
   for (int i = 0; i < 50; i++) { 
     irsend.sendSony(0xa90, 12); // Sony TV power code
     delay(40);
   }
}
