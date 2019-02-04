/* Objetivo: receber CAN, verificar ID e gravar apenas as IDS escolhidas no cartão.
 *  Testado 04/02  
 */
#include <mcp_can.h>
#include <SPI.h>
#include <SdFat.h>
#include <string.h>

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];                        // Array to store serial string

#define CAN0_INT 2                              // Set INT to pin 2
MCP_CAN CAN0(10);                               // Set CS to pin 10

SdFat sdCard; // SD variables
SdFile file;
const int ss = 9; // select slave
int record_flag = 0;

int count = 0;

void setup()
{
  Serial.begin(115200);
  // SD --------------------------------------------------------------------------------------
  // initializing SD module
  if(!sdCard.begin(ss, SPI_FULL_SPEED))sdCard.initErrorHalt(); 
  
  // CAN -------------------------------------------------------------------------------------
  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK)
    Serial.println("MCP2515 Initialized Successfully!");
  else
    Serial.println("Error Initializing MCP2515...");
  
  CAN0.setMode(MCP_NORMAL);                     // Set operation mode to normal so the MCP2515 sends acks to received data.

  pinMode(CAN0_INT, INPUT);                            // Configuring pin for /INT input
  
  Serial.println("MCP2515 Library Receive Example...");
}

void loop()
{    
    if(!file.open("file_recorded_CAN8.txt", O_RDWR | O_CREAT | O_AT_END)){ // abre arquivo
      sdCard.errorHalt("Error opening file!");
    }
    
    if(!digitalRead(CAN0_INT))                         // If CAN0_INT pin is low, read receive buffer
    {
      CAN0.readMsgBuf(&rxId, &len, rxBuf);      // Read data: len = data length, buf = data byte(s)
      
      if((rxId & 0x80000000) == 0x80000000){     // Determine if ID is standard (11 bits) or extended (29 bits)
        sprintf(msgString, "Extended ID: 0x%.8lX  DLC: %1d  Data:", (rxId & 0x1FFFFFFF), len);
      }else{
        sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId, len);

        switch(rxId){
          case 0x150: 
            file.print(msgString);
            break;
          case 0x250: 
            file.print(msgString);
            break;
          case 0x350: 
            file.print(msgString);
            break;
          case 0x450: 
            file.print(msgString);
            break;
          case 0x550: 
            file.print(msgString);
            break;
        }
      }
      Serial.print(msgString);
    
      if((rxId & 0x40000000) == 0x40000000){    // Determine if message is a remote request frame.
        sprintf(msgString, " REMOTE REQUEST FRAME");
        Serial.print(msgString);
          switch(rxId){
          case 0x150: 
            file.print(msgString);
            break;
          case 0x250: 
            file.print(msgString);
            break;
          case 0x350: 
            file.print(msgString);
            break;
          case 0x450: 
            file.print(msgString);
            break;
          case 0x550: 
            file.print(msgString);
            break;
        }
      } else {
        for(byte i = 0; i<len; i++){
          sprintf(msgString, " 0x%.2X", rxBuf[i]);
          Serial.print(msgString);
          switch(rxId){
          case 0x150: 
            file.print(msgString);
            break;
          case 0x250: 
            file.print(msgString);
            break;
          case 0x350: 
            file.print(msgString);
            break;
          case 0x450: 
            file.print(msgString);
            break;
          case 0x550: 
            file.print(msgString);
            break;
        }
        }
      } 
      Serial.println();
      file.println("");
    }
    file.close();
}
