#ifndef __BTREE_H__
#define __BTREE_H__

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))

typedef void (*VisitorFuncInt) (int data, void *extra_data);

typedef enum {
	BTREE_TRAVERSAL_ORDER_IN,
	BTREE_TRAVERSAL_ORDER_PRE,
	BTREE_TRAVERSAL_ORDER_POST
} BTreeTraversalOrder;

/**
 * Los campos son privados, y no deberian ser accedidos
 * desde el código cliente.
 */
typedef struct _BTNode {
	int    data;
	struct _BTNode *left;
	struct _BTNode *right;
} BTree;

#define btree_data(l)       (l)->data
#define btree_left(l)       (l)->left
#define btree_right(l)      (l)->right

/**
 * Crea un nuevo nodo, en complejidad O(1).
 *
 * Nota: el árbol vacio se representa con un (BTree *) NULL.
 */
BTree *btree_create(int data, BTree *left, BTree *right);

/**
 * Destruccion del árbol.
 */
void  btree_destroy(BTree *root);

/**
 * Recorrido del árbol, utilizando la funcion foreach
 */
void  btree_foreach(BTree *list, VisitorFuncInt visit, void *extra_data);

int btree_sum(BTree *root);

int btree_numnodos(BTree *root);

int btree_altura(BTree *root);

void btree_foreach2(BTree *node, VisitorFuncInt visit, BTreeTraversalOrder orden, void *extra_data);

void reemplazar_datos(BTree *raiz, int dato);

int btree_minimo_valor(BTree *raiz);

void hacer_bonsai(BTree *raiz);

BTree *fib(int nro);

#endif /* __BTREE_H__ */

