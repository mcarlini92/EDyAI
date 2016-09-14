#include <stdio.h>
#include "mov.h"
#include "cruz.h"

#define MAX1	9
#define MAX2	12

extern int cubo[MAX1][MAX2];

void cruz_caso_uno() // Arista en la capa superior bien orientada
{
	F();
	F();
}

void cruz_caso_dos() // Arista en la capa superior mal orientada
{
	u();
	r();
	F();
	R();
}

void cruz_posicionar_arista() // Busca y mueve la arista correspondiente a la cara inferior-frontal a la cara frontal-superior
{	
	if(cubo[5][4] == cubo[7][4] && cubo[6][4] == cubo[4][4]) // Arista bien posicionada pero mal orientada
	{
		F();
		F();
		return;
	}
	
	if(cubo[7][5]==cubo[4][4] || cubo[7][5]==cubo[7][4]) // Arista capa inferior, cara derecha
		if(cubo[5][7]==cubo[4][4] || cubo[5][7]==cubo[7][4])
		{
			R();
			R();
			U();
			return;
		}
	
	if(cubo[8][4]==cubo[4][4] || cubo[8][4]==cubo[7][4]) // Arista capa inferior, cara trasera
		if(cubo[5][10]==cubo[4][4] || cubo[5][10]==cubo[7][4])
		{
			B();
			B();
			U();
			U();
			return;
		}
	
	if(cubo[7][3]==cubo[4][4] || cubo[7][3]==cubo[7][4]) // Arista capa inferior, cara izquierda
		if(cubo[5][1]==cubo[4][4] || cubo[5][1]==cubo[7][4])
		{
			L();
			L();
			u();
			return;
		}
	
	if(cubo[4][5]==cubo[4][4] || cubo[4][5]==cubo[7][4]) // Arista capa media, cara frotal-derecha
		if(cubo[4][6]==cubo[4][4] || cubo[4][6]==cubo[7][4])
		{
			f();
			return;
		}
		
	if(cubo[4][2]==cubo[4][4] || cubo[4][2]==cubo[7][4]) // Arista capa media, cara frontal-izquierda
		if(cubo[4][3]==cubo[4][4] || cubo[4][3]==cubo[7][4])
		{
			F();
			return;
		}

	if(cubo[4][8]==cubo[4][4] || cubo[4][8]==cubo[7][4]) // Arista capa media, cara trasera-derecha
		if(cubo[4][9]==cubo[4][4] || cubo[4][9]==cubo[7][4])
		{
			r();
			U();
			R();
			return;
		}
		
	if(cubo[4][0]==cubo[4][4] || cubo[4][0]==cubo[7][4]) // Arista capa media, cara trasera-izquierda
		if(cubo[4][11]==cubo[4][4] || cubo[4][11]==cubo[7][4])
		{
			L();
			u();
			l();
			return;
		}
	
	if(cubo[1][5]==cubo[4][4] || cubo[1][5]==cubo[7][4]) // Arista capa superior, cara superior-derecha
		if(cubo[3][7]==cubo[4][4] || cubo[3][7]==cubo[7][4])
		{
			U();
			return;
		}
	
	if(cubo[3][1]==cubo[4][4] || cubo[3][1]==cubo[7][4]) // Arista capa superior, cara superior-izquierda
		if(cubo[1][3]==cubo[4][4] || cubo[1][3]==cubo[7][4])
		{
			u();
			return;
		}
	
	if(cubo[0][4]==cubo[4][4] || cubo[0][4]==cubo[7][4]) // Arista capa superior, cara superior-trasera
		if(cubo[3][10]==cubo[4][4] || cubo[3][10]==cubo[7][4])
		{
			U();
			U();
			return;
		}
}

void colocar_arista() // Colocar arista posicionada en la capa superior
{
	if((cubo[5][4]==cubo[4][4]) && (cubo[6][4]==cubo[7][4])) // Arista bien posicionada y orientada
		return;
		
	cruz_posicionar_arista();
	
	if(cubo[3][4]==cubo[4][4])
	{
		cruz_caso_uno();
		return;
	}
	
	else
	{
		cruz_caso_dos();
		return;	
	}
}

void formar_cruz() // Posiciono la arista corresp a la cara inferior-frontal y repito el procedimiento 4 veces
{
	
	int aux;
	for(aux=0;aux<4;aux++)
	{
		colocar_arista();
		Y();
	}
}		
