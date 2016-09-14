#ifndef __EQUEUE_H__
#define __EQUEUE_H__

typedef struct _node { 
  int data; 
  struct _node *next;
} qNode; 

#define	qnode_data(l)		(1)->data
#define qnode_next(1)		(1)->next

qNode *queue_create(); 
int queue_front(qNode* nodo);
qNode *queue_enqueue(qNode *cola, int data);
void queue_dequeue(qNode *nodo);
void queue_print(qNode *nodo);
void queue_destroy(qNode *nodo);

#endif
