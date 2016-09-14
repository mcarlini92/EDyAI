#include <stdio.h>
#include <stdlib.h>
#define MAXDIG 6 


int digitos(int nro){ // Devuelve la cant de digitos de un nro
	int cont = 1;
	while ((nro/10) !=0){
		nro = nro / 10;
		cont ++;
	}
	return cont;
}

int es_factible (int nro){  // Pasa el numero a un array y controla si tiene algun digito repetido
	int i, aux = digitos(nro);
	int data[aux];
	for(i=0; i < aux ; i++){
		data[i] = nro % 10;
		nro /= 10; 
	}
	for(i=0;i < aux-1; i++)
		for(j=i+1; j < aux;j++)
			if(data[i]==data[j])
				return 0;
		
	return 1;
}

int concatena(int nro1, int nro2){ // Concatena nro1 con nro2 
	int aux, r;  
	aux = nro2; 
	do { 
		nro1 *= 10; 
		} while ((aux /= 10) > 0); 
	r = nro1 + nro2; 
   return r; 
} 

void backtraking(int nro){ // Funcion backtraking
	int i;
	if (digitos(nro) == MAXDIG){
		printf(" Nro: %d \n", nro);
		return;
	}
	for(i=0;i <= 9;i++)
		if(es_factible(concaneta(nro, i)))
			backtraking(concaneta(nro, i));
}


int main(void) {
	int i;
	for(i=1; i <= 9;i++)
		backtraking(i);
	return 0;
}