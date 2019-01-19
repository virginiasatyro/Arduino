/***********************************************************************************
 * File: teste_rgb
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Janeiro de 2019
 * 
 * Ativar cores do LED RGB uma de cada vez de acordo com a escolha no monitor serial.
***********************************************************************************/

// pinos do LED
const int azul = 9;
const int verde = 10;
const int vermelho = 11;

String cor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // pinos do LED declarados como saída
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
}

//Funções responsáveis por executar o brilho selecionado
void cor_vermelha(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, HIGH);
}

void cor_azul(){
  digitalWrite(azul, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, LOW);
}

void cor_verde(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, LOW);
}
void cor_amarela(){
  analogWrite(azul, 0);
  analogWrite(verde, 50);
  analogWrite(vermelho, 255);
}

void cor_roxa(){
  analogWrite(azul, 207);
  analogWrite(verde, 0);
  analogWrite(vermelho, 255);
}

void cor_branca(){
  digitalWrite(azul, HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, HIGH);
}

void cor_ciano(){
  digitalWrite(azul, HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    cor = Serial.readString();
    Serial.println(cor);
  }
  
  if(cor == "vermelha") cor_vermelha();
  if(cor == "azul")     cor_azul();
  if(cor == "verde")    cor_verde();
  if(cor == "amarela")  cor_amarela();
  if(cor == "roxa")     cor_roxa();
  if(cor == "branca")   cor_branca();
  if(cor == "ciano")    cor_ciano();
}
