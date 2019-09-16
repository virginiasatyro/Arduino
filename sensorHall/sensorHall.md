# Sensor de Efeito Hall 

### Efeito Hall 

O efeito Hall está relacionado ao surgimento de uma diferença de potencial em um condutor elétrico, transversal ao fluxo de corrente e um campo magnético perpendicular à corrente. O efeito Hall está relacionado ao surgimento de uma diferença de potencial em um condutor elétrico, transversal ao fluxo de corrente e um campo magnético perpendicular à corrente. 
Em 1879, durante experiências feitas para se medir diretamente o sinal dos portadores de carga em um condutor Edwin H. Hall percebeu um fenômeno peculiar.
Na época já se sabia que quando o fio percorrido por corrente elétrica era exposto a um campo magnético as cargas presentes neste condutor eram submetidos a uma força que fazia com que seu movimento fosse alterado.
No entanto, o que Edwin Hall descreveu foi o surgimento de regiões com carga negativa e outras com carga positiva no condutor, criando um campo magnético perpendicular ao campo gerado pela corrente principal.
Em sua homenagem este efeito ficou conhecido como Efeito Hall.

Sensores de efeito Hall são utilizados em diversos contextos, como medidores de rotação (rodas de bicicleta, dentes de engrenagens, indicador de velocidade para automóveis, sistemas de ignição eletrônica), sensores de fluxo de fluidos, sensores de corrente e pressão. Os sensores Hall também são aplicados quando são necessários potenciômetros ou interruptores robustos e interruptores sem contato. Dentre essas aplicações temos gatilhos de armas de paintball eletropneumático, smartphones e alguns sistemas de posicionamento global. Os sensores de efeito Hall também encontraram aplicações industriais, onde são utilizados joysticks de Efeito Hall para controlar válvulas hidráulicas, substituindo a tradicional alavanca mecânica. Tais aplicações incluem: Mineração de caminhões, Retroescavadeiras, Guindastes, etc. 

## Módulo Sensor Magnético de Efeito Hall - KY-003

![](http://www.electronics-lab.com/wp-content/uploads/2018/04/hall-effect.jpg)

O sensor de Efeito Hall varia sua saída de acordo com a presença de um campo magnético nas redendezas. Quando a densidade de fluxo magnético excede uma determinada quantidade, o sensor detecta e indica em sua saída. 

### Especificações

Consiste em um 3144EUA-S sensível a efeito Hall, um resistor de 680ohm e um LED - acende na presença do campo magnético. 

- Tensão de Operação: 4.5V a 24V 
- Temperatura de Operação: -40°C to 85°C [-x°F to x°F]
- Dimensão: 18.5mm x 15mm [0.728in x 0.591in]

### Pinagem

- Sinal: S
- Meio: VCC
- GND: -

### Circuito 

![](https://arduinomodules.info/wp-content/uploads/Arduino_KY-003_Keyes_Hall_hagnetic_sensor_module_bb-1024x533.png)

## Sensor Magnético Linear de Efeito Hall - KY-024

![](https://arduinomodules.info/wp-content/uploads/KY-024_linear_magnetic_hall_sensor_module_arduino-240x240.jpg)

Esse sensor reage a presença de um campo magnético. Há um potenciômetro imbutido para ajustar a sensibilidade do sensor e saídas analógicas e digitais. A saída digital funciona como uma chave ligado/desligado quando um campo está próximo, assim como o KY-003. A saída analógica é capaz de mediz polaridade e força relativa do campo magnético. 

### Especificações

Consiste em um 49E - sensor linear de efeito Hall, um LM393 - comparador diferencial duplo (?), um potenciômetro, dois LEDs e seix resistores. 

- Tensão de Operação: 2.7V a 6.5V
- Sensibilidade: 1.0 mV/G min., 1.4 mV/G typ., 1.75 mV/G max.
- Dimensões: 1.5cm x 3.6cm [0.6in x 1.4in]

### Pinagem

- Pino de saída analógica: A0
- GND: G
- VCC: +
- Pino de saída digital: D0

### Circuito
![](https://arduinomodules.info/wp-content/uploads/Arduino_KY-024_Keyes_Linear_Magnetic_Hall_module_connection_diagram-1024x668.png)


### Fonte

https://pt.wikipedia.org/wiki/Efeito_Hall
https://arduinomodules.info/ky-003-hall-magnetic-sensor-module/
https://arduinomodules.info/ky-024-linear-magnetic-hall-module/
