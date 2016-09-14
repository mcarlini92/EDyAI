#include <stdio.h>
#include <stdlib.h>
#include "salida.h"

#define MAX1	9
#define MAX2	12

extern int cubo[MAX1][MAX2];
char receta[500];
int	cont = 0;

int opuesto(char arg)
{
	if((int)arg < 98)
		return ((int)arg+32);
	
	else
		return ((int)arg-32);
}

void agregar_mov(char mov)
{
	if(cont>0)	// Elimina 2 movimientos que esten ubicados en la receta en forma consecutiva y sean inversos
		if(opuesto(mov)==receta[cont-1])	
		{
			cont-=1;
			return;
		}
	
	if(cont>1)	// Reemplaza 3 movimientos iguales ubicados en la receta en forma consecutiva por el inverso a estos
		if((receta[cont-2]==mov) && (receta[cont-1]==mov))	
		{
			cont-=2;
			receta[cont] = opuesto(mov);
			cont++;
			return;
		}
		
	receta[cont] = mov;
	cont++;
}

int testing_comprobar_cara(int x, int y) // Comprueba si una cara esta bien armada
{
	if((cubo[x][y]==cubo[x-1][y-1]) && (cubo[x][y]==cubo[x-1][y]) && (cubo[x][y]==cubo[x-1][y+1]))
		if((cubo[x][y]==cubo[x][y-1]) && (cubo[x][y]==cubo[x][y+1]))
			if((cubo[x][y]==cubo[x+1][y-1]) && (cubo[x][y]==cubo[x+1][y]) && (cubo[x][y]==cubo[x+1][y+1]))
				return 1;
	
	return 0;
}

int testing_comprobar_cubo() // Comprueba si el cubo fue resuelto
{
	if(testing_comprobar_cara(4, 1))
		if(testing_comprobar_cara(1, 4))
			if(testing_comprobar_cara(4, 4))
				if(testing_comprobar_cara(7, 4))
					if(testing_comprobar_cara(4, 7))
						if(testing_comprobar_cara(4, 10))
							return 1;
	return 0;
	
}

void imprimir_receta()
{
	int i;

	for(i=0; i < (cont-1); i++)
		printf("%c", receta[i]);		
}
