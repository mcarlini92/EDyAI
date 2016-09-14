#ifndef __BCTREE_H__
#define __BCTREE_H__

typedef struct _BCTree {
	int *data;
	int nelems;
} BCTree;

#define bctree_data(l)       (l)->data
#define bctree_nelems(l)     (l)->nelems

int potbase2(int exp);

int cantnodos(int nro);

BCTree *bctree_new (int nivel);

void bctree_destroy(BCTree *raiz);

BCTree *bctree_insert(BCTree *nodo, int data);

typedef void (*VisitorFuncInt) (int data, void *extra_data);

void  bctree_foreach(BCTree *raiz, VisitorFuncInt visit, void *extra_data);

#endif /* __BCTREE_H__ */
