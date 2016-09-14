#include <stdio.h>
#include <stdlib.h>

int distintor(int x) {
	if (x!=0) 
		return 1;
	else
		return 0;
}

int apply(int (*ptrof)(int), int nro) {
	int aux;
	aux=ptrof(nro);
	return aux;
}

int main() {
	int nro= 5;
	int (*ptro) (int);
	ptro= &distintor;	
	printf("Resultado: %d", apply(ptro, nro)); 
	return 0;
}