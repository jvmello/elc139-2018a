#include <complex>
#include <iostream>
#include <omp.h>
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


#define MATSIZE 500
#define NRA MATSIZE            /* number of rows in matrix A */
#define NCA MATSIZE            /* number of columns in matrix A */
#define NCB MATSIZE            /* number of columns in matrix B */
#define MASTER 0               /* taskid of first task */
#define FROM_MASTER 1          /* setting a message type */
#define FROM_WORKER 2          /* setting a message type */

using namespace std;

long wtime(){
   	struct timeval t;
   	gettimeofday(&t, NULL);
   	
	return t.tv_sec*1000000 + t.tv_usec;
}

int main(int argc, char **argv){
	int max_row, max_column, max_n, myrank, nprocs, init, lim, dest;
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

	
  	init = myrank * max;
	lim = (myrank+1) * max;

	start_time = wtime();

	char **mat, *C;
	char *aa;

	int numworkers = nprocs-1;

	int mtype;


/**************************** master task ************************************/
   if (myrank == 0)
   {
      printf("mpi_mm has started with %d tasks.\n",nprocs);

      	mat = (char**)malloc(sizeof(char*)*max_row);

		for (int i=0; i<max_row;i++)
			mat[i]=(char*)malloc(sizeof(char)*max_column);

      /* Measure start time */
      double start = MPI_Wtime();

      /* Send matrix data to the worker tasks */
      max = max_row / numworkers;
      //extra = NRA%numworkers;
      offset = 0;
      mtype = FROM_MASTER;
      for (dest=1; dest<=numworkers; dest++)
      {
         rows = (dest <= extra) ? averow+1 : averow;   	
         // printf("Sending %d rows to task %d offset=%d\n",rows,dest,offset);
         MPI_Send(&offset, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
         MPI_Send(&rows, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
         MPI_Send(&mat[offset][0], rows*NCA, MPI_DOUBLE, dest, mtype, MPI_COMM_WORLD);
         MPI_Send(&b, NCA*NCB, MPI_DOUBLE, dest, mtype, MPI_COMM_WORLD);
         offset = offset + rows;
      }

      /* Receive results from worker tasks */
      mtype = FROM_WORKER;
      for (i=1; i<=numworkers; i++)
      {
         source = i;
         MPI_Recv(&offset, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
         MPI_Recv(&rows, 1, MPI_INT, source, mtype, MPI_COMM_WORLD, &status);
         MPI_Recv(&mat[offset][0], rows*NCB, MPI_DOUBLE, source, mtype, 
                  MPI_COMM_WORLD, &status);
         // printf("Received results from task %d\n",source);
      }

      /* Print results */
      /*
     for(int r = init; r < lim; ++r){
		for(int c = 0; c < max_column; ++c)
			std::cout << C[c];
			cout << '\n';
		}

		printf("%ld usec\n", (long) (end_time - start_time));
      }
      printf("\n******************************************************\n");
      */

      /* Measure finish time */
      double finish = MPI_Wtime();
      printf("Done in %f seconds.\n", finish - start);
   }


/**************************** worker task ************************************/
   if (taskid > MASTER)
   {
      mtype = FROM_MASTER;
      MPI_Recv(&offset, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
      MPI_Recv(&rows, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD, &status);
      MPI_Recv(&a, rows*NCA, MPI_DOUBLE, MASTER, mtype, MPI_COMM_WORLD, &status);
      MPI_Recv(&b, NCA*NCB, MPI_DOUBLE, MASTER, mtype, MPI_COMM_WORLD, &status);

     for(int r = 0; r < max_row; ++r){
		for(int c = 0; c < max_column; ++c){
			complex<float> z;
			int n = 0;
			while(abs(z) < 2 && ++n < max_n)
				z = pow(z, 2) + decltype(z)(
					(float)c * 2 / max_column - 1.5,
					(float)r * 2 / max_row - 1
				);
			mat[r][c]=(n == max_n ? '#' : '.');
		}
	}
      mtype = FROM_WORKER;
      MPI_Send(&offset, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD);
      MPI_Send(&rows, 1, MPI_INT, MASTER, mtype, MPI_COMM_WORLD);
      MPI_Send(&c, rows*NCB, MPI_DOUBLE, MASTER, mtype, MPI_COMM_WORLD);
   }

	MPI_Finalize();



return 0;
}

