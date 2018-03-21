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
&nbsp;&nbsp;&nbsp;&nbsp;Como profilers, foram escolhidos o VisualVM e o YourKit. Serão testados arquivos de tamanhos variados para a geração de schedules e visualização de perfil pelos programas escolhidos e citados.<br></p>

## Parte 1

+ Respostas:
  - (a) Não, pois em todos os testes efetuados os valores das porcentagens de tempo utilizado por cada função foram sempre muito parecidos. Isso pode ser visto em algumas screenshots tiradas para mostrar o profiling de diferentes configurações, em anexo após as duas respostas.
  - (b) Sim, a função "dot_product". Como pode ser visto nas screenshots abaixo, ela costuma tomar 90% do tempo de execução do programa, o que, com métodos de paralelização, poderia dar uma melhora significativa no desempenho geral da execução.

Figura 1: Relatório de perfil(tamanho dos vetores = 30.000.000, repetições = 90)
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/Gprof/sc1.png" width="500">

Figura 2: Relatório de perfil(tamanho dos vetores = 300, repetições = 10)
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/Gprof/sc2.png" width="500">

Figuras 3 e 4: Relatórios de perfil(tamanho dos vetores = 3.000.000, repetições = 25)
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/Gprof/sc3.png" width="500">
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/Gprof/sc4.png" width="500">

Figura 5: Relatório de perfil(tamanho dos vetores = 1.000.000, repetições = 25)
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/Gprof/sc5.png" width="500">



## Parte 2

+ VisualVM:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;O VisualVM é um profiler específico para Java que tem como objetivo verificar problemas de desempenho e ajudar o desenvolvedor a encontrar soluções para problemas de execução baseando-se em relatórios de uso de threads, CPU e memória durante a execução do determinado aplicativo.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;O sistema é de fácil instalação e possui um executável, sendo necessária apenas a extração de seus arquivos. Todos os aplicativos java sendo executados no sistema são mostrados na barra lateral, como mostrado na figura 6. É só clicar numa delas e obter informações do processo escolhido.<br>
   
Figura 6: Tela inicial do VisualVM
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/VisualVM/sc6.png" width="500">
   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Os resultados surpreenderam(pelo menos a mim). O processo de abertura e conversão do arquivo de texto exigia mais CPU/memória e "despertava" mais threads que o processo de conversão de instruções para schedule.
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Um fator que possa ter contribuído para esse resultado pode ser o excesso de repetições e funções mais internas durante a conversão, o que acaba por exigir mais do computador enquanto executa. Nesse caso, essas funções poderiam se beneficiar por paralelismo.
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Os resultados podem ser vistos nas screenshots abaixo.

Figuras 7 a 12.
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/VisualVM/sc7.png" width="500">
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/VisualVM/sc8.png" width="500">
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/VisualVM/sc9.png" width="500">
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/VisualVM/sc10.png" width="500">
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/VisualVM/sc11.png" width="500">
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/VisualVM/sc12.png" width="500">

+ YourKit:<br>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Por problemas de instalação com o Java Mission Control(inicialmente planejado para ser utilizado neste trabalho), a ferramenta YourKit foi escolhida.<br>
&nbsp;&nbsp;&nbsp;&nbsp;O YourKit é um profiler Java muito parecido em objetivos com o VisualVM. Ambos buscam traçar um perfil em desempenho de execução do aplicativo. Entretanto, o YourKit parece ser mais "técnico", fornecendo até prováveis problemas de deadlocks em suas análises. Outro ponto diferencial é a visualização de dados ser mais "lenta", possibilitando ao seu usuário a visualização de dados de maneira mais eficiente.<br>

Figura 13: Tela inicial do YourKit
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/YourKit/sc13.png" width="500">

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Os resultados foram bem parecidos com os do VisualVM. Porções maiores de CPU/memória e um número maior de threads executando ao ler o arquivo do que à conversão "final" em si.<br>

Figuras
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/YourKit/sc14.png" width="500">
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/YourKit/sc15.png" width="500">
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/YourKit/sc16.png" width="500">
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/YourKit/sc17.png" width="500">
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/YourKit/sc18.png" width="500">
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/YourKit/sc19.png" width="500">

## Referências
- Stackify. List of Java Profilers: 3 Different Types and Why You Need All of Them. https://stackify.com/java-profilers-3-types/;
- VisualVM. VisualVM: All-in-One Java Troubleshooting Tool. https://visualvm.github.io/;
- VisualVM. Introduction to Java VisualVM. https://www.youtube.com/watch?v=z8n7Bg7-A4I;
- Oracle. Oracle Java Mission Control. http://download.oracle.com/technology/products/missioncontrol/updatesites/base/5.5.0/eclipse/;
- Java(vídeo por James Weaver). Java Mission Control Demo. https://www.youtube.com/watch?v=qytuEgVmhsI;
- YourKit. The Industry Leader in .NET & Java Profiling. https://www.yourkit.com/;
- Karsten Thoms. Tackling Performance Issues with YourKit. https://www.youtube.com/watch?v=q6NlxDesFPg.

