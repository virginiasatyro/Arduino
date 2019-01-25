#include <mcp_can.h>
#include <SPI.h>
#include <SdFat.h>
#include <string.h> 

SdFat  sdCard; // SD variables
SdFile file;

const int ss = 10; // SD - select slave
bool      record_flag = 0; // 0 - file not beeing recorded

long unsigned int rxId;
unsigned char len = 8;
unsigned char flag_frame;
unsigned char rxBuf[8];
char          msgString[128];      // Array to store serial string

#define CAN0_INT 3     // Set INT to pin 2
MCP_CAN CAN0(9);      // Set CS to pin 10


void setup() 
{
  Serial.begin(115200);
  // SD ------------------------------------------------------------------------------------------
  // initializing SD module
  if(!sdCard.begin(ss, SPI_FULL_SPEED))sdCard.initErrorHalt(); 
  if(!file.open("file_recorded_CAN2.txt", O_RDWR | O_CREAT | O_AT_END)){
    sdCard.errorHalt("Error opening file!");
  }

  // CAN -----------------------------------------------------------------------------------------
  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK)
    Serial.println("MCP2515 Initialized Successfully!");
  else
    Serial.println("Error Initializing MCP2515...");

  CAN0.setMode(MCP_NORMAL);                     // Set operation mode to normal so the MCP2515 sends acks to received data.

  pinMode(CAN0_INT, INPUT);                            // Configuring pin for /INT input

  Serial.println("MCP2515 Library Receive Example...");
}

int i=0;
char msg[17];
int dado;
int count = 0;

void loop()
{
  if(!digitalRead(CAN0_INT))                         // If CAN0_INT pin is low, read receive buffer
  {
    dado=0;
    CAN0.readMsgBuf(&rxId, &flag_frame, &len, rxBuf);      // Read data: len = data length, buf = data byte(s)
    sprintf(msgString, "ID: 0x%X  \t  \t Data: ", rxId);
    Serial.println(msgString);
    file.println("Recebendo dados...");
    delay(50);
    //file.print(msgString);
    //delay(50);
    sprintf(msgString, "\tWord1: %u \tWord2: %u \tWord3: %u \tWord4: %u", *((int*)(rxBuf)), *((int*)(rxBuf+2)), *((int*)(rxBuf+4)), *((int*)(rxBuf+6)));
    Serial.print(msgString);
   // file.println(msgString);
    //delay(50);
    Serial.println();
  }

  count = count + 1;
  if(count == 100){
    Serial.println("File recorded, you can remove SD card now!");
    file.close();    // close the file
  }
  /*if(record_flag == 0){
    Serial.println("Recording file, please wait...");
    for(int j = 0; j < 100; j++){
      file.print(j);
      file.println(" 1, 2, 3, testando ...");
      delay(10);
    }
    
    Serial.println("File recorded, you can remove SD card now!");
    file.close();    // close the file
    record_flag = 1; // file recorded, avoid recording again the same information 
  }*/
}






/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
