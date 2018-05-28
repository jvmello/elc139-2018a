#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
   	double *a;
   	double *b;
   	double c;
   	int wsize;
	int repeat; 
} dotdata_t;

dotdata_t dotdata;

double dot_product(double *a, double *b, int n, int rep){
  	int i, j;
	double dotprod = 0.0;
  
  	for(j = 0; j < rep; j++){
		dotprod = 0.0;
		for(i = 0; i < n; i++){
    		dotprod += a[i] * b[i];
		}
	}

  	return dotprod;
}

void fill(double *a, int size, double value){  
	int i;
   	for(i = 0; i < size; i++){
    	a[i] = value;
   	}
}

long wtime(){
   	struct timeval t;
   	gettimeofday(&t, NULL);
   	
	return t.tv_sec*1000000 + t.tv_usec;
}

int main(int argc, char *argv[]){
  	int i;
  	double prod, local_prod;
  	int my_rank, n, p;
	long start_time, end_time;
  	int num_procs;
  	int bn, en;
 
   	if((argc != 3)){
   	    printf("Uso: %s <nelementos> <nrepeticoes>\n", argv[0]);
    	exit(EXIT_FAILURE);
   	}

	n = atoi(argv[1]);
	dotdata.repeat = atoi(argv[2]);

	start_time = wtime();

 	MPI_Init(&argc, &argv);
  	MPI_Comm_size(MPI_COMM_WORLD, &p);
  	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

   	dotdata.a = (double *) malloc(n*p*sizeof(double));
   	fill(dotdata.a, p * n, 0.01);
   	dotdata.b = (double *) malloc(n*p*sizeof(double));
   	fill(dotdata.b, p * n, 1.0);
  	
	//calcula o produto localmente em cada processo
	local_prod = dot_product(dotdata.a, dotdata.b, n, dotdata.repeat);

	//reúne todos os resultados
  	MPI_Reduce(&local_prod, &prod, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	
	end_time = wtime();  
  	
	MPI_Finalize();

  	if(my_rank == 0){
    	printf("dotProduct = %.2f\n", prod);
   		printf("%ld usec\n", (long) (end_time - start_time));
  	}

   	fflush(stdout);

   	free(dotdata.a);
   	free(dotdata.b);

   	return 0;
}

