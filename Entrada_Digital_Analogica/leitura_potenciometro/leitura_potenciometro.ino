const int pot = A0; // potenciômetro no pino A0

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int leitura = analogRead(pot); // lê o valor do potenciômetro
  Serial.println(leitura);
  
  delay(1); // delay entre leituras - estabilidade
}
