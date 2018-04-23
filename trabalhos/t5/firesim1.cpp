//  
// Simulação de incêndio em uma floresta.
// Baseada no código proposto por David Joiner.
//
// Uso: firesim <tamanho-do-problema> <nro. experimentos> <probab. maxima> 

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <sys/time.h>
#include "Random.h"
#include "Forest.h"
#include <omp.h>

void
checkCommandLine(int argc, char** argv, int& size, int& trials, int& probs, int& threads)
{
   if (argc > 1) {
      size = atoi(argv[1]);
   }   
   if (argc > 2) {
      trials = atoi(argv[2]);
   }
   if (argc > 3) {
      probs = atoi(argv[3]);
   }
   if (argc > 4) {
      threads = atoi(argv[4]);
   }    
}

int 
main(int argc, char* argv[]) 
{
   
   // parâmetros dos experimentos
   int forest_size = 30;
   int n_trials = 5000;
   int n_probs = 101;
   int n_threads = 2;

   double* percent_burned; // percentuais queimados (saída)
   double* prob_spread;    // probabilidades (entrada)
   double prob_min = 0.0;
   double prob_max = 1.0;
   double prob_step;
   int base_seed = 100;
   clock_t ini, fim;

   checkCommandLine(argc, argv, forest_size, n_trials, n_probs, n_threads);
    
   omp_set_num_threads(n_threads);

   try {
		
      ini = clock();
      Random rand;
      
      int ip, it;

      prob_spread = new double[n_probs];
      percent_burned = new double[n_probs];

      prob_step = (prob_max - prob_min)/(double)(n_probs-1);

      printf("Probabilidade, Percentual Queimado\n");

      // para cada probabilidade, calcula o percentual de árvores queimadas
      //Opção 1: paralelizar calculo de percentual
      #pragma omp parallel private(ip, it)
      {
         Forest* forest = new Forest(forest_size);
	 #pragma omp for schedule(dynamic)
	 for (ip = 0; ip < n_probs; ip++) {
	    prob_spread[ip] = prob_min + (double) ip * prob_step;
	    percent_burned[ip] = 0.0;
	    rand.setSeed(base_seed+ip); // nova seqüência de números aleatórios
	    // executa vários experimentos
	    for (it = 0; it < n_trials; it++) {
	       // queima floresta até o fogo apagar
	       forest->burnUntilOut(forest->centralTree(), prob_spread[ip], rand);
	       percent_burned[ip] += forest->getPercentBurned();
	    }
	
	    // calcula média dos percentuais de árvores queimadas
	         percent_burned[ip] /= n_trials;
	
	    // mostra resultado para esta probabilidade
	    printf("Thread %d: %lf, %lf\n", omp_get_thread_num()+1, prob_spread[ip], percent_burned[ip]);
	  }
      }

      delete[] prob_spread;
      delete[] percent_burned;
      fim = clock();
      printf("Tempo de execucao = %lf segundos\n", (double)(fim-ini)/CLOCKS_PER_SEC);
   }
   catch (std::bad_alloc)
   {
      std::cerr << "Erro: alocacao de memoria" << std::endl;
      return 1;
   }

   return 0;
}

