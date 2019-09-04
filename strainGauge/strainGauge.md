# Strain Gauge 

### Introdução

O nome extensômetro significa medidor de deformação. O nome extensômetro de resistência elétrica significa medidor de deformação (mecânica) relativa através da variação da resistência elétrica. Assim, dispositivos que efetuam esta correlação são chamados de extensômetros de resistência elétrica ou <i>strain gauges</i>. 
A utilização mais extensa e conhecida para os <i>strain gauges</i> é na construção de células de carga, tipicamente utilizadas na construção de baçanças eletrônicas. A célula de carga construída a partir de <i>strain gauges</i> gera um sinal elétrico proporcional ao esforço mecânico incidente sobre esta. 

### Extensômetro de Resistência Elétrica 

O nome extensômetro de resistência elétrica significa medidor de deformação (mecânica) relativa através de determinação da variável da resistência elétrica. Em 1856, Kelvin demonstrou que a resistência elétrica de um fio de cobre ou ferro varia quando submetido a uma deformação elástica. Assim, se um fio de comprimento <b>l</b> e resistência <b>R</b> sofre uma deformação elástica igual a <b>delta(l)</b>, a resistência sofre um acréscimo de <b>delta(R)</b>, demonstrando então que a variação relativa da resistência <b>delta(R) / R</b> relaciona-se linearmente com a variação relativa <b>delta(l) / l</b>. 

<b>K = (delta(R)/R) / (delta(l)/l)</b>

onde <b>K</b> é uma constante se a deformação se processa na região elástica do material. 

Um <i>strain gauge</i> comercial é tipicamente constituído das seguintes partes:
- Grade de metal resistivo;
- Substrato de plástico;
- Terminais de contato;

