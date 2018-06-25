#include <complex>
#include <iostream>
#include <omp.h>
#include <sys/time.h>

using namespace std;

long wtime(){
   	struct timeval t;
   	gettimeofday(&t, NULL);
   	
	return t.tv_sec*1000000 + t.tv_usec;
}


int main(int argc, char **argv){
	int max_row, max_column, max_n;
	long start_time, end_time;

	max_row = atoi(argv[1]);
	max_column = atoi(argv[2]);
	max_n = atoi(argv[3]);

start_time = wtime();

	char **mat = (char**)malloc(sizeof(char*)*max_row);

	for (int i=0; i<max_row;i++)
		mat[i]=(char*)malloc(sizeof(char)*max_column);

	#pragma omp parallel for ordered schedule(dynamic)
	for(int r = 0; r < max_row; ++r){
		
		for(int c = 0; c < max_column; ++c){
			complex<float> z;
			int n = 0;
#pragma omp ordered
			while(abs(z) < 2 && ++n < max_n)
				z = pow(z, 2) + decltype(z)(
					(float)c * 2 / max_column - 1.5,
					(float)r * 2 / max_row - 1
				);
			mat[r][c]=(n == max_n ? '#' : '.');
		}
	}

	#pragma omp parallel for
	for(int r = 0; r < max_row; ++r){
		for(int c = 0; c < max_column; ++c)
			std::cout << mat[r][c];
		cout << '\n';
	}

	end_time = wtime();	

	printf("%ld usec\n", (long) (end_time - start_time));

	return 0;
}


