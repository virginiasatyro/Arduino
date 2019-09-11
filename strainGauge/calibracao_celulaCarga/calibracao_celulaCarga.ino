/*******************************************************************************
*Testedo com:
*VCC - 5V
*SCK - pino 2
*DT - pino 3
*GND - GND 
*
*E+ --- 1k --- A- --- fio branco
*E- --- 1k --- A- --- fio preto
*A+ --- fio vermelho
*
*Muito instável ainda, porém mais eatável que utilizando duas células
*******************************************************************************/

#include <HX711.h>

//configuracao dos pinos para o modulo HX711
const int DT_Pin = 3;
const int SCK_Pin = 2;

const int time_wait = 1000;        //declaracao da variavel de espera
HX711 scale;                       //declaracao do objeto escala na classe HX711 da biblioteca
float calibration_factor = -45000; //pre-definicao da variavel de calibracao
char comand;       
float medida; //declaracao da variavel que ira receber os comandos para alterar o fator de calibracao

void setup (){
  Serial.begin(9600);
  Serial.println("Celula de carga - Calibracao de Peso");

  scale.begin (DT_Pin, SCK_Pin); //inicializacao e definicao dos pinos DT e SCK dentro do objeto ESCALA

  float media_values = scale.read_average(); //realiza uma media entre 10 leituras com a celula sem carga 
  Serial.print("Media de leituras com Celula sem carga: ");
  Serial.print(media_values);
  Serial.println();

  scale.tare(); //zera a escala
}

void loop (){
  scale.set_scale(calibration_factor); //ajusta a escala para o fator de calibracao

  //verifica se o modulo esta pronto para realizar leituras
  if (scale.is_ready()){
    //mensagens de leitura no monitor serial
    Serial.print("Leitura: ");
    Serial.print(scale.get_units(20), 3); //retorna a leitura da variavel escala com a unidade quilogramas
    //medida = scale.get_units();
    Serial.print(medida);
    Serial.print(" kg");
    Serial.print(" \t Fator de Calibracao = ");
    Serial.print(calibration_factor);
    Serial.println();

    //alteracao do fator de calibracao
    if(Serial.available()){
        comand = Serial.read();
        switch (comand){
          case 'x':
          calibration_factor = calibration_factor - 100;
          break;
          case 'c':
          calibration_factor = calibration_factor + 100;
          break;
          case 'v':
          calibration_factor = calibration_factor - 10;
          break;
          case 'b':
          calibration_factor = calibration_factor + 10;
          break;
          case 'n':
          calibration_factor = calibration_factor - 1;
          break;
          case 'm':
          calibration_factor = calibration_factor + 1;
          break;
        }
      }
    }
    else{
      Serial.print("HX-711 ocupado");
    }
  delay(time_wait);
}
