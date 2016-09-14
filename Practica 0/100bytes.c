#include <stdio.h>
#include <stdlib.h>

int main () {
	int *p = malloc(100);
	int  x = 5;
	p = &x;
	printf("Direccion puntero: %d \n",&p);
	free(p);
	free(p);
	system("PAUSE");
	return 0;
	
}

/* El programa se puede compilar sin problemas */