![](https://www.eecis.udel.edu/~portnoi/images/extensometria/Image207.gif)

### Tipos de Extensômetros 
##### Extensômetro axial único 
Utilizado quando se conhece a direção da deformação, que é em um único sentido.

![](https://www.eecis.udel.edu/~portnoi/images/extensometria/Image216.gif)

##### Extensômetro axial múltiplo
Roseta de 2 direções. São dois extensômetros sobre uma mesma base, sensíveis a duas direções. Utilizada para medir deformações principais quando se conhecem as direções

![](https://www.eecis.udel.edu/~portnoi/images/extensometria/Image217.gif)

Roseta de 3 direções. São três extensômetros sobre uma mesma base, sensíveis a três direções. Utilizada quando as direções principais de deformações não são conhecidas 

![](https://www.eecis.udel.edu/~portnoi/images/extensometria/Image218.gif)

##### Extensômetro tipo diafragma 
São quatro extensômetros sobre uma mesma base, sensíveis a deformações em duas posições diferentes. Usado para transdutores de pressão.

![](https://www.eecis.udel.edu/~portnoi/images/extensometria/Image219.gif)

##### Extensômetro para medida de tensão residual
São três extensômetros sobre uma base devidamente posicionados para utilização em método de medida de tensão residual. 

![](https://www.eecis.udel.edu/~portnoi/images/extensometria/Image220.gif)

##### Extensômetro para transduutores de carga 
São dois extensômetros dispostos lado a lado, sobre a mesma base, para utilização em células de cargas (para medição de tensão e compressão). 

![](https://www.eecis.udel.edu/~portnoi/images/extensometria/Image221.gif)

### Materiais Utilizados em *Strain Gauges*
Tipicamente, qualquer metal ou liga onde ocorra uma variação da resistência elétrica em função da deformação. Para selecionar o material da grada consideramos basicamente os seguintes fatores:

- Alta sensibilidade **K**;
-	Alta resistividade **_p_**;
-	Baixa sensibilidade à variação com a temperatura;
-	Alta  tensão de escoamento (maior elasticidade);
-	Fácil manuseio;
-	Boa soldabilidade;
-	Baixa histerese;
-	Baixa fem térmica quando ligada a outros materiais;
-	Boa resistência à corrosão;

### Características 

Os extensômetros elétricos têm as seguintes características gerais, que denotam sua importância e alto uso:

- Alta precisão de medida;
- Baixo custo;
- Excelente linearidade;
- Excelente resposta dinâmica;
- Fácil instalação;
- Pode ser imerso em água ou em atmosfera de gases corrosivos (com tratamento adequado);
- Possibilita realizar medidas à distância.

A base do extensômetro pode ser de: poliamida, epóxi, fibra de vidro reforçada com resina fenólica, baquelita, poliéster, papel e outros. O elemento resistivo pode ser confeccionado de ligas metálicas tais como Constantan, Advance, Nicromo V, Karma, Níquel, Isoelatic e outros.

O extensômetro pode ser confeccionado também com elemento semicondutor, que consiste basicamente de um pequeno e finíssimo filamento de cristal de silício que é geralmente montado em suporte de epóxi ou fenólico.

As características principais dos extensômetros elétricos de semicondutores são sua grande capacidade de variação de resistência em função da deformação e seu alto valor do fator do extensômetro, que é de aproximadamente 150, podendo ser positivo ou negativo. Para os extensômetros metálicos a maior variação de resistência é devida às variações dimensionais, enquanto que nos de semicondutor a variação é mais atribuída ao efeito piezo-resistivo.

Para um extensômetro ideal, o fator de extensômetro deveria ser uma constante, e de maneira geral os extensômetros metálicos possuem o fator de extensômetro que podem ser considerados como tal. Nos extensômetros semicondutores, entretanto, o fator do extensômetro varia com a deformação, numa relação não linear. Isto dificulta quando da interpretação das leituras desses dispositivos. Entretanto é possível se obter circuitos eletrônicos que linearizem esses efeitos. Atualmente, os extensômetros semicondutores são bastante aplicados quando se deseja uma saída em nível mais alto, como em células de cargas, acelerômetros e outros transdutores.

### Ponte de Wheatstone 

Na utilização, os _strain gauges_ devem ser colados em dispositivos robustos que suportam o esforço mecânico, denominado de célula de carga. Quando ocorre a deformação elástica da célula de carga, os _strain gauges_ colados sobre a mesma, também sofrem deformação, variando sua resistência elétrica.

Os _strain gauges_ podem ser considerados como resistências elétricas de valor definido, até o momento em que houver a deformação da chapa de aço. Para geração de um sinal elétrico proporcional a um esforço mecânico, os Strain Gauges devem ser ligados (como resistências) em uma configuração em ponte chamada de Ponte de Wheatstone. O circuito elétrico denominado Ponte de Wheatstone será então um comparador de resistores que serve para medir variações relativas de resistência elétrica. O circuito tipo ponte é único e geral. Dependendo da aplicação ou do uso, costuma-se classificá-lo em: 
- Ponte de comparação (de balanço, ou de nulo);
- Ponte de deflexão (de desbalanço ou de variação);

O tipo de ponte útil é a de deflexão ou desbalanço, entretanto esta deve estar calibrada em balanço (tensão de saída V = 0), num estado considerado inicial. Para que se tenha V = 0 se faz necessário que a razão entre as impedâncias de cada braço da ponte sejam iguais. Para isso os _strain gauges_ são fisicamente colocados de maneira a obter uma ponte em equilíbrio. A ponte de Wheatstone é insensível a variações relativas de resistência num mesmo braço, ou em ambos, desde que estas ocorram no mesmo sentido. Esta propriedade é favorável, e é explorada, no sentido de que variações de resistências decorrentes de mudanças da temperatura nos Strain Gauges não impedirão que a ponte continue balanceada, desde que todos os extensômetros estejam em locais nos quais a temperatura varie de forma similar. Para isso constrói-se a ponte com extensômetros idênticos.

## Fontes 

https://www.eecis.udel.edu/~portnoi/academic/academic-files/extensometria.html
