# Células de Carga + HX711

![](http://blog.baudaeletronica.com.br/wp-content/uploads/2018/08/Carga-768x231.jpg)

Este sensor de carga pode ser usado individualmente ou em conjunto, use por exemplo 2 sensores para montar uma balança para medir até 100Kg, ou 4 sensores para montar uma balança para medir 200Kg.

O sensor de carga e peso 50Kg deve ser utilizado em conjunto com um módulo amplificador de sinal como o Módulo Conversor HX711 para Sensor de Peso.

### Funcionamento da Célula de Carga

Células de carga possuem extensômetros (![*strain gauges*](https://github.com/virginiasatyro/Arduino/blob/master/strainGauge/strainGauge.md)) que se deformam de acordo com a carga aplicada sobre sua área de contato. Essa deformação faz com que sua resistência aumente. Entretanto existem alguns fatores que podem influenciar na variação ôhmica do extensômetro, como pode ser visto abaixo. 

![](https://www.robocore.net/upload/tutoriais/246_img_2_M.png?995)

### Ponte de Wheatstone

A ponte de Wheatstone é o método mais utilizado para realizar medições sobre a variação da célula de carga. Com ela é possível identificar valores de resistência ôhmica desconhecida. Ela é utilizada para determinar resistências muito pequenas, podendo ser utilizada para medir uma escala de mili-ohms. O circuito da ponte nada mais é do que duas disposições série-paralelo de dois resistores, preferencialmente de mesmo valor. Com o valor igualado em todos os resistores da ponte, a diferença de potencial no centro da ponte quando medido entre as disposições de resistores deve ser igual a zero. 

![](https://www.robocore.net/upload/tutoriais/246_img_3_M.png?465)

**Vout = Vc - Vd = [ R2 / ( R1 + R2 ) ] * Vin - [ R4 / ( R3 + R4 ) ] * Vin**

**R1 / R2 = R3 / R4**

### Amplificador Operacional

O módulo HX711 utilizado neste tutorial é um conversor analógico-digital e amplificador operacional de 24 bits. Ele é usado para amplificar o sinal da célula de carga de 50 kg, além de realizar a conversão do sinal analógico para um sinal digital. Isso é necessário, pois o sinal de saída da célula está na escala de milivolts (mV). Portanto para que seja um sinal que possa ser lido pelo microcontrolador, ele precisa ser amplificado para o nível adequado da placa utilizada.

#### Pinagem do módulo HX711
- E+ : pino de alimentação da célula (+);
- E- : pino de alimentação da célula (-);
- A+ : sinal da célula de carga;
- A- : sinal da célula de carga;
- VCC: alimentação (+);
- GND: alimentação (-);
- DT : conectada ao pino digital do Arduino;
- SCK: conectadad ao pino digital do Arduino;

### Especificações da Célula

- Sensor de peso
- Capacidade máxima: 50Kg
- Conexão: 3 fios
- Dimensões: 34 x 34 x 7mm

## Fontes 

https://www.robocore.net/tutoriais/celula-de-carga-hx711-com-arduino
http://blog.baudaeletronica.com.br/conversor-hx711-para-balanca-eletronica/
