#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
#include <time.h>

int main(){
	int cont = 0;
	int numThread, tid;
	int chunk = 20;
	omp_set_num_threads(3);
	int nThreads = omp_get_num_threads();
	char letras[nThreads * chunk];
	
	for(int i = 0; i < nThreads * chunk; i++){
		letras[i] = '-';
	}

	#pragma omp parallel shared(letras, chunk) private(cont, numThread)
	{
		tid = omp_get_thread_num();
		if (tid == 0){
				numThread = omp_get_num_threads();
				printf("\nNum. Threads(dinamico) = %d\n", numThread);
		}
		#pragma omp for schedule(dynamic)
		for(cont = 0; cont < numThread; cont++)
			for(int i = 0; i < chunk; i++){
				sleep(1);
				letras[i] = 'A'+cont;
				printf("%c", letras[i]);
			}
	}

	printf("\n");
}
