#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <mpi.h>

static unsigned long int next = 1;

int my_rand(void) {
	return ((next = next * 1103515245 + 12345) % ((u_long) RAND_MAX + 1));
}

void my_srand(unsigned int seed) {
	next = seed;
}

struct Graph{
	int nNodes;
	int *nEdges;
	int **edges;
	int **w;
};

struct Graph *createRandomGraph(int nNodes, int nEdges, int seed) {
	my_srand(0);

	struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));
	graph->nNodes = nNodes;
	graph->nEdges = (int *) malloc(sizeof(int) * nNodes);
	graph->edges = (int **) malloc(sizeof(int *) * nNodes);
	graph->w = (int **) malloc(sizeof(int *) * nNodes);

	int k, v;
	for (v = 0; v < nNodes; v++) {
		graph->edges[v] = (int *) malloc(sizeof(int) * nNodes);
		graph->w[v] = (int *) malloc(sizeof(int) * nNodes);
		graph->nEdges[v] = 0;
	}

	int source = 0;
	for (source = 0; source < nNodes; source++) {
		int nArestasVertice = (double) nEdges / nNodes
				* (0.5 + my_rand() / (double) RAND_MAX);
		for (k = nArestasVertice; k >= 0; k--) {
			int dest = my_rand() % nNodes;
			int w = 1 + (my_rand() % 10);
			graph->edges[source][graph->nEdges[source]] = dest;
			graph->w[source][graph->nEdges[source]++] = w;
		}
	}

	return graph;
}

int *dijkstra(struct Graph *graph, int source, int desti) {
	int nNodes = graph->nNodes;
	int *visited = (int *) malloc(sizeof(int) * nNodes);
	int *distances = (int *) malloc(sizeof(int) * nNodes);
	int k, v;

	for (v = 0; v < nNodes; v++) {
		distances[v] = INT_MAX;
		visited[v] = 0;
	}
	distances[source] = 0;
	visited[source] = 1;
	for (k = 0; k < graph->nEdges[source]; k++)
		distances[graph->edges[source][k]] = graph->w[source][k];

	for (v = source; v < desti; v++) {
		int min = 0;
		int minValue = INT_MAX;
		for (k = source; k < desti; k++)
			if (visited[k] == 0 && distances[k] < minValue) {
				minValue = distances[k];
				min = k;
			}

		visited[min] = 1;

		for (k = 0; k < graph->nEdges[min]; k++) {
			int dest = graph->edges[min][k];
			if (distances[dest] > distances[min] + graph->w[min][k])
				distances[dest] = distances[min] + graph->w[min][k];
		}
	}

	free(visited);

	return distances;
}

int main(int argc, char ** argv) {

	int nNodes;
	int nEdges;
	int seed;
	int ntasks;
	int rank;
	double start, end;
	struct Graph *graph;

	if (argc == 4) {
		nNodes = atoi(argv[1]);
		nEdges = atoi(argv[2]);
		seed = atoi(argv[3]);
		nEdges = nNodes * nEdges;
		printf("GERA");
		graph =  createRandomGraph(nNodes, nEdges, seed);
	} else {
		fscanf(stdin, "%d %d %d", &nNodes, &nEdges, &seed);
	}

		int *dists = malloc((int)nNodes * sizeof(int));

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &ntasks);

	//MPI_Barrier(MPI_COMM_WORLD);

	MPI_Barrier(MPI_COMM_WORLD);

	int val = nNodes / ntasks;

	printf("hum %d", ntasks);
	printf("rank = %d\n", rank);

	start = MPI_Wtime();

	int *dist = dijkstra(graph, val*rank, val*(rank+1));

	double mean;
	int v;

	printf("\n\n\n");

for (v = 0; v < graph->nNodes; v++)
			mean += dist[v];
	
		printf("MEDIA %d = %.2f\n", rank, mean / nNodes);	
	//mean = 0;
	
	MPI_Reduce(dist, &mean, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
//	MPI_GATHER(dist,
	end = MPI_Wtime();	

	if(rank == 0){

		printf("%.2f\n", (end-start)*1000000);
		//for (v = 0; v < graph->nNodes*ntasks; v++)
			//mean += dists[v];
	
		printf("%.2f\n", mean / nNodes);	
	}


		
	MPI_Finalize();

	return 0;
}

