#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>

int main(){
	char letras[60];
	int cont = 0;
	int numThread, tid;
	int chunk = 20;
	
	for(int i=0 ; i<60 ; i++){
		letras[i] = '-';
	}
	
	#pragma omp parallel shared(letras, chunk) private(cont, numThread)
	{
		tid = omp_get_thread_num();
		if (tid == 0){
			numThread = omp_get_num_threads();
			printf("Number of threads = %d\n", numThread);
		}
		#pragma omp for schedule(static, chunk)
		for(cont=0 ; cont < numThread; cont++)
			for(int i=0 ; i<chunk ; i++){
				letras[i] = 'A'+cont;
				printf("%c", letras[i]);
			}
	}
	printf("\n");
	
	#pragma omp parallel shared(letras, chunk) private(cont, numThread)
	{
		tid = omp_get_thread_num();
		if (tid == 0){
			numThread = omp_get_num_threads();
			printf("Number of threads Dynamic = %d\n", numThread);
		}
		#pragma omp for schedule(dynamic, chunk)
		for(cont=0 ; cont < numThread; cont++)
			for(int i=0 ; i<chunk ; i++){
				letras[i] = 'A'+cont;
				printf("%c", letras[i]);
			}
	}
	printf("\n");
	
	#pragma omp parallel shared(letras, chunk) private(cont, numThread)
	{
		tid = omp_get_thread_num();
		if (tid == 0){
			numThread = omp_get_num_threads();
			printf("Number of threads Guided = %d\n", numThread);
		}
		#pragma omp for schedule(guided, chunk)
		for(cont=0 ; cont < numThread; cont++)
			for(int i=0 ; i<chunk ; i++){
				letras[i] = 'A'+cont;
				printf("%c", letras[i]);
			}
	}	
	printf("\n");
	
	#pragma omp parallel shared(letras) private(cont, numThread)
	{
		tid = omp_get_thread_num();
		if (tid == 0){
			numThread = omp_get_num_threads();
			printf("Number of threads Runtime = %d\n", numThread);
		}
		#pragma omp for schedule(runtime)
		for(cont=0 ; cont < numThread; cont++)
			for(int i=0 ; i<chunk ; i++){
				letras[i] = 'A'+cont;
				printf("%c", letras[i]);
			}
	}
	printf("\n");
	
	#pragma omp parallel shared(letras) private(cont, numThread)
	{
		tid = omp_get_thread_num();
		if (tid == 0){
			numThread = omp_get_num_threads();
			printf("Number of threads Auto = %d\n", numThread);
		}
		#pragma omp for schedule(auto)
		for(cont=0 ; cont < numThread; cont++)
			for(int i=0 ; i<chunk ; i++){
				letras[i] = 'A'+cont;
				printf("%c", letras[i]);
			}
	}
	printf("\n");
}
