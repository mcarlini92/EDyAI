#include <stdlib.h>
#include "BTree.h"

void btree_mirror(BTree *raiz) {
	if (raiz != NULL) {
		BTree *aux;
		aux = btree_left(raiz);
		btree_left(raiz) = btree_right(raiz);
		btree_right(raiz) = aux;
		btree_mirror(btree_left(raiz));
		btree_mirror(btree_right(raiz));	
	}
}