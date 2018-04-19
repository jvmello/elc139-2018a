Disciplina ELC139-2018a - Programação Paralela

Aluno: Filipe Simões

1) Código [aqui](openMP.cpp).

Foi feito um programa onde são abordados os 5 tipos de schedule existentes (static, dynamic, guided, runtime e auto). Os 5 casos são abordados iguais, mudando apenas a tag relativa ao mesmo.
Houveram bugs e não foi possível encontrar a solução correta em todos os tipos de schedule.
Foi imaginado que o erro é devido a sobreposição de threads, o que faz com que as mesmas não executem por tentarem ir para a mesma área crítica e fiquem sempre em espera.

2) Saída do programa

<img src = "https://i.imgur.com/2kz94mV.png" width="480">

3) Referências
  Tutorial [OpenMP](https://computing.llnl.gov/tutorials/openMP/)
