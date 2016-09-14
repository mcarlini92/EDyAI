#include <stdio.h>
#include <stdlib.h>

typedef struct {  // No se modificaran 
	static int nro;
	static int peso;
} Archivo;

/*
a)Sí, como se quiere maximizar el número de archivos a poder grabar en el disquete, ordenarlos de menor a mayor (forma creciente) nos permitiría almacenar la mayor cantidad de ficheros posibles
b) No, este algoritmo greedy no encontraría la solución óptima en todos los casos.

Ejemplo:
---------         
Archivos:         I-----------------I I-------I I---I I-I
Disco:            **************************

La solución óptima sería, ordenándolos de mayor a menor, incluirlos sucesivamente y si alguno no puede ser incluido,
continuar con su inmediato siguiente, así hasta llegar al archivo más pequeño.

*/

int CmpFunc(const void *p, const void *q) { 
	Archivo *fst = (Archivo *)p;
	Archivo *snd = (Archivo *)q;
	if(fst->peso < snd->peso)
		return 1;
	else if(fst->peso == snd->peso)
		return 0;
	else
		return -1;	
}

void solve(Archivo *prt, int szF, int szD){ // ptr = predisquet , szF = cantidad de archivos, szD = capacidad del disquet , szT = espacio actual ocupado
	int i, j, szT = 0;
	Archivo *disquet;
	disquet = malloc(szD * sizeof(Archivo));
	qsort(ptr, szF, sizeof(Archivo), CmpFunc);
	
	for(i=0; i < szF && szT+(ptr[i].peso) <= szD; i++){
		disquet[i] = prt[i];
		szT+=ptr[i].peso
	}	
	for(j=0; j < szD; j++)
		printf("Archivos guardados: %d ",ptro[j].nro)
	printf("Total archivos guardados: %d\nEspacio total ocupado: %d",i, szT);
}

int main(void) {
	int szF, szD, i;
	Objeto *predisquet;
	scanf("Cantidad archivos %d", &szF);
	scanf("Espacio del disquet (entero>0) %d", &szD);
	predisquet = malloc(szF * sizeof(Archivo));
	for (i = 0; i < szF; i++){ 
		scanf("Peso %d",&predisquet[i].peso);
		predisquet[i].nro = i;
	}
	solve(predisquet, szF, szD);
	return 0;
}

// Otra opcion es la de luego de realizar qsort, contar szD elementos y borrar los demas (?)