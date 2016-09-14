#include <stdlib.h>
#include "BTree.h"

BTree *btree_create(int data, BTree *left, BTree *right) {
	BTree *newNode = malloc(sizeof(BTree));
	btree_data(newNode) = data;
	btree_left(newNode) = left;
	btree_right(newNode) = right;
	return newNode;
}

void  btree_destroy(BTree *node) {
	if (node != NULL) {
		btree_destroy(btree_left(node));
		btree_destroy(btree_right(node));
		free(node);
	}
}

void  btree_foreach(BTree *node, VisitorFuncInt visit, void *extra_data) {
	if (node != NULL) {
		visit(btree_data(node), extra_data);
		btree_foreach(btree_left(node), visit, extra_data);
		btree_foreach(btree_right(node), visit, extra_data);
	}
}

// Ejercicio 2.1
int btree_sum(BTree *root) {
    if (root == NULL) 
		return 0;
    return (btree_data(root) + btree_sum(btree_left(root)) + btree_sum(btree_right(root)));
}

// Ejercicio 2.2
int btree_numnodos(BTree *root) {
    if (root == NULL) 
		return 0;
    return (1 + btree_numnodos(btree_left(root)) + btree_numnodos(btree_right(root)));   
}

// Ejercicio 2.3
int btree_altura(BTree *root) {
    int alturamax;
    if (root == NULL)
		return -1;
    alturamax = 1 + MAX(btree_altura(btree_left(root)),btree_altura(btree_right(root)));
		return alturamax;             
} 

// Ejercicio 3
void btree_foreach2(BTree *node, VisitorFuncInt visit, BTreeTraversalOrder orden, void *extra_data){
    if (node != NULL)
        switch(orden){
						case BTREE_TRAVERSAL_ORDER_IN:
                            btree_foreach2(btree_left(node), visit, orden, extra_data);
                            visit(btree_data(node), extra_data); 
                         	btree_foreach2(btree_right(node), visit, orden, extra_data);
							break;
                                
                        case BTREE_TRAVERSAL_ORDER_PRE:
                            visit(btree_data(node), extra_data);
                            btree_foreach2(btree_left(node), visit, orden, extra_data); 
                            btree_foreach2(btree_right(node), visit, orden, extra_data);                  
                            break;
                                
                        case BTREE_TRAVERSAL_ORDER_POST:
                            btree_foreach2(btree_left(node), visit, orden, extra_data); 
                            btree_foreach2(btree_right(node), visit, orden, extra_data);
                            visit(btree_data(node), extra_data);                               
                            break;
        }     
}

// Ejercicio 4
int btree_minimo_valor(BTree *raiz){
	if(raiz == NULL)
		return 1/0; //Para indicar error fatal, raiz nunca puede ser NULL 

    if (btree_left(raiz) == NULL && btree_right(raiz) == NULL)
			return btree_data(raiz);
       
	if (btree_left(raiz) == NULL && btree_right(raiz) != NULL)
		return MIN(btree_data(raiz), btree_minimo_valor(btree_right(raiz)));
       
	if (btree_right(raiz) == NULL && btree_left(raiz) != NULL)
		return MIN(btree_data(raiz), btree_minimo_valor(btree_left(raiz)));
       
	return MIN(btree_data(raiz), MIN(btree_minimo_valor(btree_left(raiz)), btree_minimo_valor(btree_right(raiz))));

}	


void reemplazar_datos(BTree *raiz, int dato){
	if (raiz != NULL) {
		btree_data(raiz) = dato;
		reemplazar_datos(btree_left(raiz), dato); 
		reemplazar_datos(btree_right(raiz), dato);
	}
}      
             
void hacer_bonsai(BTree *raiz){
    if (raiz == NULL) {
		printf("\n Error: Arbol Nulo\n");
		return;
	}
	reemplazar_datos(raiz, btree_minimo_valor(raiz));
}