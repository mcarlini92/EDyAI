#include "BHeap.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	BHeap *heap = bheap_create();

	heap = bheap_insert(heap, 9);
	heap = bheap_insert(heap, 7);
	heap = bheap_insert(heap, 2);
	heap = bheap_insert(heap, 5);
	heap = bheap_insert(heap, 4);
	heap = bheap_insert(heap, 1);
	heap = bheap_insert(heap, 1);

	printf("Heap: ");
	bheap_print(heap);

	printf("Minimo: %d\n", bheap_minimum(heap));
	
	heap = bheap_erase_minimum(heap);

	printf("Minimo: %d\n", bheap_minimum(heap));
	
	heap = bheap_erase_minimum(heap);

	printf("Minimo: %d\n", bheap_minimum(heap));

	printf("Heap: ");
	bheap_print(heap);

	heap = bheap_erase_minimum(heap);

	printf("Minimo: %d\n", bheap_minimum(heap));

	heap = bheap_erase_minimum(heap);

	printf("Minimo: %d\n", bheap_minimum(heap));

	bheap_destroy(heap);

	return 0;
}
