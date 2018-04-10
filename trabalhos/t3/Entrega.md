[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > Trabalhos

Nome: João Vitor Machado de Mello

# T3: Programação Paralela Multithread

## Questões Pthreads

1. Particionamento: O particionamento é feito de uma maneira onde cada thread possui um vetor próprio para trabalhar, diminuindo o trabalho total do processo;<br>
<p align="center">
  <img width="563" height="154" src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t3/screenshots/particionamento.png"><br>Figura 1: Representação em código da seção de particionamento.
</p>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Comunicação: As threads não dependem exatamente de si para apresentarem resultado, mas possuem um semáforo para controlar quem  está manipulando os dados naquele momento como uma maneira de prevenção de conflitos;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Aglomeração: Os dados vão sendo salvos em novo vetor à medida que uma thread faz seu cálculo, mas apenas depois de ela "bloquear" o acesso de outras threads aos dados;<br>
  <p align="center">
  <img width="359" height="180" src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t3/screenshots/comunicacao_aglomeracao.png"><br>Figura 2: Representação em código das seções comunicação/aglomeração.
</p>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Mapeamento: Os processos vão sendo criados de forma dinâmica de acordo com a disponibilidade do processador e o número de threads possível.<br>
  <p align="center">
  <img width="626" height="366" src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t3/screenshots/mapeamento.png"><br>Figura 3: Representação em código da seção de mapeamento.
</p>

2. No exemplo do arquivo [README.md](https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t3/README.md), em volta de três segundos.
<p align="center">
  <img width="725" height="97" src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t3/screenshots/sc1.png">
  <img width="730" height="95" src="https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t3/screenshots/sc2.png"><br>
Figuras 4 e 5: Execução do código de acordo com as instruções do documento README.md.
</p>

3. Sim, mas em vetores pequenos(+/- até mil posições), duas threads são o suficiente, não havendo uma grande diferença no tempo de execução em tentativas com mais threads.

4. Para um vetor de MIL(1000) elementos:<br>

| Núm. Repetições | Núm. Threads | Tempo Médio(usec) |
|:---------------:|:------------:|:-----------------:|
| 1.000.000         | 1            | 4.425.149,3         |
| 500.000          | 2            | 2.938.732,4         |
| 250.000          | 4            | 3.500.102,6         |
| 125.000          | 8            | 3.787.474,5         |
| 62.500           | 16           | 6.590.990,8         |

   <br>Para um vetor de DOIS MIL(2000) elementos:<br>
   
| Núm. Repetições | Núm. Threads | Tempo Médio(usec) |
|:---------------:|:------------:|:-----------------:|
| 1.000.000         | 1            | 11.518.515,9        |
| 500.000          | 2            | 8.339.331,5         |
| 250.000          | 4            | 7.184.871,6         |
| 125.000          | 8            | 5.784.597,6         |
| 62.500           | 16           | 6.590.990,8         |

   <br>Para um vetor de CINCO MIL(5000) elementos:<br>
   
| Núm. Repetições | Núm. Threads |  Tempo Médio(usec) |
|:---------------:|:------------:|:------------------:|
| 1.000.000         | 1            | 28.547.986,1         |
| 500.000          | 2            | 19.009.499,9         |
| 250.000          | 4            | 20.452.339,1         |
| 125.000          | 8            | 19.842.037,4         |
| 62.500           | 16           | 19.673.411           |

<br> Tabelas 1, 2, e 3: Resultados baseando-se nos dados representados e em um tempo médio armazenado após DEZ(10) execuções realizadas.<br>

5. Não, pois, com a remoção do semáforo, as threads podem manipular os mesmos dados ao mesmo tempo, o que mudaria resultado ao final da execução.

## Open MP
1. [Programa](https://github.com/jvmello/elc139-2018a/blob/master/trabalhos/t3/openmp/newomp.c)

2. Para um vetor de MIL(1000) elementos:<br>

| Núm. Repetições | Núm. Threads | Tempo Médio(usec) |
|:---------------:|:------------:|:-----------------:|
| 1.000.000         | 1            | 5.474.294           |
| 500.000          | 2            | 2.815.437,6         |
| 250.000          | 4            | 2.814.686,9         |
| 12.5000          | 8            | 2.765.119           |
| 62.500           | 16           | 2.658.835,3         |

   <br>Para um vetor de DOIS MIL(2000) elementos:<br>
   
| Núm. Repetições | Núm. Threads | Tempo Médio(usec) |
|:---------------:|:------------:|:-----------------:|
| 1.000.000         | 1            | 10.763.214,2        |
| 500.000          | 2            | 9.537.260,6         |
| 250.000          | 4            | 8.062.672,5         |
| 125.000          | 8            | 10.062.858,9        |
| 62.500           | 16           | 7.168.232,7         |

   <br>Para um vetor de CINCO MIL(5000) elementos:<br>
   
| Núm. Repetições | Núm. Threads |  Tempo Médio(usec) |
|:---------------:|:------------:|:------------------:|
| 1.000.000         | 1            | 24.833.317,5         |
| 500.000          | 2            | 19.721.949,3         |
| 250.000          | 4            | 23.431.662,3         |
| 125.000          | 8            | 28.834.331           |
| 62.500           | 16           | 25.231.439,5         |

<br> Tabelas 4, 5, e 6: Resultados baseando-se nos dados representados e em um tempo médio armazenado após DEZ(10) execuções realizadas.<br>

