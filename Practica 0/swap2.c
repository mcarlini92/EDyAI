#include <stdio.h>
#include <stdlib.h>

void swap_1(int *ptro1, int *ptro2) {
	*ptro1= *ptro1 + *ptro2; 
	*ptro2= *ptro1 - *ptro2;
	*ptro1= *ptro1 - *ptro2; 
}

int main (){
	int x=5;
	int y=6;
	int *punt1= &x; /*punt1 apunta a x*/
	int *punt2= &y; /*punt2 apunta a y*/
	printf("Antes de swap: %d %d \n",*punt1, *punt2);
	swap_1(punt1, punt2);
	printf("Despues de swap: %d %d \n",*punt1, *punt2);
	system("PAUSE");
	return 0;
}

/* http://www.nemediano.com.mx/2011/un-swap-sin-memoria-extra/ */