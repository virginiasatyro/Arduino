/*  File: record_CAN_STM_SD_ID_2
 *  Arduino UNO
 *  Arduino IDE
 *  Author: Virgínia Sátyro
 *  License: Free - Open Source
 *  Created on Fevereiro de 2019
 *   
 *  Objetivo: otimizar o código de gravação no módulo SD;
 *  Evitar gravação dentro da interrupção;
 *  Testado corretamente: 05/02
 *  
 *  Pontos a melhorar: 
 *  - todas as IDS são standard (11 bits);
 *  - a CAN não utiliza remote request frame;
 *  - ou seja, retirar código inutilizado;
 *  - as mensagens sempre tem len = 8, len_aux desnecessário;
 *  - não é necessário utilizar o rxId_aux;
 *  - o switch pode ser colocado dentro da interrupção, guardando 
 *  apenas as variáveis que são necessárias; 
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
int record_flag = 0;

// Variáveis auxiliares para salvar os dados da CAN
long unsigned int rxId_aux;
unsigned char len_aux = 0;
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

     // Determine if ID is standard (11 bits) or extended (29 bits)
     if((rxId & 0x80000000) == 0x80000000){
         //sprintf(msgString, "Extended ID: 0x%.8lX  DLC: %1d  Data:", (rxId & 0x1FFFFFFF), len);
     }else{
         //sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId, len);
     }
     //Serial.print(msgString); 
     rxId_aux = rxId;
     len_aux = len;
         
     ///////////////////////////////////////////////////
     // Determine if message is a remote request frame.
     if((rxId & 0x40000000) == 0x40000000){  
       // sprintf(msgString, " REMOTE REQUEST FRAME");
       // Serial.print(msgString);
     }else{
         for(byte i = 0; i<len; i++){
             // sprintf(msgString, " 0x%.2X", rxBuf[i]);
             rxBuf_aux[i] = rxBuf[i];
             // Serial.print(msgString);
         }
     }       
     // Serial.println();
  }
  //Fim - interrupção ------------------------------------------------------------------------
  
  if(CAN_flag == 1){ // if there is interruption
      sprintf(msgString_aux, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId_aux, len_aux);
      Serial.print(msgString_aux);
      for(byte i = 0; i < len_aux; i++){
          sprintf(msgString_aux_data, " 0x%.2X", rxBuf_aux[i]);
          Serial.print(msgString_aux_data);
      }
      Serial.println();

    // SD - Open SD file --------------------------------------------------------------------
    if(!file.open("recorded_CAN10.txt", O_RDWR | O_CREAT | O_AT_END)){ // abre arquivo
        sdCard.errorHalt("Error opening file!");
    }

    // SD - file record
    switch(rxId_aux){
        case 0x301: // 0x150
            file.print(msgString_aux);  
            for(byte i = 0; i < len_aux; i++){ // tentar otimizar esse for!
                sprintf(msgString_aux_data, " 0x%.2X", rxBuf_aux[i]);
                file.print(msgString_aux_data);
            }
            file.println();
            break;
        case 0x303: // 0x250
            file.print(msgString_aux);
            for(byte i = 0; i < len_aux; i++){ // tentar otimizar esse for!
                sprintf(msgString_aux_data, " 0x%.2X", rxBuf_aux[i]);
                file.print(msgString_aux_data);
            }
            file.println();
            break;
        case 0x350:
            file.print(msgString_aux);
            for(byte i = 0; i < len_aux; i++){ // tentar otimizar esse for!
                sprintf(msgString_aux_data, " 0x%.2X", rxBuf_aux[i]);
                file.print(msgString_aux_data);
            }
            file.println();
            break;
        case 0x450:
            file.print(msgString_aux);
            for(byte i = 0; i < len_aux; i++){ // tentar otimizar esse for!
                sprintf(msgString_aux_data, " 0x%.2X", rxBuf_aux[i]);
                file.print(msgString_aux_data);
            }
            file.println();
            break;
        case 0x550:
            file.print(msgString_aux);
            for(byte i = 0; i < len_aux; i++){ // tentar otimizar esse for!
                sprintf(msgString_aux_data, " 0x%.2X", rxBuf_aux[i]);
                file.print(msgString_aux_data);
            }
            file.println();
            break;
    }
    file.close();
    // SD - file close -------------------------------------------------------------
    CAN_flag = 0; // reset flag
  }  
}
