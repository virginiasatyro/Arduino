# Sound Sensor - KY-038

![](https://4.bp.blogspot.com/-nIA8CLAD3JU/Var5tgYsiCI/AAAAAAAAD-s/57AIu1muwfY/s1600/Sensor-de-som-KY-038.png)
![](https://3.bp.blogspot.com/-tWhOleixewE/Var5xDOMteI/AAAAAAAAD-0/cO2Dpud4mJM/s1600/Sensor-de-som-KY-038-detalhe.png)

O objetivo deste sensor é medir a intensidade sonora do ambiente ao seu redor, variando o estado de sua saída digital caso detectado um sinal sonoro. Possui um microfone de condensador elétrico e pode ser usado em sistemas de alarme por exemplo.
O limite de detecção pode ser ajustado através do potenciômetro presente no sensor que regulará a saída digital D0. Contudo para ter uma resolução melhor é possível utilizar a saída analógica A0 e conectar a um conversor AD, como a presente no Arduino por exemplo.

O sensor de som KY-038 com microfone é uma versão mais atualizada do módulo, agora com o chip LM393. O princípio de funcionamento é simples: ao detectar som, o microfone varia a tensão na saída analógica A0, e também aciona a saída digital D0 conforme a regulagem do potenciômetro presente no módulo.

## Especificações

- Marca: KEYES
- Modelo: KY-038
- Comparador LM393
- Tensão de Operação: 4 - 6 V DC
- Sensibilidade ajustável via potenciômetro
- Saída Digital e Analógica
- Fácil instalação
- Led indicador para tensão
- Led indicador para saída digital

## Pinagem

- AO:  Saída Analógica
- GND: Terra
- VCC: Tensão de Entrada 3-24v
- DO:  Saída Digital

## Esquemático 

![](http://arduinolearning.com/wp-content/uploads/2018/07/KY_038_Microphone_sound_sensor_module.png)
