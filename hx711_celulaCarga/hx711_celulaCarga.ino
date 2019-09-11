/************************************************************************************
 * File: hx711_celulaCarga
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Setembro de 2019

Montagem:
  fios brancos das células - E+
  fios pretos das células - E- 
  Fio vermelho - A-
  Fio vermelho - A+
  
Exemplo baseado no datasheet do HX711
  HX711 --------------------------------
  SCK - 6
  DT  - 7
  Conversor de 24 bits + amplificador 
  Controla até 4 células de carga
************************************************************************************/

// --- Mapeamento de Hardware ---
#define  ADDO  7    //Data Out
#define  ADSK  6    //SCK

// --- Protótipo das Funções Auxiliares ---
unsigned long ReadCount(); //conversão AD do HX711

unsigned long convert;

void setup(){
   pinMode(ADDO, INPUT_PULLUP);   //entrada para receber os dados
   pinMode(ADSK, OUTPUT);         //saída para SCK
   
   Serial.begin(9600);

} //end setup


void loop(){
  
  convert = ReadCount();
  Serial.println(convert);
  delay(2000);

} 

// --- Funções ---
unsigned long ReadCount(){
  unsigned long Count = 0;
  unsigned char i;
  
  digitalWrite(ADSK, LOW);
  
  while(digitalRead(ADDO));
  
  for(i = 0;i < 24;i++){
     digitalWrite(ADSK, HIGH);
     Count = Count << 1;
     digitalWrite(ADSK, LOW);
     if(digitalRead(ADDO)) Count++;
  
  } //end for
  
  digitalWrite(ADSK, HIGH);
  Count = Count^0x800000;
  digitalWrite(ADSK, LOW);
  
  return(Count);
} //end ReadCount
