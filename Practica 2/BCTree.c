#include <stdlib.h>
#include "CBTree.h"

int potbase2(int exp){
	int i;
	int aux = 1;
	for (i=0; i <= exp; i++)
		aux = 2 * aux;
	return aux;
}

int cantnodos(int nro) {
	int i;
	int aux = 0;
	for (i=0; i <= nro; i++;)
		aux = aux + potbase2(i);
	return aux;	
}

BCTree *bctree_new(int nivel) {
	BCTree *raiz = malloc(cantnodos(nivel)*sizeof(BCTree));
	bctree_nelems(raiz) = 0;
	return raiz;
}

void bctree_destroy(BCTree *raiz) {
	int i;
	for(i=0; i < bctree_nelems(raiz); i++)
		free(bctree_data(raiz)[i]);
}

BCTree *bctree_insert(BCTree *nodo, int data) { // Mod para el caso de que supera la cant de espacio que reservé 
	bctree_data(nodo)[bctree_nelems(nodo)] = data; // nelems = cant de lugares ocupados en el arreglo 
	bctree_nelems(nodo)++;
	return nodo;
}

void  bctree_foreach(BCTree *raiz, VisitorFuncInt visit, void *extra_data) {
	int i;
	for(i=0; i < bctree_nelems(raiz); i++)
		visit(bctree_data(raiz)[i], extra_data);	
}