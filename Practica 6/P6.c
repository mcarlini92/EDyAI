#include <stdio.h>
#include <stdlib.h>
#include "P6.h"
#include "BHeap.h"

#define hijoi(i) (2*(i)+1)
#define hijod(i) (2*(i)+2)
#define padre(i) (((i)-1)/2)

int cont_qsort = 0;

void swap(int *a, int *b){
     int c = *a;
     *a = *b;
     *b = c;
     return;  
}

int particionar(int data[], int init, int last) {
    int pivot = data[init], l = init, r = last;
    
    while (l < r) {
        while (data[l] <= pivot)
            l++;
		while (data[r] > pivot )
			r--;
			if (l < r)
				swap(&data[l], &data[r]);
    }
	swap(&data[init], &data[r]);
	return r;
}


void qsort2(int data[], int init, int last) {
    int pivot;
    if (init < last) {
        cont_qsort++;
        pivot = particionar(data, init, last);
        qsort2(data, init, pivot - 1);
        qsort2(data, pivot + 1, last);
    }
}

/*********************EJERCICIOS********************
1) NO, no es estable, porque las comparaciones se hacen con el pivot, son: 
data[l] <= pivot,  por lo que los elementos iguales entre sí se intercambiarán

2)*/int colocar(int *v, int b, int t)
    {
        int i;
        int pivote, valor_pivote;
        int temp;
 
        pivote = b;
        valor_pivote = v[pivote];
        for (i=b+1; i<=t; i++){
            if (v[i] < valor_pivote){
                    pivote++;    
                    temp=v[i];
                    v[i]=v[pivote];
                    v[pivote]=temp;
 
            }
        }
        temp=v[b];
        v[b]=v[pivote];
        v[pivote]=temp;
        return pivote;
    } 
/*3)
void qsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
Por lo tanto, la funcion de comparanción toma un puntero a void (el inicial del arreglo de punteros
a void), el número de elementos (num), la cantidad de bytes del tipo de elementos del arreglo (size),
y un puntero a una función de comparación que toma 2 punteros a void y devuelve un entero (1 si son
iguales, 0 sino).*/
//4)

int damepivote(int init, int last){
    return rand () % (last-init+1) + init;      
}

int particionar2(int data[], int init, int last) {
    int pivot, l = init, r = last;
    
    swap(&data[damepivote(init, last)], &data[init]);
    pivot = data[init];
    
    while (l < r) {
        while (data[l] <= pivot && l < r)
            l++;
                while (data[r] > pivot)
                r--;
                if (l < r)
                   swap(&data[l], &data[r]);
    }
swap(&data[init], &data[r]);
return r;
}

int particionar3(int data[], int init, int last) {
    int pivot, l = init, r = last;
    
    pivot = data[last];
    swap(&data[last], &data[init]);

    while (l < r) {
        while (data[l] <= pivot && l < r)
            l++;
                while (data[r] > pivot)
                r--;
                if (l < r)
                   swap(&data[l], &data[r]);
    }
swap(&data[init], &data[r]);
return r;
}

int particionar4(int data[], int init, int last) {
    int pivot, l = init, r = last;
    
    swap(&data[(init+last)/2], &data[init]);
    pivot = data[init];
        
    while (l < r) {
        while (data[l] <= pivot && l < r)
            l++;
                while (data[r] > pivot)
                r--;
                if (l < r)
                   swap(&data[l], &data[r]);
    }
swap(&data[init], &data[r]);
return r;
}

//para calcular el de la mediana, comparar el 1er elemento, el del medio y el último
//y en base a seleccionar el pivot, e intercambiarlo con el primero.
int particionar5(int data[], int init, int last) {
    int pivot, l = init, r = last;
    
    swap(&data[damepivote(init, last)], &data[init]);
    pivot = data[init];
        
    while (l < r) {
        while (data[l] <= pivot && l < r)
            l++;
                while (data[r] > pivot)
                r--;
                if (l < r)
                   swap(&data[l], &data[r]);
    }
swap(&data[init], &data[r]);
return r;
}
//

void qsort3(int data[], int init, int last, int tipopivote){
    int pivot;
    if (init < last) {
        switch(tipopivote){
        case 1:
               pivot = particionar2(data, init, last);
               break;
        case 2:
               pivot = particionar3(data, init, last);
               break;
        case 3:
               pivot = particionar4(data, init, last);
               break;
        case 4:                   
               pivot = particionar5(data, init, last);            
               break;
               
        default:
               qsort3(data, init, last, 1);     
        }
        cont_qsort++;    
        qsort3(data, init, pivot - 1, tipopivote);
        qsort3(data, pivot + 1, last, tipopivote);
    }     
}

// HEAPSORT!!! :D

int *heapsort(int data[], int sz){
    int i, *l = malloc(sizeof(int)*sz);
    BHeap *h = bheap_create();
    
    for (i = 0; i < sz; i++)
        h = bheap_insert(h, data[i]);
        
    i = 0;
    while (!bheap_is_empty(h)){
          l[i] = bheap_minimum(h);
          i++;
          h = bheap_erase_minimum(h);
    }
    bheap_destroy(h);
    
    return l;
}      

//heapify!
/*
ESTA FUNCION NO ANDA, ES UNA PORQUERIA!!
void heapify(int *arr, int size){
     int i = 0, flag = 0;// maxheap = 0;
     if (arr == NULL) return;
     
     while(i < size && flag == 0){
     if(i >= size-2){
          i = 0;
          flag = 1;
     }
     
     if(arr[padre(i)] >= arr[hijoi(i)] && arr[padre(i)] >= arr[hijod(i)]){
                 i++;
     }else if(arr[padre(i)] < arr[hijoi(i)]){
                 swap(&arr[padre(i)], &arr[hijoi(i)]);
                 flag = 0; 
     }else if(arr[padre(i)] < arr[hijod(i)]){
                 swap(&arr[padre(i)], &arr[hijod(i)]);
                 flag = 0; 
     }          
     }
}
*/ 

void heapify(int *arr, int size){
    int i, indice = 1;
    if (arr == NULL || size == 1)
		return;
      
    while(indice < size){
		i = indice;
		while(i > 0){
			if(arr[i] > arr[padre(i)]){
				swap(&arr[i],&arr[padre(i)]);
				i = padre(i);
			}
			else break;               
		}
		indice++;
	}
}
             
 
void hsort(int *arr, int size){
	int parteheap = 0;
               
	while(parteheap < size){
		//Swap;sift        
		heapify(arr, size-parteheap);
		swap(&arr[0],&arr[size-1-parteheap]);
		parteheap++;        
	}
}    
     
// La ventaja es que hsort ordena de manera in-situ