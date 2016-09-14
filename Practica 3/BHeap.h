#ifndef __BHEAP_H__
#define __BHEAP_H__

#define MAX_HEAP 10

struct _BHeap {
   int data[MAX_HEAP];
   int nelems;
};

typedef struct _BHeap BHeap;

BHeap *bheap_create();
int bheap_minimum(BHeap*);
BHeap *bheap_erase_minimum(BHeap*);
BHeap *bheap_insert(BHeap*, int);
void bhead_print(BHeap*);
void bheap_destroy(BHeap*);

#endif
