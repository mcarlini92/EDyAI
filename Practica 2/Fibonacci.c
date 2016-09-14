#include <stdlib.h>
#include "BTree.h"

BTree *fib(int nro){
	if (nro == 0)
		return btree_create(0, NULL, NULL);
	else if (nro == 1)
		return btree_create(1, NULL, NULL);
	else
		btree_create(nro, fib(nro-1), fib(nro-2));
}

//Cantidad de nodos hijos de un arbol = Cantidad de nodos - 1 , puse
// todos los nodos son hijo de alguien a excepcion de la raiz