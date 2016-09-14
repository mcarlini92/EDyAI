#include <stdlib.h>
#include <stdio.h>
#include "bsort.h"


void swap(int *p, int *q) {
  int t = *p;
  *p = *q;
  *q = t;
}

void slist_swap(SList *a, SList *b)
{
	int data= slist_data(a);
	slist_data(a) = slist_data(b);
	slist_data(b) = data;
	
}

SList *slist_getelement(SList *root,int index){
	int i= index;
	SList *node = root;
	while( node != NULL && i >0){
		node = slist_next(node);
		i--;			
	}
	return node;
}

void swapg(void *p, void *q) {
  void *t = p;
  p = q;
  q = t;
}

void bsort(int data[], int sz) {
	int sorted, i;
	do {
		sorted = 1;
		for (i = 0; i < sz - 1; i++)
			if (data[i] > data[i+1]) {
				sorted = 0;
				swap(&data[i], &data[i+1]);
			}
		} while (sorted != 1);
}


void ssort(int data[], int sz) {
	int i, j, min;
	for (i = 0; i < sz; i++) {
		min = i;
		for (j = i + 1; j < sz; j++) {
			if (data[j] < data[min])
				min = j;
		}
		swap(&data[i], &data[min]);
	}
}


void ssortl(Slist *root){
	int flag;
	Slist *min, *aux, *aux2;
	aux = root;
	while(aux!=NULL){
		min=aux;
		flag=0;
		aux2=slist_next(aux);
		while(aux2!=NULL){
			if(slist_data(min) > slist_data(aux2)){
				min=aux2;
				flag=1;			
			}
			if(flag)
				slist_swap(aux2, min);
			aux2=slist_next(aux2);
		}
		aux = slist_next(aux);
	}
}
	
void isort(int data[], int sz){
	int i, j;
	if(sz <= 1)
		return;
	for(i = 1 ; i < sz ; i++){
		j = i;
		while( j>0 && data[j] < data[j-1]){ // Si el elemento anterior es mayor, 
			swap(&data[j], &data[j-1]); // hago el swap
			j--; // y hago decrecer a j para verificar con los anteriores
		}
	}
}

void isortl(SList *root){
	SList *list = root;
	int i, j, sz;
	sz = slist_lenght(list);
	if(sz <= 1)
		return;
	for(i = 1 ; i < sz ; i++){
		j = i;
		while( j>0 && slist_data(slist_getelement(list,j)) < slist_data(slist_getelement(list,j - 1))){ // Si el elemento anterior es mayor, 
			slist_swap(slist_getelement(list,j),slist_getelement(list,j - 1)); //swap(&data[j], &data[j-1]);
			j--; // y hago decrecer a j para verificar con los anteriores		
		}
	}
}

void rssort(int data[], int sz) {
	int i, max = (sz-1);
	if (sz <= 1)
		return;
	for (i = 0; i < sz; i++) {
			if (data[max] < data[i])
				max = i;
		}
	swap(&data[sz], &data[max]);
	rssort(data, (sz-1));		
}

void bsort2(int data[], int sz) {
	int j, i, cota;
	cota = (((sz*sz)-sz)/2) // en el peor caso, el arreglo esta ordenado de mayor a menor y la cant de int que hay que hacer es (n^2-n)/2 
	for(j=0;j <= cota;j++)
		for (i = 0; i < sz - 1; i++)
			if(data[i] > data[i+1]) 
				swap(&data[i], &data[i+1]);
}

int es_permutacion(int *x, int *y, int zs){
	int i;
	rssort(x, sz);
	rssort(y, sz);
	for(i=0;i <= zs;i++)
		if(*(x+i) != *(y+i)) // x[i] != y[i] tambien seria valido
			return 0;
	return 1;
}


void bsortg(void *data, int sz, CmpFunc func){
  int sorted, i, j; 
  do {
    sorted = 1;
    for (i = 0; i < sz - 1; i++){
		if (func(data[i], data[i+1])){
			sorted = 0;
			swapg(data[i], data[i+1]);
		}
    }
	} while(sorted != 1);
}

void ssortg(void *data, int sz, CmpFunc func){
  int i, j, min;
	for (i = 0; i < sz; i++) {
		min = i;
		for (j = i + 1; j < sz; j++) {
			if (comparacion(data[min] , data[j]))
				min = j;
		}
		swapg(data[i], data[min]);
	}
}

void isortg(void *data, int sz, CmpFunc func){
	int i, j;
	if(sz <= 1)
		return;
	for(i = 1 ; i < sz ; i++){
		j = i;
		while( j>0 && func(data[j-1], data[j])){
			swapg(data[j], data[j-1]);
			j--;		
		}
	}
}