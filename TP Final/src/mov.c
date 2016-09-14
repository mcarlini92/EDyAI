#include <stdio.h>
#include "salida.h"
#include "mov.h"

#define MAX1	9
#define MAX2	12

extern int cubo[MAX1][MAX2];

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void swaptriple(int *a1, int *a2, int *a3, int *b1, int *b2, int *b3)
{
	int c1, c2, c3;
	
	c1 = *a1;
	c2 = *a2;
	c3 = *a3;
	*a1 = *b1;
	*a2 = *b2;
	*a3 = *b3;
	*b1 = c1;
	*b2 = c2;
	*b3 = c3;
}

void mov_cara_antih(int fil, int col)
{
	swap(&cubo[fil+1][col+1], &cubo[fil-1][col+1]);
	swap(&cubo[fil+1][col], &cubo[fil][col+1]);
	swap(&cubo[fil+1][col-1], &cubo[fil+1][col+1]);

	swap(&cubo[fil+1][col-1], &cubo[fil-1][col-1]);
	swap(&cubo[fil+1][col], &cubo[fil-1][col]);
	swap(&cubo[fil][col-1], &cubo[fil+1][col]);
	
	if(fil==1 && col==4)
	{
		swaptriple(&cubo[3][0], &cubo[3][1], &cubo[3][2], &cubo[3][3], &cubo[3][4], &cubo[3][5]);
		swaptriple(&cubo[3][0], &cubo[3][1], &cubo[3][2], &cubo[3][6], &cubo[3][7], &cubo[3][8]);
		swaptriple(&cubo[3][0], &cubo[3][1], &cubo[3][2], &cubo[3][9], &cubo[3][10], &cubo[3][11]);	
	}

	if(fil==4 && col==1)
	{
		swaptriple(&cubo[0][3], &cubo[1][3], &cubo[2][3], &cubo[5][11], &cubo[4][11], &cubo[3][11]);
		swaptriple(&cubo[0][3], &cubo[1][3], &cubo[2][3], &cubo[6][3], &cubo[7][3], &cubo[8][3]);
		swaptriple(&cubo[0][3], &cubo[1][3], &cubo[2][3], &cubo[3][3], &cubo[4][3], &cubo[5][3]);	
	}
	
	if(fil==4 && col==4)
	{
		swaptriple(&cubo[2][3], &cubo[2][4], &cubo[2][5], &cubo[5][2], &cubo[4][2], &cubo[3][2]);
		swaptriple(&cubo[2][3], &cubo[2][4], &cubo[2][5], &cubo[6][5], &cubo[6][4], &cubo[6][3]);
		swaptriple(&cubo[2][3], &cubo[2][4], &cubo[2][5], &cubo[3][6], &cubo[4][6], &cubo[5][6]);	
	}
	
	if(fil==4 && col==7)
	{
		swaptriple(&cubo[0][5], &cubo[1][5], &cubo[2][5], &cubo[3][5], &cubo[4][5], &cubo[5][5]);
		swaptriple(&cubo[0][5], &cubo[1][5], &cubo[2][5], &cubo[6][5], &cubo[7][5], &cubo[8][5]);
		swaptriple(&cubo[0][5], &cubo[1][5], &cubo[2][5], &cubo[5][9], &cubo[4][9], &cubo[3][9]);	
	}
	
	if(fil==4 && col==10)
	{
		swaptriple(&cubo[3][8], &cubo[4][8], &cubo[5][8], &cubo[0][3], &cubo[0][4], &cubo[0][5]);
		swaptriple(&cubo[3][8], &cubo[4][8], &cubo[5][8], &cubo[5][0], &cubo[4][0], &cubo[3][0]);
		swaptriple(&cubo[3][8], &cubo[4][8], &cubo[5][8], &cubo[8][5], &cubo[8][4], &cubo[8][3]);	
	}
	
	if(fil==7 && col==4)
	{
		swaptriple(&cubo[5][0], &cubo[5][1], &cubo[5][2], &cubo[5][9], &cubo[5][10], &cubo[5][11]);
		swaptriple(&cubo[5][0], &cubo[5][1], &cubo[5][2], &cubo[5][6], &cubo[5][7], &cubo[5][8]);
		swaptriple(&cubo[5][0], &cubo[5][1], &cubo[5][2], &cubo[5][3], &cubo[5][4], &cubo[5][5]);	
	}
}

void mov_cara_h(int fil, int col)
{
	 mov_cara_antih(fil, col);
	 mov_cara_antih(fil, col);
	 mov_cara_antih(fil, col);
}

void mov_capa_media()
{
	mov_cara_antih(1, 4);
	mov_cara_h(7, 4);
	swaptriple(&cubo[4][0], &cubo[4][1], &cubo[4][2], &cubo[4][3], &cubo[4][4], &cubo[4][5]);
	swaptriple(&cubo[4][0], &cubo[4][1], &cubo[4][2], &cubo[4][6], &cubo[4][7], &cubo[4][8]);
	swaptriple(&cubo[4][0], &cubo[4][1], &cubo[4][2], &cubo[4][9], &cubo[4][10], &cubo[4][11]);	
}

void r()
{
	mov_cara_antih(4, 7);
	agregar_mov('r');
}

void R()
{
	mov_cara_h(4, 7);
	agregar_mov('R');
}

void l()
{
	mov_cara_antih(4, 1);
	agregar_mov('l');
}

void L()
{
	mov_cara_h(4, 1);
	agregar_mov('L');
}

void d()
{
	mov_cara_antih(7, 4);
	agregar_mov('d');
}

void D()
{
	mov_cara_h(7, 4);
	agregar_mov('D');
}

void u()
{
	mov_cara_antih(1, 4);
	agregar_mov('u');
}

void U()
{
	mov_cara_h(1, 4);
	agregar_mov('U');
}

void b()
{
	mov_cara_antih(4, 10);
	agregar_mov('b');
}

void B()
{
	mov_cara_h(4, 10);
	agregar_mov('B');
}

void f()
{	
	mov_cara_antih(4, 4);
	agregar_mov('f');
}

void F()
{
	mov_cara_h(4, 4);
	agregar_mov('F');
}

void y()
{
	mov_capa_media();
	agregar_mov('y');
}

void Y()
{
	y();
	y();
	y();
}
