[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > Trabalhos

Nome: João Vitor Machado de Mello

# T3: Programação Paralela Multithread

## Questões Pthreads

1. 
- Particionamento: O particionamento é feito de uma maneira onde cada thread possui um vetor próprio para trabalhar, diminuindo o trabalho total do processo.
- Comunicação: As threads não dependem exatamente de si para apresentarem resultado, mas possuem um semáforo para controlar quem - está manipulando os dados naquele momento como uma maneira de prevenção de conflitos.
- Aglomeração: Os dados vão sendo salvos em novo vetor à medida que uma thread faz seu cálculo, mas apenas depois de ela "bloquear" o acesso de outras threads aos dados.
- Mapeamento: 

2. Considerando o tempo (em segundos) mostrado na saída do programa, qual foi a aceleração com o uso de threads?

3. A aceleração (speedup) se sustenta para outros tamanhos de vetores, números de threads e repetições? Para responder a essa questão, você terá que realizar diversas execuções, variando o tamanho do problema (tamanho dos vetores e número de repetições) e o número de threads (1, 2, 4, 8..., dependendo do número de núcleos). Cada caso deve ser executado várias vezes, para depois calcular-se um tempo de processamento médio para cada caso. Atenção aos fatores que podem interferir na confiabilidade da medição: uso compartilhado do computador, tempos muito pequenos, etc.

4. Elabore um gráfico/tabela de aceleração a partir dos dados obtidos no exercício anterior.

5. Explique as diferenças entre [pthreads_dotprod.c](pthreads_dotprod/pthreads_dotprod.c) e [pthreads_dotprod2.c](pthreads_dotprod/pthreads_dotprod2.c). Com as linhas removidas, o programa está correto?

## Open MP



