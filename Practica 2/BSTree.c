#include <stdlib.h>
#include "BSTree.h"

BSTree *bstree_insert(BSTree *raiz, int data) {
	BSTree *raiz2 = raiz;	
	if (raiz2 == NULL) {
		BSTree *newnode = malloc(sizeof(BSTree));
		bstree_data(newnode)	= data;
		bstree_left(newnode)	= NULL;
		bstree_right(newnode)	= NULL;
		if (raiz == NULL)
			return newnode;
		if (bstree_data(raiz2) < data)
			bstree_right(raiz2) = newnode;
		else
			bstree_left(raiz) = newnode;
		return raiz;
	}
	else if ((bstree_data(raiz2)) < data)
		bstree_insert(bstree_right(raiz2), data);
	else
		bstree_insert(bstree_left(raiz2), data);
}

int bstree_contains(BSTree *raiz, int data) {
	if (raiz == NULL)
		return 0;
	else if (bstree_data(raiz) > data)
		bstree_contains(bstree_left(raiz), data);
	else if (bstree_data(raiz) < data)
		bstree_contains(bstree_right(raiz), data);
	else
		return 1;
}

int bstree_nelements(BSTree *raiz) {
	if (raiz == NULL) 
		return 0;
	else
		 return (1 + bstree_nelements(bstree_left(rraiz)) + bstree_nelements(bstree_right(raiz))); 
}

int bstree_height(BSTree *raiz) {
	if (raiz == NULL)
		return -1;
	else
		return (1 + MAX(bstree_height(bstree_left(raiz)),bstree_height(bstree_right(raiz))))
}


void  btree_foreach(BTree *node, VisitorFuncInt visit, void *extra_data) {
	if (node != NULL) {
		visit(btree_data(node), extra_data);
		btree_foreach(btree_left(node), visit, extra_data);
		btree_foreach(btree_right(node), visit, extra_data);
	}
}