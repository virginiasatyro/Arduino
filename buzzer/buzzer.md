# Buzzer

## Módulo Buzzer Ativo KY-012

![](https://startingelectronics.org/tutorials/arduino/modules/active-buzzer/geekcreit-active-buzzer.jpg)

O buzzer ativo tem dispositivos eletrônicos em seu interior responsáveis por produzir o som ou tom. Apenas o volume do som pode ser modificado alterando-se a alimentação. O tom gerado insternamente não pode ser modificado.  

### Pinagem 

![](https://startingelectronics.org/pinout/geekcreit-active-buzzer-module-pinout/geekcreit-active-buzzer-pinout.jpg)

Tipicamento o pino negativo é ligado ao GND, o positivo é ligado ao 5 V e o de meio permanece desconectado. 

### Características 

- Tensão de operação            3.5V ~ 5.5V
- Corrente máxima              	30mA / 5VDC
- Frequência de ressonância   	2500Hz ± 300Hz 
- Som mínimo de saída           85Db @ 10cm
- Temperatuda de operação       -20°C ~ 70°C [-4°F ~ 158°F]
- Temperatura de armazenamento  -30°C ~ 105°C [-22°F ~ 221°F]   
- Dimensão                    	18.5mm x 15mm [0.728in x 0.591in]

### Circuito 

O buzzer necessita aproximadamente 25 mA dos 5 V fornecidos. Sendo assim, o buzzer drena mais corrente do que um pino do Arduino á capaz de fornecer - 20 mA. Não é ideal ligá-lo diretamente ao Arduino. 
A solução é utilizar um transistor para alimentar o buzzer. Alternativamente, a corrente drenada do pino pode ser reduzida através da ligação com um pino de PWM.

![](https://startingelectronics.org/tutorials/arduino/modules/active-buzzer/arduino-active-buzzer-circuit.png)

## Módulo Buzzer Passivo

O módulo é dito passivo porque não tem componentes eletrônicos internos que geram um som ou tom. Circuitos eletrônicos externos ou um dispositivo baseado com microcontrolador é necessário para que o dispositivo emita um som. Por o dispositivo ser passivo, ele pode ser considerado mais um pequeno auto-falante do que um buzzer. Ele pode ser utilizado como um gerador de tom/melodia. 


### Pinagem 

Tipicamente o pino do positivo é conectado a um pino de I/O do Arduino e o pino negativo é ligado ao GND. Opcional: utilizar um resistor de 100 ohm entre o pino e o buzzer. 

![](https://startingelectronics.org/pinout/geekcreit-passive-buzzer-module-pinout/geekcreit-passive-buzzer-pinout.jpg)

### Esquemático

![](https://www.arduino.cc/en/uploads/Tutorial/Tone_Schematic.png)

### Transdutor Piezo Elétrico 

A palavra piezo é de origem grega e significa pressionar, torcer. Piezos são elementos que utilizam o efeito piezoelétrico. Piezoeletricidade é a capacidade de alguns cristais gerarem tensão elétrica por resposta a uma pressão mecânica

![](https://i1.wp.com/portal.vidadesilicio.com.br/wp-content/uploads/2017/05/piezo-buzzer-funcionamento.gif?resize=220%2C220&ssl=1)

Sendo assim, alguns materiais possuem a capacidade de gerar tensão elétrica quando são submetidos a uma força externa. Uma das aplicações dele é como sensores de batida, como em baterias elétricas. Outro lugar comum de encontrá-los, é em isqueiros, que transformam o movimento do ignitor em faísca.
O mais interessante é que o contrario também é verdade. Quando inserimos um diferencial de tensão  no cristal, o cristal transforma energia elétrica em energia mecânica. Dessa forma, o piezo se mexe.
Através desse efeito, podemos alimentar o transdutor com um tensão variável, com o intuito de obter sons.
