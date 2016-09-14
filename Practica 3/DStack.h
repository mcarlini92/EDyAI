#ifndef __DSTACK_H__
#define __DSTACK_H__

typedef struct _Stack{ 
	int *data;
	int n; // Reservado
	int back; // Utilizado
} DStack;

#define dstack_data(l)		(l)->data		
#define	dstack_n(l)			(l)->n
#define	dstack_back(l)		(l)->back

//---------------------------------------------------------------------------

DStack *dstack_create();

int dstack_top(DStack *pila);

DStack *dstack_push(DStack *pila, int dato);

DStack *dstack_pop(DStack *pila);

DStack *dstack_reverse(DStack *pila);

void dstack_print(DStack *pila);

void dstack_destroy(DStack *pila);

#endif /*__DSTACK_H__*/
