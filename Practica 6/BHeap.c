#include "BHeap.h"
#include <stdlib.h>
#include <stdio.h>

#define hijoi(i) (2*(i)+1)
#define hijod(i) (2*(i)+2)
#define padre(i) (((i)-1)/2)

#define nelems(h) (h)->nelems
#define data(h, i) (h)->data[i]

BHeap *bheap_create() {
	BHeap *ret = malloc(sizeof(BHeap));

	nelems(ret)=0;
	return ret;
}

int bheap_minimum(BHeap *heap) {
	if(nelems(heap) == 0) {
		printf("error: heap vacio\n");
		return -1;
	} else
		return data(heap,0);
}

BHeap *bheap_erase_minimum(BHeap *heap) {
	int i;

	/* si ya estaba vacio */
	if(nelems(heap) == 0)
		return heap;

	/* subo el ultimo elemento */
	data(heap,0) = data(heap, nelems(heap) - 1);
	nelems(heap)--;

	/* hundir */
	i = 0;
	while(hijoi(i) < nelems(heap)) {
		int minpos = i;
		
		if(data(heap, hijoi(i)) < data(heap, minpos))
			minpos = hijoi(i);

		if(2*i + 2 < nelems(heap))
			if(data(heap, hijod(i)) < data(heap, minpos))
				minpos = hijod(i);

		if(minpos != i) {
			int t;
			t = data(heap, i);
			data(heap, i) = data(heap, minpos);
			data(heap, minpos) = t;
			i = minpos;
		} else
			break;
	}

	return heap;
}

BHeap *bheap_erase_minimum2(BHeap *heap) {
	int i;

	/* si ya estaba vacio */
	if(nelems(heap) == 0)
		return heap;

	/* subo el ultimo elemento */
	data(heap,0) = data(heap, nelems(heap) - 1);
	nelems(heap)--;

	/* hundir */
	i = 0;
	while(hijoi(i) < nelems(heap)) {
		int minpos = i;
		
		if(data(heap, hijoi(i)) > data(heap, minpos))
			minpos = hijoi(i);

		if(2*i + 2 < nelems(heap))
			if(data(heap, hijod(i)) > data(heap, minpos))
				minpos = hijod(i);

		if(minpos != i) {
			int t;
			t = data(heap, i);
			data(heap, i) = data(heap, minpos);
			data(heap, minpos) = t;
			i = minpos;
		} else
			break;
	}

	return heap;
}


BHeap *bheap_insert(BHeap *heap, int data) {
	int i;
	
	/* si ya esta lleno */
	if (nelems(heap) == MAX_HEAP)
	{
		printf("error: heap lleno\n");
		return heap;	
	}
	
	/* agrego al final */
	data(heap,nelems(heap)) = data;
	nelems(heap)++;

	/* flotar */
	i = nelems(heap) - 1;
	while(i != 0 && data(heap,padre(i)) > data(heap, i)) {
		int t;
		t = data(heap, i);
		data(heap, i) = data(heap,padre(i));
		data(heap, padre(i)) = t;
		i = padre(i);
	}

	return heap;
}

BHeap *bheap_insert2(BHeap *heap, int data) {
	int i;
	
	/* si ya esta lleno */
	if (nelems(heap) == MAX_HEAP)
	{
		printf("error: heap lleno\n");
		return heap;	
	}
	
	/* agrego al final */
	data(heap,nelems(heap)) = data;
	nelems(heap)++;

	/* flotar */
	i = nelems(heap) - 1;
	while(i != 0 && data(heap,padre(i)) < data(heap, i)) {
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

int bheap_is_empty(BHeap *arbolito){
    if (arbolito == NULL)
                 return 1/0;                
    return !(arbolito->nelems); 
} 

