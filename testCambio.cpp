#include <iostream>
#include "monedas.h"

int main(){
	int M = 8;
	int v[]= {1,4,6};
	int N= sizeof(v)/ sizeof(int);
	
	
	std::cout<< "Numero minimo de monedas: " << cambio(v , N, M) << " para devolver "<< M << " con monedas de "<< v[0]<< ", " << v[1]<<" y " << v[2]<< std::endl;


	int *res = cambio2(v, N, M);
	printf("\nVector solucion: (");
	for(int i=0; i<N-1; i++){
		printf("%d, ",res[i]);

	}

	std::cout<< res[N-1]<<")"<<std::endl;
	return 0;
}
