#ifndef __P6_H__
#define __P6_H__



int particionar(int data[], int init, int last);

void qsort2(int data[], int init, int last);

int colocar(int *v, int b, int t);

int damepivote(int init, int last);

int particionar2(int data[], int init, int last);

int particionar3(int data[], int init, int last);

int particionar4(int data[], int init, int last);

int particionar5(int data[], int init, int last);

void qsort3(int data[], int init, int last, int tipopivote);

int *heapsort(int data[], int sz);

void heapify(int *arr, int size); //era lo mismo que declarar como int arr[], int size.

void hsort(int *arr, int size);


#endif /*__P6_H__*/
