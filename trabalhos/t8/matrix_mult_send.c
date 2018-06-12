#include <stdio.h>
#include <mpi.h>
#define N 8

MPI_Status status;

double a[N][N], b[N][N], c[N][N];

int main(int argc, char **argv){
  	int nprocs, myrank, numprocs, source, dest, colunas, offset, i, j, k, num = 0;

	MPI_Init(&argc, &argv);
  	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

  	numprocs = nprocs-1;

  	if(myrank == 0){
    	for(i = 0; i < N; i++){
      		for(j = 0; j < N; j++){
        		a[i][j] = num;
				num++;
        		b[i][j] = num;
				num++;
      		}
    	}

	    colunas = N/numprocs;
    	offset = 0;

	    for(dest = 1; dest <= numprocs; dest++){
    	  MPI_Send(&offset, 1, MPI_INT, dest, 1, MPI_COMM_WORLD);
	      MPI_Send(&colunas, 1, MPI_INT, dest, 1, MPI_COMM_WORLD);
	      MPI_Send(&a[offset][0], colunas*N, MPI_DOUBLE,dest, 1, MPI_COMM_WORLD);
	      MPI_Send(&b, N*N, MPI_DOUBLE, dest, 1, MPI_COMM_WORLD);
    	  offset = offset + colunas;
	    }

	    for(i = 1; i <= numprocs; i++){
	      source = i;
	      MPI_Recv(&offset, 1, MPI_INT, source, 2, MPI_COMM_WORLD, &status);
	      MPI_Recv(&colunas, 1, MPI_INT, source, 2, MPI_COMM_WORLD, &status);
	      MPI_Recv(&c[offset][0], colunas*N, MPI_DOUBLE, source, 2, MPI_COMM_WORLD, &status);
    	}
		
		printf("Matriz A:\n");
	    for(i = 0; i < N; i++){
	      for(j = 0; j < N; j++)
	        printf("%6.2f   ", a[i][j]);
		  printf("\n");
    	}

		printf("Matriz B:\n");
	    for(i = 0; i < N; i++){
	      for(j = 0; j < N; j++)
	        printf("%6.2f   ", b[i][j]);
		  printf("\n");
    	}

    	printf("Matriz C:\n");
	    for(i = 0; i < N; i++){
	      for(j = 0; j < N; j++)
	        printf("%6.2f   ", c[i][j]);
		  printf("\n");
    	}
  	}

  	if(myrank != 0){
    	source = 0;
	    MPI_Recv(&offset, 1, MPI_INT, source, 1, MPI_COMM_WORLD, &status);
	    MPI_Recv(&colunas, 1, MPI_INT, source, 1, MPI_COMM_WORLD, &status);
	    MPI_Recv(&a, colunas*N, MPI_DOUBLE, source, 1, MPI_COMM_WORLD, &status);
	    MPI_Recv(&b, N*N, MPI_DOUBLE, source, 1, MPI_COMM_WORLD, &status);

    	/* Matrix multiplication */
	    for(k = 0; k < N; k++)
	      for(i = 0; i < colunas; i++){
    	    c[i][k] = 0.0;
    	    for(j = 0; j < N; j++)
    	      c[i][k] = c[i][k] + a[i][j] * b[j][k];
    	  }

	    MPI_Send(&offset, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
    	MPI_Send(&colunas, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
	    MPI_Send(&c, colunas*N, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	
	return EXIT_SUCCESS;
}
