#include <stdio.h>
#include <stdlib.h>
#include "EQueue.h"

qNode *queue_create(){
	qNode *q = (queue*) malloc(sizeof(queue));
	qnode_next(q) = NULL;
	return q;
}

int queue_front(qNode* nodo) {
	qNode *aux = nodo;
	if (q = NULL)
		return 1/0;
	else
		while(qnode_next(aux) != NULL) // aux terminara siendo el ultimo nodo 
			aux = qnode_next(aux);
	return (qnode_data(aux));
}

qNode *queue_enqueue(qNode *cola, int data) {
	qNode *Nnode = malloc(sizeof(qNode));
	qnode_data(Nnode) = data;
	qnode_next(Nnode) = NULL;
	if (cola == NULL)
		return Nnode;
	qnode_next(Nnode) = cola;
	return Nnode;
}

void queue_dequeue(qNode *nodo) {
	qNode *aux = nodo;
	if (nodo == NULL) 
		return 1/0;
	nodo = qnode_next(nodo)
	free(aux);
	return;
}

void queue_destroy(qNode *nodo) {
	qNode *aux = nodo;
	while (aux != NULL) {
		aux = qnode_next(nodo);
		free(nodo);
	}
	return;
}

void queue_printf(qNode *nodo) {
	qNode *aux = nodo;
	while( aux != NULL ) {
		printf("Data: %d",qnode_data(aux));
		aux = qnode_next(aux);
	}
}