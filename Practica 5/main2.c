#include <stdio.h>
#include "bsort.h"

#define NELEMS(a) (sizeof((a))/sizeof(int))

int mayor_a(void *ptro1 , void *ptro2){
	if ((int)*ptro1 > (int)*ptro2 )
		return 1;
	else
		return 0;
}

int menor_a(void *ptro1 , void *ptro2){
	if ((int)*ptro1 < (int)*ptro2 )
		return 1;
	else
		return 0;
}



int main(void) {
	int arr[] = { 2, 4, 1, 3, 7, 8, 6 };
	int x[] = { 1, 4, -2 , -3 };
	int i;
	bsortg(arr, NELEMS(arr), mayor_a);
	bsortg(x, NELEMS(x), menor_a)
	for (i  = 0; i < NELEMS(arr); i++)
		printf("%d ", arr[i]);
	puts("");
	return 0;
}
