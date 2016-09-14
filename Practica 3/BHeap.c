#include "BHeap.h"
#include <stdlib.h>
#include <stdio.h>

#define hijoi(i) (2*(i)+1)
#define hijod(i) (2*(i)+2)
#define padre(i) (((i)-1)/2)

#define nelems(h) 	(h)->nelems
#define data(h, i) 	(h)->data[i]

BHeap *bheap_create() {
	BHeap *ret = malloc(sizeof(BHeap));
	nelems(ret)=0;
	return ret;
}

int bheap_minimum(BHeap *heap) {
	if(nelems(heap) == 0) {
		printf("Error: heap vacio \n");
		return -1;
	}
	else
		return data(heap,0);
}

BHeap *bheap_erase_minimum(BHeap *heap) {
	int i;

	/* si ya estaba vacio */
	if(nelems(heap) == 0)
		return heap;

	/* subo el ultimo elemento */
	data(heap,0) = data(heap, nelems(heap) - 1);
	nelems(heap)--; // Disminuyo el tamaño del heap 

	/* hundir */
	
	int minpos = 0; // Posicion del minimo
	int exminpos = 0; // Posisicion del ex-minimo
	while(hijoi(minpos) < nelems(heap)) {	// Se fija si minpos tiene hijos , controlando que estos esten dentro la cant de elementos 
											// Como es un arb completo, la prioridad la tiene el hijo izq					
		int aux = 0;	// Si aux deja de ser 0, significara que se realizo un cambio 

		if(data(heap, hijoi(minpos)) < data(heap, minpos)) { 	// Controla si el hijo izq es menor que el padre para marcarlo como el min y dsp hacer el inter
			aux = 1;
			minpos = hijoi(minpos);
			exminpos = minpos;
		}
		else if(hijod(minpos) < nelems(heap)) // Idem hijoi(minpos) nada mas que con el hijo derecho
			if(data(heap, hijod(minpos)) < data(heap, minpos)) { // Controla si el hijo derecho es menor que el padre para marcarlo como el min y dsp hacer el inter
				aux = 1;
				minpos = hijod(minpos);
				exminpos = minpos;
			}
		else if(aux != 0) { // Si aux es diferente de 0, es porque tengo que realizar un intercambio entre un nodo padre y su hijo
			int t;
			t = data(heap,exminpos);
			data(heap, exminpos) = data(heap, minpos);
			data(heap, minpos) = t;
		}
		else
			break;
	}

	return heap;
}

BHeap *bheap_insert(BHeap *heap, int data) {
	int i;
	/* si ya esta lleno */
	if (nelems(heap) == MAX_HEAP) {
		printf("Error: heap lleno \n");
		return heap;	
	}
	/* agrego al final */
	data(heap,nelems(heap)) = data;
	nelems(heap)++;
	/* flotar */
	i = nelems(heap) - 1;
	while(i != 0 && data(heap, padre(i)) > data(heap, i)) {
		int t;
		t = data(heap, i);
		data(heap, i) = data(heap,padre(i));
		data(heap, padre(i)) = t;
		i = padre(i);
	}
	return heap;
}

void bheap_print(BHeap *heap) {
	int i;
	for(i = 0; i < nelems(heap); ++i)
		printf("%d ", data(heap, i));
	printf("\n");
}

void bheap_destroy(BHeap *heap) {
	free(heap);
}

