#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include "heap.h"

#define CANT 1000
#define SIZE_THRESHOLD 5 //mínimo tamaño de arreglo sobre el que trabaja introsort. Cuando sea más chico lo agarra el insertion sort
int calls;

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

void isort(int data[], int sz){
	int mess,i;
	for(mess=1;mess<sz;mess++)
		for(i=mess-1,calls++;i>=0 && data[i]>data[i+1];i--){
			calls++;
			swap(&data[i],&data[i+1]);
		}
}

int particionar(int data[],int init,int last){ //versión median-of-3
	if(init==last)
		return init;

	if(data[last]<=data[init] && data[(int)((last+init)/2)]<=data[last]){
		calls++;
		swap(&data[init],&data[last]);
	}
	else if(data[last]<=data[(int)((last+init)/2)] && data[(int)((last+init)/2)]<=data[last]){
		swap(&data[init],&data[(int)((last+init)/2)]);
		calls++;
	}

	int i=init+1, j=last, ppos=init;
	while(i<=j)
		if(data[i]<=data[ppos]){
			calls++;
			swap(&data[i],&data[ppos]);
			ppos=i;
			i++;
		}
		else{
			calls++;
			swap(&data[i],&data[j]);
			j--;
		}
	return ppos;
}

void qsort_(int data[],int init,int last){
	if(init>=last)
		return;
	int p=particionar(data,init,last);
	qsort_(data,init,p-1);
	qsort_(data,p+1,last);
}

void heapify(int* data,int sz){ //acomoda un arreglo de int dejándolo como un maxheap.
	int i,j,soytupadre;
	for(i=1;i<sz;i++){ //empiezo tomando el primer elemento como un heap, y voy agregando los demás manteniendo la primer parte del arreglo como heap.
		j=i;
		soytupadre=(int)((j-1)/2);
		while(soytupadre>=0 && j > 0 && data[soytupadre]<data[j]){ // agrego un elemento al heap como último y lo floto!!
			calls++;
			swap(&data[j],&data[soytupadre]);
			j=soytupadre;
			soytupadre=(int)((j-1)/2);
		}
	}
}

void swapsift(int *data,int sz){ //ordena de menor a mayor un arreglo que estaba como maxheap.
	int i;
	for(i=sz-1;i>0;i--){
		calls++;
		swap(&data[0],&data[i]); //cambio el primer elemento (el mayor) con el último.
		heapify(data,i); //quiero que el subarreglo desde el 0 hasta el penúltimo siga siendo maxheap.
	}
}

void hsort(int *data,int sz){
	heapify(data,sz);
	swapsift(data,sz);
}

void introsort_(int *data,int init,int last,int depth_limit){
	int p;
	while(last-init > SIZE_THRESHOLD){
		if(0==depth_limit){
			hsort(&data[init],last-init+1);
			return;
		}
		depth_limit--;
		p=particionar(data,init,last);
		introsort_(data,p,last,depth_limit);
		last=p;
	}
}

void introsort(int *data,int init,int last){
	int depth_limit=2*floor(log(last-init+1)/log(2)); //empíricamente (mágicamente) se toma este valor
	introsort_(data,init,last,depth_limit);
	isort(&data[init],last-init+1);
}


int main(){
	srand(time(NULL));
	int *data=malloc(CANT*sizeof(int)),*d2=malloc(CANT*sizeof(int)),*d3=malloc(CANT*sizeof(int)),*d4=malloc(CANT*sizeof(int)),*d5=malloc(CANT*sizeof(int)),*d6=malloc(CANT*sizeof(int)),f,r,i;
	for(f=0;f<CANT;f++){
		r=rand()%10000;
		data[f]=r;
		d2[f]=r;
		d3[f]=r;
		d4[f]=1000-f;
	}

	for(i=0;i<CANT;i++)
		printf("%2d ",d4[i]);
	printf("  <- sin ordenar\n\n\n");

	calls=0;
	introsort(data,0,CANT-1);
	for(i=0;i<CANT;i++)
		printf("%2d ",data[i]);
	printf("  <- introsort. Llamadas: %d.\n\n",calls);

	calls=0;
	qsort_(d2,0,CANT-1);
	for(i=0;i<CANT;i++)
		printf("%2d ",d2[i]);
	printf("  <- qsort_. Llamadas: %d.\n",calls);
}
