#include <stdio.h>
#include "mov.h"
#include "aristas.h"

#define MAX1	9
#define MAX2	12

extern int cubo[MAX1][MAX2];

void arista_caso_uno() // La arista se encuentra a la izq
{
	U();
	F();
	U();
	f();
	u();
	l();
	u();
	L();
}

void arista_caso_dos() // La arista se encuentra a la der
{
	u();
	f();
	u();
	F();
	U();
	R();
	U();
	r();
}

void posicionar_cubo(int aux) // Trae al frente la cara con el color de arriba de la arista
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

int buscar_arista_tercera_capa() // Busca aristas en donde los 2 colores sean diferentes del de la cara superior
{
	if((cubo[2][4]!=cubo[1][4]) && (cubo[3][4]!=cubo[1][4]))
	{	
		posicionar_cubo(cubo[2][4]);
		return 1;
	}
	
	if((cubo[1][3]!=cubo[1][4]) && (cubo[3][1]!=cubo[1][4]))
	{	
		posicionar_cubo(cubo[1][3]);
		return 1;
	}
	
	if((cubo[1][5]!=cubo[1][4]) && (cubo[3][7]!=cubo[1][4]))
	{	
		posicionar_cubo(cubo[1][5]);
		return 1;
	}
	
	if((cubo[0][4]!=cubo[1][4]) && (cubo[3][10]!=cubo[1][4]))
	{	
		posicionar_cubo(cubo[0][4]);
		return 1;
	}

	return 0;
}

void buscar_arista_segunda_capa() // Busca aristas en la segunda capa pero mal posicionadas
{
	if((cubo[4][2]!=cubo[4][1]) || (cubo[4][3]!=cubo[4][4])) // Aristas de la cara frontal
	{	
		y();
		arista_caso_dos();
		return;
	}
	
	if((cubo[4][5]!=cubo[4][4]) || (cubo[4][6]!=cubo[4][7]))
	{	
		arista_caso_dos();
		return;
	}
	
	if((cubo[4][8]!=cubo[4][7]) || (cubo[4][9]!=cubo[4][10])) // Aristas de la cara trasera
	{	
		Y();
		arista_caso_dos();
		return;
	}
	
	if((cubo[4][0]!=cubo[4][1]) || (cubo[4][11]!=cubo[4][10]))
	{	
		y();
		y();
		arista_caso_dos();
		return;
	}
}

void posicionar_arista() // Giro la cara de arriba hasta encontrar una coincidencia
{
	while(1)
	{
		if((cubo[1][3]==cubo[4][4] && cubo[3][1]==cubo[4][1]) || (cubo[1][5]==cubo[4][4] && cubo[3][7]==cubo[4][7]))
			return;
			
		else
			U();
	}
}

int comprueba_aristas() // Comprueba que todas las aristas de la 2da capa esten bien posicionadas
{
	if((cubo[4][0]==cubo[4][1]) && (cubo[4][2]==cubo[4][1]))
		if((cubo[4][3]==cubo[4][4]) && (cubo[4][5]==cubo[4][4]))
			if((cubo[4][6]==cubo[4][7]) && (cubo[4][8]==cubo[4][7]))
				if((cubo[4][9]==cubo[4][10]) && (cubo[4][11]==cubo[4][10]))
					return 1;
	return 0;
}

void insertar_aristas()
{
	while(1)
	{
		if(comprueba_aristas())
			return;
				
		if(buscar_arista_tercera_capa())
		{
			posicionar_arista();
                
			if(cubo[3][1]==cubo[4][1])
					arista_caso_uno();
			                 
			if(cubo[3][7]==cubo[4][7])
                    arista_caso_dos();
		}
            
		else
			buscar_arista_segunda_capa();		
	}
}
