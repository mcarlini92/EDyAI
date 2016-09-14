#include <stdio.h>

int main () {
	int p[] = {6,6,6,6};
	int n = 4;
	int i;
	int suma = 0;
	for (i=0; i<=(n-1) ;i++)
		suma = (suma + p[i]);
	printf("Promedio: %d \n", (suma/n));
	system("PAUSE");
	return 0;
}