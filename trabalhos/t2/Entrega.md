[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > Trabalhos

Nome: João Vitor Machado de Mello

# T2: Experiências com Profilers


## Parte 1

Respostas:
  - (a) Não, pois em todos os testes efetuados os valores das porcentagens de tempo utilizado por cada função foram sempre muito parecidos. Isso pode ser visto em algumas screenshots tiradas para mostrar o profiling de diferentes configurações, em anexo após as duas respostas.
  - (b) Sim, a função "dot_product". Como pode ser visto nas screenshots abaixo, ela costuma tomar 90% do tempo de execução do programa, o que, com métodos de paralelização, poderia dar uma melhora significativa no desempenho geral da execução.

Figura 1: Relatório de perfil(tamanho dos vetores = 30.000.000, repetições = 90)
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/sc5.jpg" width="500">

Figura 2: Relatório de perfil(tamanho dos vetores = 300, repetições = 10)
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/sc6.jpg" width="500">

Figuras 3 e 4:Relatórios de perfil(tamanho dos vetores = 3.000.000, repetições = 25)
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/sc8.jpg" width="500">
<img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/sc9.jpg" width="500">

Figura 5: Relatório de perfil(tamanho dos vetores = 1.000.000, repetições = 25)
<div style="text-align=center"><img src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t2/screenshots/sc10.jpg" width="500"></div>



## Parte 2


+ Escolha um programa que você tenha desenvolvido, ou que seja desenvolvido por outros mas que você conheça o código. 
Pode ser um programa em qualquer linguagem, de preferência estruturado em vários subprogramas (procedimentos, funções, métodos...), e que possa ter a entrada variada facilmente.

+ Escolha 2 profilers para a linguagem alvo e procure repetir os passos da Parte 1, adequando-os a possíveis diferenças.

+ Observe e faça anotações sobre: 
   - (a) particularidades de instalação, recursos ou funcionamento dos profilers, 
   - (b) resultados obtidos e 
   - (c) dúvidas e/ou dificuldades encontradas.

