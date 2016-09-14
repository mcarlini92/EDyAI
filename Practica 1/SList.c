#include <stdlib.h> //Para malloc
#include <string.h> //Para la funcion strl
#include "SList.h"

SList *slist_append(SList *list, int data)
{
      SList *newNode = malloc(sizeof(SList));
      SList *node;
      slist_data(newNode) = data;
      slist_next(newNode) = NULL;
      if (list == NULL) {
         return newNode;
      }
      node = list;
      while (slist_next(node) != NULL) {
            node = slist_next(node);
      }
      /* ahora 'node' apunta al ultimo nodo en la lista */
      slist_next(node) = newNode;
      return list;
}

SList *slist_prepend(SList *list, int data)
{
      SList *newNode = malloc(sizeof(SList));
      slist_next(newNode) = list;
      slist_data(newNode) = data;
      return newNode;
}

void  slist_destroy(SList *list)
{
      SList *nodeToDelete;

      while (list != NULL) {
            nodeToDelete = list;
            list = slist_next(list);
            free(nodeToDelete);
      }
}

void  slist_foreach(SList *list, VisitorFuncInt visit, void *extra_data)
{
      SList *node = list;

      while (node != NULL) {
            visit(slist_data(node), extra_data);
            node = slist_next(node);
      }
}


// ----------------------EJERCICIOS-------------------
//Ej 2.1

int slist_has_next(Slist *nodo) {
	if ((nodo=NULL) || slist_next(nodo)==NULL)
		return 0;
	else 
		return 1;
}

//Ej 2.2

int slist_length(Slist *nodo) {
	Slist *nodoaux = nodo;
	int length = 0;
	while (slist_has_next(nodoaux)!=0) {
		lengt+=1;
		nodoaux=slist_next(nodoaux);
	}
	return length;
}

//Ej 2.3

SList *slist_concat(SList *lista1, SList *lista2) {
	Slist *nodoaux = lista1;
	if (lista2==NULL)
		return lista1;
	if (lista1==NULL)
		return lista2;
	while (slist_next(nodoaux) != NULL) {
		nodoaux=slist_next(nodoaux);
	}
	slist_next(nodoaux) = lista2;
	return lista1;
}

//Ej 2.4

void slist_insert(SList *lista, int posicion, int dato) {
	Slist *nodoaux = lista;
	SList *nuevonodo = malloc(sizeof(SList));
	int i = 0;
	if ((posicion>length(lista))) //Si la posicion es mayor a la cant de elementos de la lista, devuelvo la lista original
		return lista;
	slist_data(nuevonodo) = dato;
	if (posicion==length(lista) && (length(lista)>1)){ // Si quiero agregar el nuevo nodo al final de lista y la lista tiene mas de un elemento 
		while (slist_next(nodoaux) != NULL) {
			nodoaux = slist_next(nodoaux);
		}
		slist_next(nodoaux) = nuevonodo;
		slist_next(nuevonodo) = NULL;
	}
	
	if ((posicion-1)==0) // Si quiero agregar el nuevo nodo al principio de la lista
		slist_next(nuevonodo) = lista;	
	
	else { // Caso donde posicion esta ubicado de la sgte forma 1<posicion<length(lista)
		while (i<(posicion-1)) { //nodoaux va a ser el anterior nodo que va a tener el nuevo nodo que insertemos
			nodoaux = slist_next(nodoaux);
			i++;
		}	
		slist_next(nuevonodo) = slist_next(nodoaux);
 		slist_next(nodoaux) = nuevonodo;
	}
}

//Ej 2.5

