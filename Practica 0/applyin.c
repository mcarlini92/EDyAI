#include <stdio.h>
#include <stdlib.h>

int distintor(int x) {
	if (x!=0) 
		return 1;
	else
		return 0;
}

void applyin(int (*ptrof)(int), int *ptron) {
	*ptron= (ptrof(*ptron));
}

int main() {
	int (*ptrof) (int);
	int nro;
	int *ptron;
	ptrof= &distintor;
	nro= 5;
	ptron= &nro;
	printf("Antes: %d \n", nro);
	applyin(ptrof,ptron);
	printf("Despues: %d \n", nro);
	return 0;
}