#include <stdio.h>
#include <stdlib.h>

void setin(int *pnt){
	if (*pnt!=0)
		*pnt= 1;
	else
		*pnt= 0;
}

int main (){
	int x=5;
	int *punt;
	punt= &x;
	printf("Antes de setin: %d %d \n",*punt);
	setin(punt);
	printf("Despues de setin: %d %d \n",*punt);
	system("PAUSE");
	return 0;
}