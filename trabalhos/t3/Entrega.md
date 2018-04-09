[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > Trabalhos

Nome: João Vitor Machado de Mello

# T3: Programação Paralela Multithread

## Questões Pthreads

1. Particionamento: O particionamento é feito de uma maneira onde cada thread possui um vetor próprio para trabalhar, diminuindo o trabalho total do processo;
  Comunicação: As threads não dependem exatamente de si para apresentarem resultado, mas possuem um semáforo para controlar quem - está manipulando os dados naquele momento como uma maneira de prevenção de conflitos;
  Aglomeração: Os dados vão sendo salvos em novo vetor à medida que uma thread faz seu cálculo, mas apenas depois de ela "bloquear" o acesso de outras threads aos dados;
  Mapeamento: Os processos vão sendo criados de forma dinâmica de acordo com a disponibilidade do processador.

2. No exemplo do arquivo "readme", em volta de três segundos.

3. Sim, mas em vetores pequenos(+/- até mil posições), duas threads são o suficiente, não havendo uma grande diferença no tempo de execução em tentativas com mais threads.

4. (fazer tabela).

5. Não, pois, com a remoção do semáforo, as threads podem trabalhar com os mesmos dados, mudando o resultado final da execução.

## Open MP



