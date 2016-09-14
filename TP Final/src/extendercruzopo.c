#include <stdio.h>
#include "mov.h"
#include "extendercruzopo.h"

#define MAX1	9
#define MAX2	12

extern int cubo[MAX1][MAX2];

void extendercruzopo_caso_uno() // Aristas adyacentes
{
	r();
	u();
	R();
	u();
	r();
	U();
	U();
	R();
	u();
}

void extendercruzopo_caso_dos() // Aristas opuestas
{
	extendercruzopo_caso_uno();
	U();
	Y();
	extendercruzopo_caso_uno();	
}

void extender_cruz_opuesta()
{
	int aux;

	while(1)
	{
		aux = 0;
		while(aux < 4)
		{
			if((cubo[3][1]==cubo[4][1]) && (cubo[3][4]==cubo[4][4]) && (cubo[3][7]==cubo[4][7]) && (cubo[3][10]==cubo[4][10]))
				return;
			
			if((cubo[3][4]==cubo[4][4]) && (cubo[3][10]==cubo[4][10]))
			{
				extendercruzopo_caso_dos();
				return;
			}
			
			if((cubo[3][4]==cubo[4][4]) && (cubo[3][7]==cubo[4][7]))
			{
				extendercruzopo_caso_uno();
				return;
			}
			
			else
			{
				U();
				aux++;
			}
		}
		Y();
	}
}
