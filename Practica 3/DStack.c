#include <stdio.h>
#include <stdlib.h>
#include "Dstack.h"

Stack *stack_create(){
	DStack *newstack = malloc(sizeof(DStack));
	dstack_data(newstack) = malloc(10*sizeof(int));
	dstack_n(newstack) = 10;     
	dstack_back(newstack) = -1;     
	return newstack;
}

int dstack_top(DStack *pila) {
	int n = dstack_back(pila);
	if(n == -1)
		return 1/0;
	return dstack_data(pila)[n];
}

DStack *dstack_push(DStack *pila, int data){
	int dim = dstack_n(pila);
	int i = dstack_back(pila);
	if((dim - 1) == i)
		realloc(dstack_data(pila),dim*2*sizeof(int));
	dstack_data(pila)[i+1] = data;
	i++; // i ++ equivale a dstack_back(pila)++      
}

DStack *dstack_pop(DStack *pila) {
	if(dstack_back(pila) >= 0)
		dstack_back(pila)--;
	return pila;
}

DStack *reverse(DStack *pila) {
	DStack *revpila = dstack_create();
	int dato, nelemens;
	while(dstack_back(pila) >= 0){
		nelemens = dstack_back(pila);
		aux = dstack_data(pila)[nelemens];
		revpila = dstack_push(revpila, aux);
		dstack_back(pila)--;     
	}
	return revpila;
}

void dstack_print(DStack *pila){ 
	int i, n = dstack_back(pila);
	for (i=n; i >= 0; i--)
		printf("%d ",dstack_data(pila)[i]);
}

void dstack_destroy(DStack *pila){
	free(pila);
}

