/*  File: datalogger_v1
 *  Arduino UNO
 *  Arduino IDE
 *  Author: Virgínia Sátyro
 *  License: Free - Open Source
 *  Created on Fevereiro de 2019
 *   
 *  Objetivo: Datalogger Tesla UFMG 2019
 *  Problemas: muitos dados na CAN
 *  Interrupção interrompe demais
 *  alguns dados não são gravados
 *  com menos dados funciona melhor
 */

#include <mcp_can.h>
#include <SPI.h>
//#include <SdFat.h>
#include <string.h>

long unsigned int rxId;  // ID recieved 
unsigned char len = 0;
byte rxBuf[8];
char msgString[128];     // array to store serial string
char msgString1[512];
unsigned int vetRxInteiros[8];
unsigned int vetRxInteiros1[18];

#define CAN0_INT 2 // set INT to pin 2
MCP_CAN CAN0(10);  // set CS to pin 10
/*
// SD variables
SdFat sdCard; 
SdFile file;
#define ss 9 // select slave
*/

int current_proof; // prova
long unsigned int rxId_aux;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // SD Initialize ------------------------------------------------------------------------
  // initializing SD module
  //if(!sdCard.begin(ss, SPI_HALF_SPEED))sdCard.initErrorHalt(); 
  
  // CAN Initialize -----------------------------------------------------------------------
  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(CAN0.begin(MCP_ANY, CAN_1000KBPS, MCP_8MHZ) == CAN_OK){
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
        if(current_proof == 1){ 
          if(rxId == 0x307){ // 0x304 não funciona!! dados zerados aqui
            vetRxInteiros1[0] = data_word[3]; // timer
            vetRxInteiros1[1] = data_word[0]; // speed
            vetRxInteiros1[2] = data_word[1]; // torq
            vetRxInteiros1[3] = data_word[2]; // shutt
          }
          if(rxId == 0x303){
            vetRxInteiros1[4] = data_word[3]; // break 
          }
          if(rxId == 0x305){
            vetRxInteiros1[5] = data_word[0]; // energy inv r
            vetRxInteiros1[6] = data_word[1]; // energy inv l 
            vetRxInteiros1[7] = data_word[2]; // current motor r 
            vetRxInteiros1[8] = data_word[3]; // current motor l
          }
          if(rxId == 0x306){
            vetRxInteiros1[9]  = data_word[0]; // temp 1 inv r 
            vetRxInteiros1[10] = data_word[1]; // temp 2 inv r 
            vetRxInteiros1[11] = data_word[2]; // temp 1 inv l 
            vetRxInteiros1[12] = data_word[3]; // temp 2 inv l  
          }
          if(rxId == 0x660){
            vetRxInteiros1[13] = data_word[0]; // media current 
            vetRxInteiros1[14] = data_word[1]; // total voltage 
            vetRxInteiros1[15] = data_word[2]; // temp media 
            vetRxInteiros1[16] = data_word[3]; // temp max 
          }
          if(rxId == 0x670){
            vetRxInteiros1[17] = data_word[0]; // min voltage
          }         
        }
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

     // SD - Open SD file -----------------------------------------------------------------------
     /*if(!file.open("recorded_datalog_v11.txt", O_RDWR | O_CREAT | O_AT_END)){ // abre arquivo
         sdCard.errorHalt("Error opening file!");
     }*/
     
     if(current_proof == 1){ //enduro
        sprintf(msgString1, "%d\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\n", current_proof, vetRxInteiros1[0],vetRxInteiros1[1], vetRxInteiros1[2], vetRxInteiros1[3], vetRxInteiros1[4], vetRxInteiros1[5], vetRxInteiros1[6], vetRxInteiros1[7], vetRxInteiros1[8], vetRxInteiros1[9], vetRxInteiros1[10], vetRxInteiros1[11], vetRxInteiros1[12], vetRxInteiros1[13], vetRxInteiros1[14], vetRxInteiros1[15], vetRxInteiros1[16], vetRxInteiros1[17]);  
        Serial.print(msgString1);
        // SD - file record
        //file.print(msgString1);
        //file.println();  
     }
     if(current_proof == 2 || current_proof == 3){
         sprintf(msgString, "%d, %u, %u, %u, %u, %u, %u, %u, %u\n", current_proof, vetRxInteiros[0], vetRxInteiros[1], vetRxInteiros[2], vetRxInteiros[3], vetRxInteiros[4], vetRxInteiros[5], vetRxInteiros[6], vetRxInteiros[7]);
         Serial.print(msgString);          
         // SD - file record
         //file.print(msgString);  
         //file.println();               
     }

     delay(10);
     //file.close();
     // SD - file close -------------------------------------------------------------------------
}
