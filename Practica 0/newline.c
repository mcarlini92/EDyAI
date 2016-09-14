#include <stdio.h>
#include <stdlib.h>

char* getnewline() {
	char aux;
	int i;
	char *ptr =(char*)malloc(100);
	printf("Linea: "); scanf("%s",ptr);
	return ptr;
	free(ptr);
}

int main() {
	printf("Linea escrita: %s", getnewline()); 
	return 0;
}

// Usar ^Z (Cntrl+Z) parar hacer salto de linea y enter para fin de archivo