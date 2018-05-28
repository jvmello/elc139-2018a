#include <stdio.h>
#include <mpi.h>
#include <time.h>

int main(int argc,char *argv[])
{
   	int p, rank, dest, tag = 1, source, rc;
   	int inmsg, outmsg = 100;
   	MPI_Status status;

   	MPI_Init(&argc,&argv);
   	MPI_Comm_size(MPI_COMM_WORLD, &p);
   	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	printf("Processo %d iniciando...\n",rank);

	srand(time(NULL));
	int val = rand() % 100;

   	if(rank == 0){ //primeiro processo, incrementa e envia
    	dest = 1;
      	source = dest;
		printf("Valor inicial -> %d\n", val);
		val += 1;
      	rc = MPI_Send(&val, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
      	printf("Enviei mensagem para processo %d -> %d\n", dest, val);
		val += 1;
   	}
   	else if(rank == p - 1){ //último processo, apenas recebe
    	source = rank - 1;
      	rc = MPI_Recv(&val, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
      	printf("Recebi mensagem do processo %d -> %d\n", source, val);
//	val -= 1;	
      	printf("Calculos finalizados, N final = %d\n", val);
   	}
   	else{ //processos "do meio", recebem o valor e passam adiante
      	dest = rank + 1;
      	source = rank - 1;
      	rc = MPI_Recv(&val, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
      	printf("Recebi mensagem do processo %d -> %d\n", source, val);
		val += 1;
      	rc = MPI_Send(&val, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
      	printf("Enviei mensagem para processo %d -> %d\n", dest, val);
   	}

	MPI_Finalize();

	return 0;
}





