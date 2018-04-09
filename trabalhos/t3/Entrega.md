[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > Trabalhos

Nome: João Vitor Machado de Mello

# T3: Programação Paralela Multithread

## Questões Pthreads

1. Particionamento: O particionamento é feito de uma maneira onde cada thread possui um vetor próprio para trabalhar, diminuindo o trabalho total do processo;<br>
  Comunicação: As threads não dependem exatamente de si para apresentarem resultado, mas possuem um semáforo para controlar quem - está manipulando os dados naquele momento como uma maneira de prevenção de conflitos;<br>
  Aglomeração: Os dados vão sendo salvos em novo vetor à medida que uma thread faz seu cálculo, mas apenas depois de ela "bloquear" o acesso de outras threads aos dados;<br>
  Mapeamento: Os processos vão sendo criados de forma dinâmica de acordo com a disponibilidade do processador.<br>

2. No exemplo do arquivo "readme", em volta de três segundos.

3. Sim, mas em vetores pequenos(+/- até mil posições), duas threads são o suficiente, não havendo uma grande diferença no tempo de execução em tentativas com mais threads.

4. Para um vetor de MIL(1000) elementos:<br>

| Núm. Repetições | Núm. Threads | Tempo Médio(usec) |
|:---------------:|:------------:|:-----------------:|
| 1000000         | 1            | 4425149,3         |
| 500000          | 2            | 2938732,4         |
| 250000          | 4            | 3500102,6         |
| 125000          | 8            | 3787474,5         |
| 62500           | 16           | 6590990,8         |

   <br>Para um vetor de DOIS MIL(2000) elementos:<br>
   
| Núm. Repetições | Núm. Threads | Tempo Médio(usec) |
|:---------------:|:------------:|:-----------------:|
| 1000000         | 1            | 11518515,9        |
| 500000          | 2            | 8339331,5         |
| 250000          | 4            | 7184871,6         |
| 125000          | 8            | 5784597,6         |
| 62500           | 16           | 6590990,8         |

   <br>Para um vetor de CINCO MIL(5000) elementos:<br>
   
| Núm. Repetições | Núm. Threads |  Tempo Médio(usec) |
|:---------------:|:------------:|:------------------:|
| 1000000         | 1            | 28547986,1         |
| 500000          | 2            | 19009499,9         |
| 250000          | 4            | 20452339,1         |
| 125000          | 8            | 19842037,4         |
| 62500           | 16           | 19673411           |

5. Não, pois, com a remoção do semáforo, as threads podem manipular os mesmos dados ao mesmo tempo, o que mudaria resultado ao final da execução.

## Open MP



