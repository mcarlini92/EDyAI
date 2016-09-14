#include <stdio.h>
#include <stdlib.h>

void setzerozero(int a[]) {
	int i;
	a[0]=0;
	for(i=0;i<4;i++)
		printf("%d ",a[i]);
}

int main () {
	int p[] = {6,6,6,6};
	int i;
	setzerozero(p);
	printf("\n");
/*Comprobacion desde la funcion llamante*/
	for(i=0;i<4;i++) 
		printf("%d ",p[i]);
	printf("\n");	
	system("PAUSE");
	return 0;
}