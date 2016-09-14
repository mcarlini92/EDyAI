#ifndef __STACK_H__
#define __STACK_H__

#define MAX_STACK 100

typedef struct _Stack{
	int data[MAX_STACK];
	int back;
} Stack;

#define stack_back(l)		(l)->back
#define stack_data(l)		(l)->data

Stack *stack_create();

int stack_top(Stack *pila);

Stack *stack_push(Stack *pila, int dato);

Stack *stack_pop(Stack *pila);

Stack *reverse(Stack *pila);

void stack_print(Stack *pila);

void stack_destroy(Stack *pila);


#endif /*__STACK_H__*/