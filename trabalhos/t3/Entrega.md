Filipe Simões de Mendonça

ELC139 - Programação Paralela

Foi usado o Windows 10 em um computador Intel Core i7-4510U com 2 CPU.

## Parte 1 - Pthreads

1) Particionamento, Comunicação, Aglomeração e Mapeamento
  
  1.a e d) Particionamento e Mapeamento:
  
  <img src = "https://i.imgur.com/yeON1TA.png" width="480">
  
  O particionamento é feito na criação das threads, pois é onde de fato é dividido para cada thread o total de elementos do vetor. Por isso também é feito o mapeamento na mesma função, onde é feita a divisão estática dos elementos, já que o número de elementos por thread é dado como argumento do programa.
  
  1.b e c) Comunicação e Aglomeração
  
  <img src = "https://i.imgur.com/XsGB4S0.png" width="480">
  
  A comunicação e a aglomeração são feitas no mesmo local, pois as duas threads comunicam-se sobre a região crítica (área do mutex) e aglomeram seus resultados em 'dotdata.c'.
  

2) Nos testes efetuados, com em média 7.1 segundos, sem threads, para em media 4.3 segundos, com 2 threads, houve uma aceleração de aproximadamente 40% do programa, visto que atingiu quase metade do tempo sem thread.

3) Não, pois a aceleração, a medida que o número de elementos no vetor aumenta, a porcentagem de aceleração tende a cair, como pode ser visto na tabela abaixo.

<img src = "https://i.imgur.com/1TNKdCH.png" width="480">

Com o dobro de elementos do teste inicial, foi dada uma queda de 4% da aceleração, deixando a aproximidamente 36%. E dobrando novamente os valores, houve uma queda de 1%, deixando a acelereção em 35%. Então é seguro dizer que a aceleração não se mantém a mesma, porém fica próxima da casa dos 30-40%.

4) 
<img src = "https://i.imgur.com/gPVc26C.png" width="480">


5) A única diferença entre os dois é o controle da área crítica sendo feita no pthreads_dotprod.c, enquanto no pthreads_dotprod2.c a área crítica não possui nenhuma controle. No caso de cálculo do produto interno não se causam erros já que a ordem que a multiplicação e a soma do produto interno é feita não influi em nada no resultado final.

## Parte 2 - OPEN MP

1) Código [aqui](pasta/arquivo)

2) Tabelinha desempenho
<img src = "add link" width="480">
