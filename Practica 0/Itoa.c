#include <stdio.h>
#include <stdlib.h>


int cant(int y){
	int z=0;
	while (y>=1){
		++z;
		y=y/10;
	}
	return z;
}			

char *itoa_2(int x){
	char *ptr;	
	int n=0;	
	int z = cant(x);
	int t = cant(x)-1;
	int v=0;	
	ptr = malloc(z*(sizeof(char)));
	while (x!=0){
		n = (x%10);
		x = x/10;
		*((ptr+t))= n + '0';
		t=t-1;
	}
	*((ptr+z))= '\0';
	return ptr;
}

int main(void){
	int x=12;	
	char *punt;
	punt = itoa_2(x);
	printf("El arreglo es: %s \n", punt);
	free(punt);
	system("PAUSE");
	return 0;
	
}

