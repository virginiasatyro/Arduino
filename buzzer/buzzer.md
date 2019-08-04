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
