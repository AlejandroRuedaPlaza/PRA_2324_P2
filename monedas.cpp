#include <iostream>
#include <algorithm>
#include "monedas.h"

int cambio(int* v, int N, int M){
	int** matrix = new int*[N];
	//printf("\n  0  1  2  3  4  5  6  7  8");	
	for(int i=0; i< N ; i++){
		matrix[i] = new int[M+1];
		//std::cout << std::endl;
		for(int j=0; j<=M; j++){
			if(j == 0)
				matrix[i][j] = 0;
			else if( i == 0 && v[0]-1 > j)
				matrix[i][j] = std::numeric_limits<int>::max();//valor infinito
			else if( i == 0)
				matrix[i][j] = 1 + matrix[0][j-v[0]];
			else if(v[i] > j)
				matrix[i][j] = matrix[i-1][j];
			else
				matrix[i][j] = std::min(matrix[i-1][j], 1+matrix[i][j-v[i]]);
			//std::cout<< "  " << matrix[i][j];
		}
	}
	//std::cout << std::endl;

	return matrix[N-1][M-1];
}

int* cambio2(int* v, int N, int M){
	static int result[3] = {0, 0, 0};

        int** matrix = new int*[N];
	int i=N-1;
	int j=M;

   	for(int i=0; i< N ; i++){
		result[i] = 0;
		matrix[i] = new int[M+1];			
		//std::cout << std::endl;
		for(int j=0; j<=M; j++){
			if(j == 0)
				matrix[i][j] = 0;
			else if( i == 0 && v[0]-1 > j)
				matrix[i][j] = std::numeric_limits<int>::max();//valor infinito
			else if( i == 0)
				matrix[i][j] = 1 + matrix[0][j-v[0]];
			else if(v[i] > j)
				matrix[i][j] = matrix[i-1][j];
			else			         
				matrix[i][j] = std::min(matrix[i-1][j], 1+matrix[i][j-v[i]]);
			//std::cout<< "  " << matrix[i][j];
		}
	}
	
	while(i >= 0 && j >= 0){
		if(matrix[i][j] == (1 + matrix[i][j-v[i]])){
			result[i] += 1;
			j = j - v[i];			
		}else{
			i--;
		}
	}
		
	return result;
}


