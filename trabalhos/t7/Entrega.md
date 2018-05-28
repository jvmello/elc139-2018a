[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > Trabalhos

Nome: João Vitor Machado de Mello

# T7: Primeiros passos com MPI

## Parte 1:
- [Resposta](respostas/mpi_dotprod.c)
- Resultados:<br><br>
Para MIL(1000) repetições:<br>

| Tam. Vetor | Núm. Processos | Tempo Médio(usec) |
|:---------------:|:------------:|:-----------------:|
| 1.000.000         | 1            | 5.747.735,5         |
| 500.000          | 2            | 3.917.942,2        |
| 250.000          | 4            | 3.293.994,3         |

   <br>Para DUAS MIL(2000) repetições:<br>
   
| Tam. Vetor | Núm. Processos | Tempo Médio(usec) |
|:---------------:|:------------:|:-----------------:|
| 1.000.000         | 1            | 12.418.026,7        |
| 500.000          | 2            | 7.706.020,8         |
| 250.000          | 4            | 8.367.825,1         |

   <br>Para CINCO MIL(5000) repetições:<br>
   
| Tam. Vetor | Núm. Processos |  Tempo Médio(usec) |
|:---------------:|:------------:|:------------------:|
| 1.000.000         | 1            | 33.868.759,2         |
| 500.000          | 2            | 17.905.881,9         |
| 250.000          | 4            | 19.697.282,6         |

## Parte 2:
- [Resposta](respostas/mpi_pipeline.c)

## Parte 3:
- [Resposta 1](respostas/mpi_corrigido1.c)
- [Resposta 2](respostas/mpi_corrigido2.c)

## Referências:
- [MPI Send and Receive](http://mpitutorial.com/tutorials/mpi-send-and-receive/)
- [MPI Reduce and Allreduce](http://mpitutorial.com/tutorials/mpi-reduce-and-allreduce/)
- [Message Passing Interface (MPI)](https://computing.llnl.gov/tutorials/mpi/)
- [First examples in MPI](http://hamilton.nuigalway.ie/teaching/AOS/NINE/mpi-first-examples.html)
- [MPI - C Examples](http://people.sc.fsu.edu/~jburkardt/c_src/mpi/mpi.html)
