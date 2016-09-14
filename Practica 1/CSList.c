#include <CSList.h>

void cslist_foreach(CSList *list, VisitorFuncInt visit, DListTraversalOrder sentido, void *extra_data) {
	CSList *nodoaux = list;
    visit(cslist_data(nodoaux),extra_data);
    nodoaux = cslist_next(nodoaux);
    while (nodoaux != list){
		visit(cslist_data(nodoaux),extra_data);
        nodoaux = cslist_next(nodoaux);
    }
}