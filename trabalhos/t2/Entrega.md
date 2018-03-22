Filipe Simões de Mendonça

ELC139 - Programação Paralela

Sumário

	Parte 1: Gprof

	Parte 2a: Inter V-Tune

	Parte 2b: -

Parte 1 - Gprof:

    Execução com 30 milhões como tamanho do vetor e 10 repetições:
    
<img src="http://i.imgur.com/8H1s7x6.png" width="480">
    
	Execução com 40 milhões como tamanho do vetor e 20 repetições:
    
<img src="http://i.imgur.com/oYKIf0z.png" width="480">
        
    Resposta 1) O perfil é afetado com diferentes perfis? Sim, pois com diferentes tamanhos de vetor, porém com mudanças pouco significativas por mais que o tamanho do vetor aumente em 10 milhões. A maior diferença se dá na % de tempo entre cada função. No primeiro teste, o tempo foi dividido quase que igualmente entre as funções de cálculo e de inicialização do vetor (53% x 44%, aproximado). Já no segundo teste, o tempo da função de cálculo foi muito maior comparado a inicialização do vetor (83% x 14%). Com isso, é possível responder que:
	Resposta 2) Pelo perfil de execução, há alguma função que poderia ser candidata a paralelização? Por quê? Sim, a função dot_product, por ser a função propriamente do cálculo, que se torna mais pesada quanto mais elementos e repetições tiver no programa, é a principal candidata a paralelização no código, visando assim diminuir o tempo levado pelo cálculo, que tem um aumento maior que o tempo de iniciação do vetor.
