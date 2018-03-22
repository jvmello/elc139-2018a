Filipe Simões de Mendonça

ELC139 - Programação Paralela

Foi usado o Windows 10 em um computador Intel Core i7-4510U com 2 CPU.

## Sumário

Parte 1: Gprof

Parte 2a: Inter V-Tune

Parte 2b: Sleepy

## Parte 1 - Gprof:

Execução com 30 milhões como tamanho do vetor e 10 repetições:
    
<img src="http://i.imgur.com/8H1s7x6.png" width="480">
    
Execução com 40 milhões como tamanho do vetor e 20 repetições:
    
<img src="http://i.imgur.com/oYKIf0z.png" width="480">
        
Resposta 1) O perfil é afetado com diferentes perfis? Sim, pois com diferentes tamanhos de vetor, porém com mudanças pouco significativas por mais que o tamanho do vetor aumente em 10 milhões. A maior diferença se dá na % de tempo entre cada função. No primeiro teste, o tempo foi dividido quase que igualmente entre as funções de cálculo e de inicialização do vetor (53% x 44%, aproximado). Já no segundo teste, o tempo da função de cálculo foi muito maior comparado a inicialização do vetor (83% x 14%). Com isso, é possível responder que:

Resposta 2) Pelo perfil de execução, há alguma função que poderia ser candidata a paralelização? Por quê? Sim, a função dot_product, por ser a função propriamente do cálculo, que se torna mais pesada quanto mais elementos e repetições tiver no programa, é a principal candidata a paralelização no código, visando assim diminuir o tempo levado pelo cálculo, que tem um aumento maior que o tempo de iniciação do vetor.

    Obs: O código usado na parte 2 é o algoritmo do ArrayMáximo, com vetor de tamanho 1024 e 1 bilhão de repetições (Para ser possível um tempo significante pros profilers)

## Parte 2 - Intel VTune

Resposta 1) Particularidades de instalação, recursos ou funcionamento dos profiler: O profiler é instalável normalmente via .exe. O profiler é pago e fornece uma versão de 30D grátis. O profiler oferece a opção de escolher o intervalo de testes do programa, pegando amostras dele. O funcionamento é dado executando um .exe existente.

Resposta 2) Resultados obtidos
<img src = "https://i.imgur.com/GcuCvzn.png" width="480">
O programa mostra o número de threads usadas (0 em caso de não ter uso de threads) e quanto tempo pausou em cada thread. Também mostra qual das funções do programa que teve maior tempo de CPU
<img src = "https://i.imgur.com/qbRiVfI.png" width="480">
Também é mostrado o tempo médio de uso EFETIVO da CPU em um histograma que mede o quão bem feito é o uso da CPU.

Resposta 3) Dúvidas e/ou dificuldades encontradas: Não houveram dúvidas ou dificuldades, a ferramenta foi facilmente instalada e executada, com poucas configurações pra serem feitas.

## Parte 2 - Sleepy

Resposta 1) Particularidades de instalação, recursos ou funcionamento dos profiler: O profiler é instalável normalmente via .exe. O profiler é grátis e funciona para códigos .c e .cpp. O profiler lista todos os recursos em execução no computador para mostrar o quanto de CPU os mesmos consomem. Funciona semelhante ao "Gerenciador de Tarefas do Windows". O funcionamento é dado lendo um .exe e dado um diretório para resultados.

Resposta 2) Resultados obtidos
<img src = "https://i.imgur.com/F58L9sM.png" width="480">
O profiler demonstra poucas informações, as principais sendo o tempo exclusivo, tempo total executado, % de uso exclusivo da CPU, % de uso total da CPU e os módulos usados. Para executar o código do ArrayMaximo foi feito um loop infinito já que o profiler precisava ser inicializado ao mesmo tempo que o executável. A execução foi parada com 9.51s

Resposta 3) Dúvidas e/ou dificuldades encontradas: O profiler tem interface confusa, e é pouco intuitivo, para 'profilar' um programa é necessário dar cliques repetidos no executável do console. 

## Referências

+ Intel VTune https://software.intel.com/en-us/intel-vtune-amplifier-xe
+ Sleepy http://www.codersnotes.com/sleepy/
