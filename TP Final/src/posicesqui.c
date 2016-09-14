#include <stdio.h>
#include "mov.h"
#include "posicesqui.h"

#define MAX1	9
#define MAX2	12

extern int cubo[MAX1][MAX2];

void posicesqui_caso_uno() // Intercambiar en sentido horario. 
{
	l();
	U();
	R();
	u();
	L();
	U();
	r();
	u();
}

void posicesqui_caso_dos() // Intercambiar en sentido anti-horario. 
{
	R();
	u();
	l();
	U();
	r();
	u();
	L();
	U();
}

int vertice_pos() // Comprueba si el vertice  sup-derecho esta bien posicionado
{
	if((cubo[3][5]==cubo[1][4]) || (cubo[3][5]==cubo[4][4]) || (cubo[3][5]==cubo[4][7]))
		if((cubo[2][5]==cubo[1][4]) || (cubo[2][5]==cubo[4][4]) || (cubo[2][5]==cubo[4][7]))
			if((cubo[3][6]==cubo[1][4]) || (cubo[3][6]==cubo[4][4]) || (cubo[3][6]==cubo[4][7]))
				return 1; // Vertice bien posicionado a la derecha
	
	if((cubo[3][2]==cubo[4][1]) || (cubo[3][2]==cubo[4][4]) || (cubo[3][2]==cubo[1][4]))
		if((cubo[3][3]==cubo[4][1]) || (cubo[3][3]==cubo[4][4]) || (cubo[3][3]==cubo[1][4]))
			if((cubo[2][3]==cubo[4][1]) || (cubo[2][3]==cubo[4][4]) || (cubo[2][3]==cubo[1][4]))
				return 2; // Vertice bien posicionado a la izquierda
	
	return 0;
}	

void posiciona_cubo() // Compruebo los 4 vertices en busca de uno bien orientado
{
	while(1)
	{
		int aux = 0;
		while(aux < 2)
		{	
			if(vertice_pos())
				return;
		
			else
			{
				Y();
				Y();
				aux++;
			}
		}
		posicesqui_caso_uno();
	}
}

int determinar_sentido()
{
	if((cubo[3][0]==cubo[1][4]) || (cubo[3][0]==cubo[4][7]) || (cubo[3][0]==cubo[4][10]))
		if((cubo[0][3]==cubo[1][4]) || (cubo[0][3]==cubo[4][7]) || (cubo[0][3]==cubo[4][10]))
			if((cubo[3][11]==cubo[1][4]) || (cubo[3][11]==cubo[4][7]) || (cubo[3][11]==cubo[4][10]))
				return 1; // Sentido horario
	
	if((cubo[0][5]==cubo[4][1]) || (cubo[0][5]==cubo[1][4]) || (cubo[0][5]==cubo[4][10]))
		if((cubo[3][8]==cubo[4][1]) || (cubo[3][8]==cubo[1][4]) || (cubo[3][8]==cubo[4][10]))
			if((cubo[3][9]==cubo[4][1]) || (cubo[3][9]==cubo[1][4]) || (cubo[3][9]==cubo[4][10]))
				return 2; // Sentido anti-horario
	return 0;
}

void posicionar_esquina() 
{
	posiciona_cubo();
	
	if((vertice_pos()==1) && (determinar_sentido()==1)) // Horario, der
		{
			posicesqui_caso_uno();
			return;
		}
	
	if((vertice_pos()==2) && (determinar_sentido()==1)) // Horario, izq
		{
			y();
			posicesqui_caso_uno();
			return;			
		}
	
	if((vertice_pos()==1) && (determinar_sentido()==2)) // Antih, der
		{
			Y();
			posicesqui_caso_dos();
			return;
		}
	
	if((vertice_pos()==2) && (determinar_sentido()==2)) // Antih, izq
		{
			posicesqui_caso_dos();
			return;
		}
}
