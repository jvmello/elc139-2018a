#include <complex>
#include <iostream>
#include <omp.h>
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

using namespace std;

long wtime(){
   	struct timeval t;
   	gettimeofday(&t, NULL);
   	
	return t.tv_sec*1000000 + t.tv_usec;
}

int main(int argc, char **argv){
	int max_row, max_column, max_n, myrank, nprocs, init, lim;
	long start_time, end_time;
	//cin >> max_row;
	//cin >> max_column;
	//cin >> max_n;
	int max;

	printf("%d\n", argc);

	MPI_Init(&argc, &argv);
  	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

	printf("%d %d %d", atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

	max_row = atoi(argv[1]);
	max_column = atoi(argv[2]);
	max_n = atoi(argv[3]);

	max = max_row / nprocs;
  	init = myrank * max;
	lim = (myrank+1) * max;

	start_time = wtime();

	char **mat, *C;
	char *aa;

	if(myrank == 0){
		mat = (char**)malloc(sizeof(char*)*max_row);

		for (int i=0; i<max_row;i++)
			mat[i]=(char*)malloc(sizeof(char)*max_column);

		//aa = (char**)malloc(sizeof(char*)*max_row);

		//for (int i=0; i<max_row;i++)
		C=(char*)malloc(sizeof(char)*max_column);
		aa=(char*)malloc(sizeof(char)*max_column);
	}

	MPI_Barrier(MPI_COMM_WORLD);
printf("TENTA");
	MPI_Scatter(&mat[myrank], max, MPI_CHAR, aa, max, MPI_CHAR, 0, MPI_COMM_WORLD);
printf("TENTA");
//	MPI_Bcast(mat, max_row*max_column, MPI_CHAR, 0, MPI_COMM_WORLD);

	for(int r = init; r < lim; ++r){
		for(int c = 0; c < max_column; ++c){
			complex<float> z;
			int n = 0;
			while(abs(z) < 2 && ++n < max_n)
				z = pow(z, 2) + decltype(z)(
					(float)c * 2 / max_column - 1.5,
					(float)r * 2 / max_row - 1
				);
			aa[c]=(n == max_n ? '#' : '.');
			//printf("AAAAAAAAA %c", aa[c]);
		}
	}
printf("TENTA\n");
	
	MPI_Gather(aa, max, MPI_INT, C, max, MPI_CHAR, 0, MPI_COMM_WORLD);

	end_time = wtime();

	MPI_Barrier(MPI_COMM_WORLD);

	MPI_Finalize();

	for(int r = init; r < lim; ++r){
		for(int c = 0; c < max_column; ++c)
			std::cout << C[c];
		cout << '\n';
	}

	printf("%ld usec\n", (long) (end_time - start_time));

return 0;
}


