#include <stdio.h>
#include <stdlib.h>

int moneda(int nro){
	switch(nro)
		case 0:
			return 20;
		case 1:
			return 10;
		case 2:
			return 5;
		case 3;
			return 1;
}

int *solve(int vuelto){
	int *solucion;
	int resto = vuelto;
	solucion = malloc(4*sizeof(int));
	solucion[0]=vuelto/20;
	resto = vuelto - (solucion[0]*20);
	for(i=0; i < 4; i++){
		solucion[i] = resto/moneda(i);
		resto= resto % moneda(i);	
	}
	return solucion;
}

int main(void) {
	int i, vuelto, *solucion;
	scanf("Vuelto a devolver %d", &vuelto);
	solucion = solve(vuelto);
	printf("\n 20cv: %d , 10cv: %d , 5cv: %d , 1cv: %d",solucion[0], solucion[1], solucion[2], solucion[3]);
	return 0;
}

/*
Utilizo mod y division entera para saber la cantidad de monedas a utilizar de cada valor disp, basicamente lo que hago es ir utilizando la moneda con el valor mas alto hasta que llegar a un punto en que sobrepaso lo que debo devolver y entonces utilizo la misma idea con las demas monedas. Es un algoritmo greedy porque en cada bucle lo que optimizo es la cantidad de veces que tengo que usar la moneda respectiva , y como tengo que usar la menor cantidad , tiene mayor prioridad las de mas valor . Cada posicion de solucion reepresenta una moneda siendo la relacion pos 0 = 20cv , 1pos = 10 ... , 3pos = 1cv

Ejemplo: 
Debo devolver 127 , entonces mi algoritmo realizara lo siguiente ... empiezo con resto = 127

1º  Solucion[0] = 127/20 = 6 (div entera)
	Resto = 127 mod 20 = 7
	
2º	Solucion[1] = 7 / 10 = 0
	Resto = 7 mod 10 = 7

3º	Solucion[2] = 7 / 5 = 1
	Resto = 7 mod 5 = 2 

4º	Solucion[3] = 2 / 1 = 2
	Resto = 2 mod 1 = 0
	
Por lo tanto , la cantidad a usar de monedas sera (6)*20cv - (0)*10cv - (1)*5cv - (2)*1cv 

No es posible utilizar este algoritmo con cualquiera valor de monedas , por ejemplo si solamente usamos monedas de valores pares entonces sera imposible devolver el vuelto de manera exacta si este es impar. El hecho de poder utilizar la moneda de 1cv nos garantiza que siempre existira una solucion  

*/