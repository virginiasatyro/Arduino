/*  File: record_CAN_STM_SD_ID_3
 *  Arduino UNO
 *  Arduino IDE
 *  Author: Virgínia Sátyro
 *  License: Free - Open Source
 *  Created on Fevereiro de 2019
 *   
 *  Objetivo: otimizar o código de gravação no módulo SD;
 *  Simular o recebimento das variáveis reais do BMS e ECU
 */
int prova;

#include <mcp_can.h>
#include <SPI.h>
#include <SdFat.h>
#include <string.h>

long unsigned int rxId;  // ID recieved 
unsigned char len = 0;
//unsigned byte rxBuf[8];
byte rxBuf[8];
char msgString[128];     // array to store serial string
bool CAN_flag = 0;
unsigned int vetRxInteiros[8];

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
  // SD Initialize ------------------------------------------------------------------------
  // initializing SD module
  if(!sdCard.begin(ss, SPI_FULL_SPEED))sdCard.initErrorHalt(); 
  
  // CAN Initialize -----------------------------------------------------------------------
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
        CAN0.readMsgBuf(&rxId, &len, rxBuf); // Read data: len = data length, buf = data byte(s)
        
        unsigned int* data_word = (unsigned int*)rxBuf;

        // ACELERACAO
        if(rxId == 0x310){
          prova = data_word[0];
        }

        if(prova == 1){ // enduro
          
        }
        if(prova == 2){ // aceleração
            if(rxId == 0x301){
              vetRxInteiros[0] = data_word[0];
              vetRxInteiros[1] = data_word[1];
              vetRxInteiros[2] = data_word[2];
              vetRxInteiros[3] = data_word[3];
            }
            else if(rxId == 0x302){
              vetRxInteiros[4] = data_word[4];
              vetRxInteiros[5] = data_word[5];
              vetRxInteiros[6] = data_word[6];
              vetRxInteiros[7] = data_word[7];
          }
        }
        if(prova == 3){ // skid
         if(rxId == 0x301){
            vetRxInteiros[0] = data_word[0];
            vetRxInteiros[1] = data_word[1];
            vetRxInteiros[2] = data_word[2];
            vetRxInteiros[3] = data_word[3];
        }
        else if(rxId == 0x302){
            vetRxInteiros[4] = data_word[4];
            vetRxInteiros[5] = data_word[5];
            vetRxInteiros[6] = data_word[6];
            vetRxInteiros[7] = data_word[7];
        }
        }
        
        
        // FIM - ACELERACAO
        
     }
     //Fim - interrupção ------------------------------------------------------------------------
         sprintf(msgString, "%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\n", vetRxInteiros[0], vetRxInteiros[1], vetRxInteiros[2], vetRxInteiros[3], vetRxInteiros[4], vetRxInteiros[5], vetRxInteiros[6], vetRxInteiros[7]);
         Serial.print(msgString);                         

     // SD - Open SD file -----------------------------------------------------------------------
         if(!file.open("recorded_CAN14.txt", O_RDWR | O_CREAT | O_AT_END)){ // abre arquivo
             sdCard.errorHalt("Error opening file!");
         }

          // SD - file record
          file.print(msgString);  
          file.println();
        
          file.close();
          CAN_flag = 0;
      // SD - file close -------------------------------------------------------------------------
}
