#ifndef __BTREE_H__
#define __BTREE_H__

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))

typedef void (*VisitorFuncInt) (int data, void *extra_data);

/**
 * Los campos son privados, y no deberian ser accedidos
 * desde el código cliente.
 */
typedef struct _BSTNode {
	int    data;
	struct _BSTNode *left;
	struct _BSTNode *right;
} BSTree;

#define bstree_data(l)       (l)->data
#define bstree_left(l)       (l)->left
#define bstree_right(l)      (l)->right

BSTree *bstree_insert(BSTree *raiz, int data);

int bstree_contains(BSTree *, int data);

int bstree_nelements(BSTree *raiz);

int bstree_height(BSTree *raiz);

void  btree_foreach(BTree *node, VisitorFuncInt visit, void *extra_data);


#endif /* __BTREE_H__ */

