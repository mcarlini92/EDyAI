#include <stdio.h>
#include "entrada.h"

#define MAX1	9
#define MAX2	12

extern int cubo[MAX1][MAX2];

int atoi2(char s)
{
	return s - '0';			
}

void llenar_cubo()		
{
	int i, a = 0;
	int arr[54];
	int var;
	char c;
	
	printf("Ingrese la entrada del cubo\n");
	for(i = 0; i < 54; i++)
	{	
		c = getchar();
		var = atoi2(c);
		arr[i] = var;
	}	
	
	for(i=3; i<6; i++, a++)
		cubo[0][i] = arr[a];
	for(i=3; i<6; i++, a++)
		cubo[1][i] = arr[a];
	for(i=3; i<6; i++, a++)
		cubo[2][i] = arr[a];
		
	for(i=0; i<12; i++, a++)
		cubo[3][i] = arr[a];
	for(i=0; i<12; i++, a++)
		cubo[4][i] = arr[a];
	for(i=0; i<12; i++, a++)
		cubo[5][i] = arr[a];
		
	for(i=3; i<6; i++, a++)
		cubo[6][i] = arr[a];
	for(i=3; i<6; i++, a++)
		cubo[7][i] = arr[a];
	for(i=3; i<6; i++, a++)
		cubo[8][i] = arr[a];	
}

void print_cubo()
{
	int i, j, k;
	
	printf("\t");
	for(k = 0; k < MAX2; k++)
		printf("%d \t", k);
	puts("");		
	puts("");
	
	for(i = 0; i < MAX1; i++)
	{	
		printf("%d \t", i);
		for(j = 0; j < MAX2; j++)
			if(cubo[i][j] == 0)
				printf(" \t");
			else
				printf("%d \t", cubo[i][j]);	//i filas y j columnas
		puts("");
		puts("");
	}
	puts("");
	
}
