# Micro Servo 9g

![](http://blogmasterwalkershop.com.br/wp-content/uploads/2018/06/img00_como_usar_com_arduino_micro_servo_motor_sg90_9g_robo_mercatronica_carrinho_uno_mega_leonardo_nano.png) 

Ao utilizar o Micro Servo Motor SG90 9g é possível controlar o giro e a posição do mesmo através dos comandos enviados pela plataforma microcontrolada. Após o envio do comando para que o servo altere sua posição, o mesmo verifica sua posição atual e em seguida executa o comando girando até a posição indicada.

Servomotores consomem uma corrente significativa ao se movimentarem. A utilização de uma fonte externa pode ser necessária e é recomendada. Lembre-se de conectar o pino GND da fonte externa ao GND do Arduino para que a referência seja a mesma.

Apesar de sua posição ser controlada através do duty cycle de um sinal PWM enviado ao pino de controle não é necessária a conexão do pino de controle a um pino que possua PWM, pois utilizaremos a biblioteca Servo.h.
A utilização de analogWrite produzirá um controle de menor precisão e poderá até danificar alguns servomotores por sua frequência (490 Hz) ser 10 vezes superior a frequência típica de controle de alguns servomotores.



## Especificações e Características

- Modelo: SG90
- Marca do servo: Tower Pro
- Tensão de operação: 3,0 a 6,0 V
- Posição (máxima): 180° de giro
- Material das engrenagens: nylon
- Temperatura de trabalho: -30ºC ~ 60ºC
- Torque: 1,2 Kg/cm (4,8 V) / 1,6 Kg/cm (6,0 V)
- Velocidade: 0,12 seg/60Graus (4,8v) sem carga
- Dimensões.: 32x30x12 mm
- Tamanho cabo: 245 mm
- Peso: 9g

## Conexão 

- Vermelho - 5,0 V
- Amarelo/laranja - pino de controle
- Marrom/preto - GND

## Biblioteca

### Servo.h 
