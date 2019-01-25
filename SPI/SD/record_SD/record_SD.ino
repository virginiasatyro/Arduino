/***********************************************************************************
 * File: record_SD
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Janeiro de 2019
 * 
 * O objetivo desse projeto é fazer o primeiro teste do cartão SD, ou seja, abrir
 * um arquivo, gravar uma string e fechar.
***********************************************************************************/
#include<SdFat.h>

SdFat sdCard;
SdFile file;

const int ss = 10;   // select-slave
int      record_flag = 0; // if flag is 0 - file not recorded

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // initializing SD module
  if(!sdCard.begin(ss, SPI_FULL_SPEED))sdCard.initErrorHalt(); 
  if(!file.open("file_recorded2.txt", O_RDWR | O_CREAT | O_AT_END)){
    sdCard.errorHalt("Error opening file!");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(record_flag == 0){
    Serial.println("Recording file, please wait...");
    for(int i = 0; i < 100; i++){
      file.print(i);
      file.println(" 1, 2, 3 testando...");
      delay(1);
     }

    Serial.println("File recorded, you can remove SD card now!");
    file.close(); // close the file
    record_flag = 1; // file recorded, avoid recording again the same information 
  }
}
