#include <stdlib.h>#include "EStack.h"Node *stack_create() {	Node *pila = malloc(sizeof(Node));	node_next(pila) = NULL;	return pila;}int stack_top(Node *pila) {	if(pila != NULL)		return node_data(pila);	else		return 1/0;}Node *stack_push(Node *pila, int dato) {	Node *npila = malloc(sizeof(Node));	node_data(npila) = dato;	node_next(npila) = pila;	return npila;}Node *stack_pop(Node *pila){	Node *aux = pila	pila = node_next(pila);	free(aux);	return pila;}void stack_destroy(Node *pila){	Node *aux;	while(pila != NULL){		aux = pila;		pila = node_next(pila);		free(aux);		}}Node *stack_reverse(Node *pila){	Node *revpila = stack_create(), *aux;	while(pila != NULL){         		aux = pila;		revpila = stack_push(revpila,stack_top(pila));		pila = node_next(pila);		free(aux);       	}	return revpila;}int stack_leght(Node *pila){	int i = 0;		for(i=0; pila != NULL; i++)			pila = stack_next(pila);	return i;}void stack_print(Stack *pila){	int n = stack_lenght(pila);	int i = 0;	for (i=n; i >= 0 ; i--)		printf("%d ",stack_data(pila)[i]);}