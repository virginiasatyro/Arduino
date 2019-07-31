# Arduino
 Repositório criado com o objetivo reunir implementações básicas referente ao microcontrolador Arduino de forma a criar um ambiente de acesso rápido, fácil e educativo.
 
 Esse README.md tem como objetivo fazer um resumo das principais funções que podem ser usadas, focando em formatação, imagens, GIFs, links, listas, quotes, tasklists e código.
 
 Extensão .md -> arquivo markdown - linguagem de marcação, assim como HTML, serve basicamente para estlizar texto na Web. Algumas tags do HTML também funcionam nesse tipo de arquivo. 

# Markdown 
# h1    
## h2    
### h3    
#### h4    
##### h5    
###### h6  

<h1>HTML</h1>
<h1>h1</h1>
<h2>h2</h2>
<h3>h3</h3>
<h4>h4</h4>
<h5>h5</h5>
<h6>h6</h6>

# Ênfase 
Equivalente ao <b>negrito</b> , <i>itálico</i> e <strike>riscado</strike>

### Markdown
*Itálico*
_Itálico_

**Negrito**
__Negrito__

--Riscado--

**_Negrito e Itálico_**
 
 <h3>HTML</h3>
 
 <i>Itálico</i>
 <em>Itálico</em> 
 <strong>Negrito</strong>
 <b>Negrito</b>
 
 <strike>Riscado</strike>
 
 <b><i>Negrito e Itálico</b></i>
 
# Lista Ordenada
 Equivalete ao 'ol'
 
### Markdown
 1. aaaa
 2. bbbb
 
 1. dddd
 1. eeee
 
<h3>HTML</h3>
 <ol>
  <li>aa</li>
  <li>bb</li>
 </ol>
 
# Lista Não Ordenada 
 Equivalente ao 'ul'
 
### Markdown
 - aaaa
 - bbbb
 - cccc
 - dddd
 
<h3>HTML</h3>
<ul>
 <li>aa</li>
 <li>bb</li>
</ul>
 
# Links
Equivalente ao 'a' 

### Markdown 
[Google](http://google.com/)
[Build](/build/classes)

<h3>HTML</h3>
<a href="http://google.com/">Google</a>
<a href="/build/classes">Build</a> 

# Quotes
Equivalente ao 'blockquote'

### Markdown 
Como diria um antigo mestre:
 > Que a força esteja com você!
 
<h3>HTML</h3>
Como diria um antigo mestre:
 <blockquote>Que a força esteja com você!</blockquote>
 
# Tasklists 

### Markdown 
- [x] Implementar a classe X
- [x] Implementar a classe Y 
- [ ] Testar classes
- [ ] Dominar o mundo 

# Código 

### Markdown 
```
function testando(){
    var x = "ok";
    console.log(x);
}
```

# Tabelas
Em markdown é preciso basicamente desenhar a tabela, porém existe um gerador de tabelas que facilita: [gerador](https://www.tablesgenerator.com/markdown_tables?source=post_page---------------------------)
Em HTML usamos 'table'.

### Markdown 
| Top A | Top B |
|-------|-------|
|AAAAAAA|BBBBBBB|
|CCCCCCC|DDDDDDD|

<h3>HTML</h3>
<table>
 <thead>
  <th>TOP A</th>
  <th<TOP B</th>
 </thead>
 <tbody>
  <tr>
   <td>AAA</td>
   <td>BBB</td>
 </tr>
 <tr>
  <td>CCC</td>
  <td>DDD</td>
 </tr>
 </table>
 
 # Imagens e Gifs
 
 Duas maneiras:
 1. Issue - colocar a imagem como issue - GitHub gera link - copiar esse link - utilizar;
 2. Tendo a imagem que queremos em um diretório do repositório, basta utilizar a sintaxe: ![](caminho até a imagem)
 
 ### Markdown
 ![](https://user-images.githubusercontent.com/16197291/62239261-f05dc480-b3aa-11e9-844c-ef8c58f4e17e.png)
 
 <h3>HTML</h3>
 <img src="https://img.icons8.com/material/24/000000/github.png">
