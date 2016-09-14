#ifndef __BSORT_H__
#define __BSORT_H__

#include "Slist.h"

void swap(int *, int *);

void slist_swap(SList *, SList *);

SList *slist_getelement(SList *,int);

void swapg(void *, void *);

void bsort(int [], int);

void ssort(int data[], int);

void rssort(int data[], int);

void ssortl(Slist *root);

void isort(int x[], int sz);

void isortl(SList *);

typedef int (*CmpFunc)(void *, void *);

void bsortg(void *data, int sz,  CmpFunc mayor_a);

void ssortg(void *x, int n,  CmpFunc mayor_a);

void isort(void *x, int n, CmpFunc mayor_a);

void mayoramenor (void *x, void *sz);

enum PALO {ORO, ESPADA, BASTO, COPAS};

struct carta {
	enum PALO palo;
	int numero;
};

#endif /* __BSORT_H__ */
