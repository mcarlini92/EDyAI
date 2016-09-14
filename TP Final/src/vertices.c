#include <stdio.h>
#include "mov.h"
#include "vertices.h"

#define MAX1	9
#define MAX2	12

extern int cubo[MAX1][MAX2];

void vertice_caso_uno() // Vertice en el lado derecho con el color hacia el frente
{
	f();
	u();
	F();
}

void vertice_caso_dos() // Vertice en el lado izquierdo con el color hacia el frente
{
	F();
	U();
	f();
}

void vertice_caso_tres() // Vertice en el lado derecho con el color hacia arriba 
{
	f();
	U();
	F();
	U();
	U();
	vertice_caso_uno();
}

int comprueba_vertices() // Comprueba si todos los vertices estan en su lugar
{
	if((cubo[6][3]==cubo[7][4]) && (cubo[5][3]==cubo[4][4]) && (cubo[5][2]==cubo[4][1]))
		if((cubo[6][5]==cubo[7][4]) && (cubo[5][6]==cubo[4][7]) && (cubo[5][5]==cubo[4][4]))
			if((cubo[8][3]==cubo[7][4]) && (cubo[5][0]==cubo[4][1]) && (cubo[5][11]==cubo[4][10]))
				if((cubo[8][5]==cubo[7][4]) && (cubo[5][8]==cubo[4][7]) && (cubo[5][9]==cubo[4][10]))
					return 1;
	return 0;
}

void vertice_posicionar_cubo(int aux) // Trae al frente la cara con el color de arriba del vertice
{
	if(aux==cubo[4][4])
		return;
	
	if(aux==cubo[4][1])
	{
		y();
		return;
	}
	
	if(aux==cubo[4][7])
	{
		Y();
		return;
	}
	
	if(aux==cubo[4][10])
	{
		y();
		y();
		return;		
	}
}

int buscar_vertice_tercera_capa()
{
	if((cubo[3][2]==cubo[7][4]) || (cubo[3][3]==cubo[7][4])) // Vertices con el color de la cara de abajo apuntado a un costado 
	{	
		vertice_posicionar_cubo(cubo[2][3]);
		return 1;
	}
	
	if((cubo[3][5]==cubo[7][4]) || (cubo[3][6]==cubo[7][4]))
	{	
		vertice_posicionar_cubo(cubo[2][5]);
		return 1;
	}
	
	if((cubo[3][8]==cubo[7][4]) || (cubo[3][9]==cubo[7][4]))
	{	
		vertice_posicionar_cubo(cubo[0][5]);
		return 1;
	}
	
	if((cubo[3][0]==cubo[7][4]) || (cubo[3][11]==cubo[7][4])) 
	{	
		vertice_posicionar_cubo(cubo[0][3]);
		return 1;
	}
	
	if(cubo[2][3]==cubo[7][4]) // Vertices con el color de la cara de abajo apuntado hacia arriba
	{	
		vertice_posicionar_cubo(cubo[3][3]);
		return 1;
	}
	
	if(cubo[2][5]==cubo[7][4])
	{	
		vertice_posicionar_cubo(cubo[3][5]);
		return 1;
	}
	
	if(cubo[0][5]==cubo[7][4])
	{	
		vertice_posicionar_cubo(cubo[3][9]);
		return 1;
	}
	
	if(cubo[0][3]==cubo[7][4])
	{	
		vertice_posicionar_cubo(cubo[3][11]);
		return 1;
	}
	
	return 0;
}

int buscar_vertice_primera_capa()
{
	if((cubo[6][5]!=cubo[7][4]) || (cubo[5][5]!=cubo[4][4]) || (cubo[5][6]!=cubo[4][7])) // Vertice mal posicionado en el lado frontal-derecho
	{	
		vertice_caso_uno();
		return 1;
	}
	
	if((cubo[6][3]!=cubo[7][4]) || (cubo[5][3]!=cubo[4][4]) || (cubo[5][2]!=cubo[4][1])) // Vertice mal posicionado en el lado frontal-izquierdo
	{	
		vertice_caso_dos();
		return 1;
	}
	
	if((cubo[8][5]!=cubo[7][4]) || (cubo[5][8]!=cubo[4][7]) || (cubo[5][9]!=cubo[4][10])) // Vertice mal posicionado en el lado trasero-derecho
	{	
		Y();
		vertice_caso_uno();
		return 1;
	}
	
	if((cubo[8][3]!=cubo[7][4]) || (cubo[5][0]!=cubo[4][1]) || (cubo[5][11]!=cubo[4][10])) // Vertice mal posicionado en el lado trasero-izquierdo
	{	
		y();
		vertice_caso_dos();
		return 1;
	}

	return 0;
}

void posicionar_vertice()
{
	if((cubo[3][5]==cubo[4][4]) || (cubo[3][5]==cubo[4][7]) || (cubo[3][5]==cubo[7][4])) // Compruebo si el vertice frontal-derecho esta bien posicionado
		if((cubo[3][6]==cubo[4][4]) || (cubo[3][6]==cubo[4][7]) || (cubo[3][6]==cubo[7][4]))
			if((cubo[2][5]==cubo[4][4]) || (cubo[2][5]==cubo[4][7]) || (cubo[2][5]==cubo[7][4]))
				return;

	if((cubo[3][2]==cubo[4][4]) || (cubo[3][2]==cubo[4][1]) || (cubo[3][2]==cubo[7][4])) // Compruebo si el vertice frontal-izquierdo esta bien posicionado
		if((cubo[3][3]==cubo[4][4]) || (cubo[3][3]==cubo[4][1]) || (cubo[3][3]==cubo[7][4]))
			if((cubo[2][3]==cubo[4][4]) || (cubo[2][3]==cubo[4][1]) || (cubo[2][3]==cubo[7][4]))
				return;
	
	U(); // Si no esta ninguno bien posicionado, muevo la capa de arriba hasta encontrar uno 
	posicionar_vertice();
}

void insertar_vertices()
{
	while(1)
	{
		if(comprueba_vertices())
			return;
			
		if(buscar_vertice_tercera_capa())
		{
			posicionar_vertice();
			
			if(cubo[3][3]==cubo[7][4])
				vertice_caso_dos();
			
			if(cubo[3][5]==cubo[7][4])
				vertice_caso_uno();
			
			if(cubo[2][5]==cubo[7][4])
				vertice_caso_tres();
			
			if(cubo[2][3]==cubo[7][4])
			{
				y();
				vertice_caso_tres();
			}		
			
			insertar_vertices();
		}
		
		else
			buscar_vertice_primera_capa();
	}
}
