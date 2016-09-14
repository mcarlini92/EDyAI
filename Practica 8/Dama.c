#include <stdio.h>
#include <stdlib.h>

typedef struct punto_{
	int abs; // i
	int ord; // j
} Punto;

int solve(int n, Punto a, Punto b){
	return solve_(n, a , b, 0);
}

int solve_(int n, Punto a, Punto b, int mov){
	if(a.ord==b.ord) // Misma columna
		return (mov + n );
	if(abs(a.ord-a.abs)==abs(b.ord-b.abs)) // Misma diagonal
		return (mov+)
		



}





int main (void){
	int n;
	Punto a, b;
	scanf("Inicio: %d %d\n",&a.abs, &a.ord);
	scanf("Llegada: %d %d\n", &b.abs, &b.ord);
	printf("Solucion: %d", solve(n, a, b));
	return 0;
}