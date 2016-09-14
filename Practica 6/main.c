#include <stdio.h>
#include <stdlib.h>
#include "P6.h"
#include "BHeap.h"

extern int cont_qsort;
       
int main(){
    int arreglo[] = { 1, 2, 3, 4, 5, 6 };
//    int arreglo[] = {5,7,9,1,3,46,2,8,12};
    int arreglo2[] = { 1, 2, 3, 4, 5, 6 }; //{11,3,9,41,5,7,15,18,12,-1,6};
    int arreglo3[] = { 1, 2, 3, 4, 5, 6 }; //{11,3,9,41,5,7,15,18,12,-1,6};
    int arreglo4[] = { 1, 2, 3, 4, 5, 6 }; //{11,3,9,41,5,7,15,18,12,-1,6};
    int arreglo5[] = {1,9,54,32,-7,5,7,64,11,42};
    int arreglo6[] = {1,9,54,32,-7,5,7,64,11,42};
    
    int i, nelems = (sizeof(arreglo)/sizeof(int)), nelems2 = (sizeof(arreglo2)/sizeof(int));
    int nelems5 = (sizeof(arreglo5)/sizeof(int)),  nelems6 = (sizeof(arreglo6)/sizeof(int)), *arreglonuevo;
    qsort2(arreglo,0,nelems-1);
    
    for(i = 0; i<nelems; i++)
          printf("%d ",arreglo[i]);
       
    printf("El numero de llamadas a qsort (pivote: inicial) fue: %d \n \n", cont_qsort);
    
    //---------------------------------------------------------------
    cont_qsort = 0;
    qsort3(arreglo2,0,nelems2-1,1);
    
    for(i = 0; i<nelems2; i++)
          printf("%d ",arreglo2[i]);
       
    printf("El numero de llamadas a qsort (pivote: random) fue: %d \n \n", cont_qsort);
  
    //---------------------------------------------------------------
    cont_qsort = 0;
    qsort3(arreglo3,0,nelems2-1,2);
    
    for(i = 0; i<nelems2; i++)
          printf("%d ",arreglo3[i]);
       
    printf("El numero de llamadas a qsort (pivote: final) fue: %d \n \n", cont_qsort);
    
    //---------------------------------------------------------------
    cont_qsort = 0;
    qsort3(arreglo4,0,nelems2-1,3);
    
    for(i = 0; i<nelems2; i++)
          printf("%d ",arreglo4[i]);
       
    printf("El numero de llamadas a qsort (pivote: del medio) fue: %d \n \n", cont_qsort);
    
    //---------------------------------------------------------------
  //  cont_qsort = 0;
    printf("Aplicando heapsort a un arreglo desordenado: \n");
    arreglonuevo = heapsort(arreglo5, nelems5); //heapsort no recibe la posición final, sino el nº de elementos
    
    for(i = 0; i<nelems5; i++)
          printf("%d ",arreglonuevo[i]);
    printf("\n");
       
  //  printf("El numero de llamadas a heapsort (pivote: del medio) fue: %d \n \n", cont_qsort);
     //---------------------------------------------------------------
        printf("Aplicando heapify y swapsift a un arreglo desordenado: \n");
    //heapify(arreglo6, nelems6); //heapsort no recibe la posición final, sino el nº de elementos
    swapsift(arreglo6, nelems6);
    
    for(i = 0; i<nelems6; i++)
          printf("%d ",arreglo6[i]);
    printf("\n");
       
  //  printf("El numero de llamadas a heapsort (pivote: del medio) fue: %d \n \n", cont_qsort);
    
       
       
    printf("\n");
    system("pause");
    return 0;
}
