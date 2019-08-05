# PushButton

O pushbutton é um componente que conecta dois pontos em um circuito quando pressionado. Por exemplo, podemos ligar com LED ao pressionar o botão e desligar ao pressioná-lo novamente.

## Componentes
- Arduino
- Pushbutton
- Resistor 10k ohm

## Circuito
![](https://www.arduino.cc/en/uploads/Tutorial/button.png)

## Esquemático
![](https://www.arduino.cc/en/uploads/Tutorial/button_sch.png)

### Resistores <b>Pull-up</b> e <b>Pull-down</b>
![](https://www.embarcados.com.br/wp-content/uploads/2013/12/Entradas-e-Sa%C3%ADdas-digitais-Arduino-pull-up-pull-down.jpg)

O resistor pull-up ou pull-down é basicamente um resistor que fica ligado ao sinal que se deseja ler. Ele serve para garantir que determinado sinal, ou uma entrada de tensão, seja lida enquando o pino não recebe nenhum sinal.
Os Pull-Ups/Pull-Down são utilizados para evitar flutuação em pinos configurados como entradas(INPUT). Em geral, é necessário implementar externamente, mas muitas vezes há Pull-Ups implementados internamente em alguns pinos do microcontrolador. No caso dos microcontroladores Atmegas, já existem Pull-Ups internos em todos os pinos digitais e analógicos (OBS: Só use Pull-Up nos pinos analógicos caso utilizar estes como digitais), portanto não há necessidade de implementar Pull-Up externamente.

#### Pull-up

Garante que o sinal lido seja de nível alto (5V) enquanto o botão ou a chave nãao forem pressionados.

#### Pull-down

O resistor de pull-down garante que o sinal lid seja de nível baixo (GND) enquando o botão ou a chave não forem pressionados.

##### Arduino

O Arduino possui uma forma de ativar as resistências pull-up que existem dentro dele. Não possui pull-down.
```
pinMode(pino,  INPUT_PULLUP);
```

## Módulo Push Button

![](https://startingelectronics.org/tutorials/arduino/modules/push-button/geekcreit-push-button-module.jpg)

#### Esquemático 

![](https://startingelectronics.org/tutorials/arduino/modules/push-button/geekcreit-push-button-circuit.png)

![](https://startingelectronics.org/pinout/push-button/geekcreit-push-button-module-pinout.jpg)

## Links Úteis
[Arduino](https://www.arduino.cc/en/Tutorial/Debounce)

https://startingelectronics.org/tutorials/arduino/modules/push-button/
