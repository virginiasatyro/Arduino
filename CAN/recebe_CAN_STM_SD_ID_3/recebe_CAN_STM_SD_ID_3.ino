/*  File: record_CAN_STM_SD_ID_3
 *  Arduino UNO
 *  Arduino IDE
 *  Author: Virgínia Sátyro
 *  License: Free - Open Source
 *  Created on Fevereiro de 2019
 *   
 *  Objetivo: otimizar o código de gravação no módulo SD;
 *  Melhorar a versão 2 
 *  Testado 06/02
 */

#include <mcp_can.h>
#include <SPI.h>
#include <SdFat.h>
#include <string.h>

long unsigned int rxId;  // ID recieved 
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];     // array to store serial string
bool CAN_flag = 0;

#define CAN0_INT 2 // set INT to pin 2
MCP_CAN CAN0(10);  // set CS to pin 10

// SD variables
SdFat sdCard; 
SdFile file;
#define ss 9 // select slave

// Variáveis auxiliares para salvar os dados da CAN
unsigned char rxBuf_aux[8];
char msgString_aux[128];
char msgString_aux_data[128];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // SD -----------------------------------------------------------------------------------
  // initializing SD module
  if(!sdCard.begin(ss, SPI_FULL_SPEED))sdCard.initErrorHalt(); 
  
  // CAN ----------------------------------------------------------------------------------
  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK){
    Serial.println("MCP2515 Initializad Successfully!");
  }else{
    Serial.println("Error Initializing MCP2515...");
  }

  CAN0.setMode(MCP_NORMAL);  // Set operation mode to normal so the MCP2515 sends acks to received data.
  pinMode(CAN0_INT, INPUT);  // Configuring pin for INT input
  Serial.println("MCP2515 Library Receive Example...");
}


void loop() {
    // CAN ----------------------------------------------------------------------------------
    if(!digitalRead(CAN0_INT)){  // If CAN0_INT pin is low, read receive buffer
        CAN_flag = 1;
        CAN0.readMsgBuf(&rxId, &len, rxBuf); // Read data: len = data length, buf = data byte(s)

        if(rxId == 0x150 || rxId == 0x250 || rxId == 0x350 || rxId == 0x450 || rxId == 0x550){
          for(byte i = 0; i < len; i++){
              rxBuf_aux[i] = rxBuf[i];
          }        
        }else{
          CAN_flag = 0;
        }
    }       
    //Fim - interrupção ------------------------------------------------------------------------
  
    if(CAN_flag == 1){ // if there is interruption
      sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId, len);
      Serial.print(msgString);
      for(byte i = 0; i < len; i++){
          sprintf(msgString_aux_data, " 0x%.2X", rxBuf_aux[i]);
          Serial.print(msgString_aux_data);
      }
      Serial.println();

    // SD - Open SD file -----------------------------------------------------------------------
    if(!file.open("recorded_CAN11.txt", O_RDWR | O_CREAT | O_AT_END)){ // abre arquivo
        sdCard.errorHalt("Error opening file!");
    }

    // SD - file record
    file.print(msgString);  
    for(byte i = 0; i < len; i++){
      sprintf(msgString_aux_data, "0x%.2X", rxBuf[i]);
      file.print(msgString_aux_data);
    }
    file.println();
        
    file.close();
    // SD - file close -------------------------------------------------------------------------
    CAN_flag = 0; // reset flag
   }  
}