void slist_remove(SList *lista, int posicion) {
	Slist *nodoaux = lista;
	int i = 0;
	int j = 0;
	if (posicion>length(lista)) //Si la posicion es mayor a la cant de elementos de la lista, devuelvo la lista original
		return lista;
	if (posicion==length(lista) && (length(lista)!=1) ){ // Si quiero eliminar el nodo final de la lista 
		while (j<(posicion-1)) { // nodoaux sera el penultimo nodo de la lista
			nodoaux = slist_next(nodoaux);
			j++;
		}
		free((slist_next(nodoaux))); //Si nodoaux era el penultimo, su siguiente era el nodo a eliminar en cuestion y asi libero memoria
		slist_next(nodoaux) = NULL;
		
	}
	
	if ((posicion-1)==0) // Si quiero borrar el primer nodo de la lista
		lista = slist_next(lista);	
		free(lista); // Como es el primero nodo, no tiene complicaciones
	else { // Caso donde posicion esta ubicado de la sgte forma 1<posicion<length(lista)
		while (i<(posicion-1)) { //nodoaux va a ser el anterior nodo al que vamos a eliminar
			nodoaux = slist_next(nodoaux);
			i++;
		}	
		slist_next(nodoaux) = slist_next(slist_next(nodoaux)); 
 		free(slist_next(nodoaux));
	}
}

//Ej 2.6

int slist_contains(Slist *lista, int nro) {
	Slist *nodoaux = lista;
	int i = 0,
	int aux = 0;
	while ((nodoaux!=NULL) && (aux==0)) {
		if (slist_data(lista)==nro)
			aux = 1;
		else
			nodoaux = slist_next(nodoaux);	
	}
	return aux;
}

//Ej 2.7
// Analizar caso en que hay dos nodos con la misma data
 
unsigned int slist_index(SList *lista, const int data) { // Devolverá 0 si no se encuentra en la lista , sino devolvera la pos del nodo en la lista
	Slist *nodoaux = lista;
	int cont = 1;
	int aux = 0;
	if (slist_contains(lista, data)==0) { // Si no se encuentra en la lista , no entra al bucle
		return 0;
	}
	while ((nodoaux!=NULL) && (aux==0)) {
		if (slist_data(lista)==data)
			aux = 1;
		else
			nodoaux = slist_next(nodoaux);
			cont++;
	}
	return cont; 
}

//Ej 2.8

Slist *slist_intersect(Slist *lista1, Slist *lista2) { 
	Slist *nvalista = NULL; // Aqui guardare los elementos en comun, lo inicializo apuntando a NULL
	Slist *nodoaux = lista1;
	int ind = 0;
	if ((lista1==NULL) || (lista2==NULL))
		return nvalista;
	while (nodoaux!=NULL) { // Me movere en la lista1, comparando cada nodo con todos de la lista2
		if (slist_cotains(lista2, (slist_data(nodoaux)))==1) { // Verifica si el dato sobre el nodo en el que estoy parado se encuentra en lista2
			slist_append(nvalista, slist_data(nodoaux)); // Agrego el elemento a nvlista con su data corresp, append se encarga de agreg al final y hacerlo apuntar a NULL
		}
		else // Si el dato no se encontraba en lista2, sigo con el prox nodo de lista1
			nodoaux = slist_next(nodoaux);
	}
	return nvalista;	
}

//Ej 2.10
//typedef int (*ComparaFunc) (SList *lista1) toma dos nodos consec y devuelve 1 si el primero es mas chico que el otro , caso contrario 0  
//Si su consecutivo es NULL , devuelve 1  

void slist_sort(SList *lista, ComparaFunc comp) { // Ordenamiento de nodos segun su dato, de menor a mayor
	Slist *nodoaux = lista;
	int aux;
	while (nodoaux!=NULL) { 
		if (comp(nodoaux)==0) { //Si encuentro dos nodos consec donde la datos del primero es mas grande que la del segundo, intercambio sus datos
			aux = slist_data(nodoaux);
			slist_data(nodoaux) = slist_data(slist_next(nodoaux));
			slist_data(slist_next(nodoaux)) = aux;
			nodoaux=lista; // Vuelvo a correr la funcion desde el principio
		}
		else
			nodoaux = slist_next(nodoaux);	
	}
}


















