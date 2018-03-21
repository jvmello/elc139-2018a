[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > Trabalhos

Nome: João Vitor Machado de Mello

# T2: Experiências com Profilers

## Sumário

&nbsp;&nbsp;&nbsp;&nbsp;Para este trabalho, o programa escolhido será um "conversor de schedules" para gerenciadores de banco de dados. O trabalho foi desenvolvido para a disciplina de Implementação de Banco de Dados e consistia em converter um arquivo com várias instruções em um schedule(sequência de execução de um banco) funcional.<br>
&nbsp;&nbsp;&nbsp;&nbsp;Várias funções foram desenvolvidas para o funcionamento do programa. As principais envolvem:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Carregamento e leitura de arquivos;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Conversão dos mesmos para uma linguagem que o tradutor entenderia;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Processamento das consultas traduzidas em um schedule completo;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Funções para interface envolvendo botões e caixas de texto para melhor entendimento do que estava acontecendo durante a execução do aplicativo.<br>
&nbsp;&nbsp;&nbsp;&nbsp;Como profilers, foram escolhidos o VisualVM e o Java Mission Control. Serão testados arquivos de tamanhos variados para a geração de schedules e visualização de perfil pelos programas escolhidos e citados.<br></p>

## Parte 1

+ Respostas:
  - (a) Não, pois em todos os testes efetuados os valores das porcentagens de tempo utilizado por cada função foram sempre muito parecidos. Isso pode ser visto em algumas screenshots tiradas para mostrar o profiling de diferentes configurações, em anexo após as duas respostas.
  - (b) Sim, a função "dot_product". Como pode ser visto nas screenshots abaixo, ela costuma tomar 90% do tempo de execução do programa, o que, com métodos de paralelização, poderia dar uma melhora significativa no desempenho geral da execução.

Figura 1: Relatório de perfil(tamanho dos vetores = 30.000.000, repetições = 90)
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/sc5.jpg" width="500">

Figura 2: Relatório de perfil(tamanho dos vetores = 300, repetições = 10)
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/sc6.jpg" width="500">

Figuras 3 e 4: Relatórios de perfil(tamanho dos vetores = 3.000.000, repetições = 25)
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/sc8.jpg" width="500">
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/sc9.jpg" width="500">

Figura 5: Relatório de perfil(tamanho dos vetores = 1.000.000, repetições = 25)
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/sc10.jpg" width="500">



## Parte 2(VisualVM, Java Mission Control)

+ VisualVM:
  - O VisualVM é um profiler específico para Java que tem como objetivo verificar problemas de desempenho e ajudar o desenvolvedor a encontrar soluções para problemas de execução baseando-se em relatórios de uso de threads, CPU e memória durante a execução do determinado aplicativo.
   O sistema é de fácil instalação e possui um executável, sendo necessária apenas a extração de seus arquivos. Todos os aplicativos java sendo executados no sistema são mostrados na barra lateral, como mostrado na figura 6. É só clicar numa delas e obter informações do processo escolhido.
   
Figura 6: Tela inicial do VisualVM
   
   Os resultados surpreenderam(pelo menos a mim). O processo de abertura e conversão do arquivo de texto exigia mais CPU/memória e "despertava" mais threads que o processo de conversão de instruções para schedule.
Um fator que possa ter contribuído para esse resultado pode ser o excesso de repetições e funções mais internas durante a conversão, o que acaba por exigir mais do computador enquanto executa. Nesse caso, essas funções poderiam se beneficiar por paralelismo.
Os resultados podem ser vistos nas screenshots abaixo.

Figuras 7 a 11.

+ Java Mission Control:

## Referências

