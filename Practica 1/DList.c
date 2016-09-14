#include <stdlib.h>
#include <Dlist.h>

// Hacer las funciones dlist_prepend y dlist_append

void dlist_foreach(DList *list, VisitorFuncInt visit, DListTraversalOrder sentido, void *extra_data) {
	Dlist *listinicio = list;
	if (sentido==DLIST_TRAVERSAL_ORDER_FORWARD)
		while (nodoaux != NULL) {
            visit(dlist_data(nodoaux), extra_data);
			nodoaux = dlist_next(nodoaux);
		}
	else {
		while (nodoaux != NULL) {
            visit(dlist_data(nodoaux), extra_data);
			nodoaux = dlist_next(nodoaux);
		}
		while (nodoaux != NULL) {
            visit(dlist_data(nodoaux), extra_data);
			nodoaux = dlist_prev(nodoaux);
		}	
	}
}