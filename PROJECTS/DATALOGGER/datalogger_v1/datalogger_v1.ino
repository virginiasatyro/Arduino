/*  File: datalogger_v1
 *  Arduino UNO
 *  Arduino IDE
 *  Author: Virgínia Sátyro
 *  License: Free - Open Source
 *  Created on Fevereiro de 2019
 *   
 *  Objetivo: Datalogger Tesla UFMG 2019
 */

#include <mcp_can.h>
#include <SPI.h>
#include <SdFat.h>
#include <string.h>

long unsigned int rxId;  // ID recieved 
unsigned char len = 0;
byte rxBuf[8];
char msgString[128];     // array to store serial string
unsigned int vetRxInteiros[8];

#define CAN0_INT 2 // set INT to pin 2
MCP_CAN CAN0(10);  // set CS to pin 10

// SD variables
SdFat sdCard; 
SdFile file;
#define ss 9 // select slave

int current_proof; // prova
long unsigned int rxId_aux;

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

        // ID current_proof
        if(rxId == 0x310){
          current_proof = data_word[0];
        }
         
        /* ENDURO
         * ECU timer | velocidade | torque médio | volante | freio | energia inversor direito |  
         * energia inversor esquerdo | corrente motor direito | corrente motor esquerdo | 
         * temp 1 inversor direito | temp 2 inversor esquerdo | corrente media bateria | tensao total |
         * temperatura media | temperatura maxima | menor tensao bateria 
         */
         /*
        if(current_proof == 1){ 
          
        }*/
        // FIM - ENDURO 
        /*  ACELERACAO
         *  veldd | velde | veltd | velte | torque motor direito | torque motor esquerdo | torque pedal direito | torque pedal esquerdo 
         */
        else if(current_proof == 2){ 
            if(rxId == 0x301){
                vetRxInteiros[1] = data_word[0]; // confirmar informações e IDS referentes ao motor esquerdo e ao direito
                vetRxInteiros[0] = data_word[1];
                vetRxInteiros[3] = data_word[2];
                vetRxInteiros[2] = data_word[3];
            } 
            if(rxId == 0x302){
                vetRxInteiros[4] = data_word[0];
                vetRxInteiros[5] = data_word[1];
            }
            if(rxId == 0x303){
                vetRxInteiros[6] = data_word[2]; // confirmar o que é esquerda e direita
                vetRxInteiros[7] = data_word[3];
            }
        }       
        // FIM - ACELERACAO
        /* SKID
         * veldd | velde | veltd | velte | torque motor direito | torque motor esquerdo | volante
         */
        else if(current_proof == 3){ // skid
            if(rxId == 0x301){
              vetRxInteiros[1] = data_word[0]; // confirmar informações e IDS referentes ao motor esquerdo e ao direito
              vetRxInteiros[0] = data_word[1];
              vetRxInteiros[3] = data_word[2];
              vetRxInteiros[2] = data_word[3];
            } 
            if(rxId == 0x302){
              vetRxInteiros[4] = data_word[0];
              vetRxInteiros[5] = data_word[1];
            }
            if(rxId == 0x304){ // NAO ENTRA AQUI??
              Serial.println("Entrou rxId = 0x304!!!"); 
              vetRxInteiros[6] = 1; // ----->>>> nao funciona
              vetRxInteiros[7] = 0;
            }
            
        }
        // FIM - SKID
        
     }
     //Fim - interrupção ------------------------------------------------------------------------
     
     sprintf(msgString, "%d, %u, %u, %u, %u, %u, %u, %u, %u\n", current_proof, vetRxInteiros[0], vetRxInteiros[1], vetRxInteiros[2], vetRxInteiros[3], vetRxInteiros[4], vetRxInteiros[5], vetRxInteiros[6], vetRxInteiros[7]);
     Serial.print(msgString);                         

     // SD - Open SD file -----------------------------------------------------------------------
     if(!file.open("recorded_datalog_v11.txt", O_RDWR | O_CREAT | O_AT_END)){ // abre arquivo
         sdCard.errorHalt("Error opening file!");
     }

     // SD - file record
     file.print(msgString);  
     file.println();
        
     file.close();
      // SD - file close -------------------------------------------------------------------------
}
