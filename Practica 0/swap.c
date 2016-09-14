#include <stdio.h>
#include <stdlib.h>

void swap_1(int *ptro1, int *ptro2) {
	int temp;
	temp= *ptro1; /*Guardo en temp el valor de la variable a la que apunta ptro1*/
	*ptro1= *ptro2; /*Modifico el valor de la variable a la que apunta tpro1 por el valor de la variable a la que apunta ptro2*/
	*ptro2= temp; /*Modifico el valor de la variable a la que apunta tpro2 por el valor de la variable al que apuntaba ptro1 (que se guardo en temp) */
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