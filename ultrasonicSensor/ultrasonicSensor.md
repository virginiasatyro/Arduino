# Sensor Ultrassônico HC-SR04

![](https://uploads.filipeflop.com/2017/07/9SS01-2.jpg)

O Sensor Ultrassônico HC-SR04 é um componente muito comum em projetos com Arduino, e permite que você faça leituras de distâncias entre 2 cm e 4 metros, com precisão de 3 mm.

O funcionamento do HC-SR04 [datasheet](https://img.filipeflop.com/files/download/Datasheet_HCSR04.pdf) se baseia no envio de sinais ultrassônicos pelo sensor, que aguarda o retorno (echo) do sinal, e com base no tempo entre envio e retorno, calcula a distância entre o sensor e o objeto detectado. 
Primeiramente é enviado um pulso de 10µs, indicando o início da transmissão de dados. Depois disso, são enviado 8 pulsos de 40 KHz e o sensor então aguarda o retorno (em nível alto/high), para determinar a distância entre o sensor e o objeto, utilizando a equação <b>Distância = (Tempo echo em nível alto * velocidade do som) /2</b>

![](https://uploads.filipeflop.com/2011/07/HC_SR04_Trigger_Echo.jpg)
![](https://uploads.filipeflop.com/2011/07/Diagrama-tempo-hc-sr04.png)


# Fontes 

[Felipeflop](https://www.filipeflop.com/blog/sensor-ultrassonico-hc-sr04-ao-arduino/)
[Biblioteca](https://github.com/filipeflop/Ultrasonic)
