#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

Hashtable *hashtable_new(int size, HashFunc hash, EqualsFunc efunc) {
	unsigned int idx;
	Hashtable *ht = malloc(sizeof(Hashtable)); // Reservo memoria para mi tabla hash 
	ht->hash = hash; // Asigno la funcion hash que viene como argumento
	ht->efunc = efunc; // Asigno la funcion para comparar que viene como argumento
	ht->size = size; // Asigno el tamaño de la tabla que viene como argumento
	ht->table = malloc(sizeof(Hashbucket * )*size); // Reservo espacio para las cubetas en relacion al tamaño (size) que viene como argumento
	ht->nelems = 0; // Declaro que no hay elementos en la tabla
	for (idx = 0; idx < size; idx++) 
		ht->table [idx]= NULL; // Lleno las cubetas creadas con NULL, o sea, estan vacias 
	return ht;
}

void hashtable_insert(Hashtable *ht, void *key, void *data) {
  unsigned int idx = ht->hash(key,ht->size); // idx contiene el valor de la funcion hash con los argumentos (key, size), o sea, la posic de la cubeta a la que corresp.
  Hashbucket * node= ht->table[idx]; // Creo un puntero a cubeta y hago que apunte a la cubeta segun su key

	while(node!=NULL) { // Me muevo por los nodos de la cubeta
		if(ht->efunc(node->key,key)) { // Busco si ya existe la key de la data que quiero ingresar
			node->data=data; // Si existe, sobre-escribo la data vieja con la nueva data 
			break;
		}
	else node=node->next; // Avanzo al siguiente nodo de la cubeta
}

	if(node==NULL) { // Si no existe la clave(key) de mi data a ingresar
		Hashbucket* hb = malloc(sizeof(Hashbucket)); // Creo un nuevo nodo
		hb->key=key; // Le doy la key del elemento a ingresar
		hb->data=data; // Le ingreso la data 
		hb->next=ht->table[idx]; // Agrego mi nuevo nodo a la lista de nodo que tienen la misma key luego de pasar por la funcion hash 
		ht->table[idx]=hb;// Meto mi nueva cubeta en la posicion corresp segun el valor de su key pasada por la funcion hash
		ht->nelems++; // Suma uno al contador de cubetas de la estructura hashtable 
	}
}

void *hashtable_lookup(Hashtable *ht, void *key) {
	unsigned int idx = ht->hash(key,ht->size); // idx contiene el valor de la funcion hash con los argumentos (key, size), o sea, la posic de la cubeta a la que corresp.

	Hashbucket * node =ht->table[idx]; // Creo un nuevo nodo haciedo que apunte a la cubeta corresp con la key del argumento 

	while (node!=NULL) {
		if(ht->efunc(node->key,key)) // Comparo las key de la tabla hash con la key del argumento para saber si esta ultima ya existe 
			return node->data; // Si existe ya en mi tabla hash, devuelvo la data correspondiente a la key 
		else
			node=node->next; // Me muevo por los nodos de la cubeta
	}
	return NULL;
}


void hashtable_delete(Hashtable *ht, void *key) {
	unsigned int idx = ht->hash(key,ht->size); // idx contiene el valor de la funcion hash con los argumentos (key, size), o sea, la posic de la cubeta a la que corresp.

	if (ht->table[idx]!= NULL) { // Si la cubeta no esta vacia, o sea, si el primer nodo de la cubeta es diferente de NULL
		Hashbucket * node =ht->table[idx]; // Creo un puntero apunte a la cubeta corresp segun la key dada y con el me ire moviendo por los elementos de la cubeta corresp
		if(ht->efunc(node->key,key)) { // Comparo la key del primer nodo con la key del argumento
			ht->table[idx]=ht->table[idx]->next; // Si son iguales, hago que el primer elem del la cubeta sea el siguiente al nodo que voy a borrar 
			free(node); // Y borro el nodo que tiene la la key que buscaba 
			ht->nelems--; // Resto uno al contado de elementos de la hashtable
		}
		Hashbucket * node2=node->next; // Crea un nuevo nodo y apunte al siguiente de node 
		while(node2!=NULL) {
			if(ht->efunc(node2->key,key)) {
				node->next=node2->next;
				free(node2);
				ht->nelems--;
			}
			node=node->next;
			node2=node2->next;
		}
	}

}

void hashtable_destroy(Hashtable *ht) {
    Hashbucket * node; // Nodo con el que me voy a ir moviendo por las cubetas
    int i;

    for(i=0 ; i< ht->size ; i++ ) { // bucle desde la primera cubeta hastas la ultima (size)
        node=ht->table[i]; // Hago que el nodo apunte a la cubeta segun el valor de i
        while(ht->table[i]!=NULL) { // Si la cubeta no esta vacia
            ht->table[i]=ht->table[i]->next; // Hago que el segundo nodo de la cubeta sea el primero
            free(node); // Borro el que era el primero
            node=ht->table[i]; // Me muevo a la siguiente cubeta 
        }
    }
    free(ht->table); // Libera el espacio reservado para las cubetas
    free(ht); // Libera el espacio reservado para la tabla hash
}

// Entro a la cubeta 1 , si no esta vacia, borro el primer elemento y me voy a la dos , si no esta vacia , borro el primer elemento y me voy a la siguiente ... repite el proceso hastas que todas las cubetas sean NULL, o sea, no tenga elementos

Hashtable * hashtable_resize(Hashtable * ht){
	unsigned int idx;
    Hashtable *ht2 = malloc(sizeof(Hashtable)); // Defino ht2 , puntero a la nueva hash table
    ht2->hash = ht->hash; // Le paso la funcion hash de ht a la nueva hash table (ht2)
    ht2->efunc = ht->efunc; // Le paso la funcion de comparar keys de ht a la nueva hash table (ht2)
    ht2->size = 2*(ht->size); // Le paso el tamaño duplicado de la ht a la ht2 
    ht2->table = malloc((ht2->size)*sizeof(Hashbucket)); // Reservo espacio para las cuebetas de ht2 
    ht2->nelems = 0; // Cantidad de elementos de la ht2 seteada en 0
	
    for (idx = 0; idx < ht2->size; idx++) // Me mueve por las cubetas de ht2
        ht2->table [idx] = NULL; // Como estas vacias, las seteo como NULL
		
    for (idx=0; idx <ht->size;idx++){ // Voy a pasar los elementos de las cubetas de ht a ht2
        if(ht->table[idx]!=NULL) { // Si la cubeta de ht es diferente de vacio
            Hashbucket * node = ht->table[idx]; // node apunta al primer elemento de la cubeta segun el valor de idx
            while(node!=NULL) { // Me muevo por los nodos de la cubeta en la que estoy 
                hashtable_insert(ht2,node->key,node->data); // Voy agregando los nodos a la nueva hash table (ht2)
                node=node->next; // Me mueve al siguiente nodo de la cubeta de ht
            }
        }
    }
    hashtable_destroy(ht); // Libero la memoria reservada para ht , pues ya no me sirve mas puesto que ya pase todos sus elementos a ht2
    return ht2;
}

void hashtable_print(Hashtable *ht)
{
    int i;
    printf("Hashtable:\n");

    for(i=0; i< ht->size; i++) {
        printf(" Cubeta %d: \n",i);
        Hashbucket *node =ht->table[i]; // Me situo en la cubeta i-esima de la tabla hash
        if(node ==NULL) // Si la cubeta esta vacia
			printf("\t Cubeta vacia \n");
        while(node!=NULL) { // Sino esta vacia 
            printf("\t\tkey = %s , data = %d\n",(char *)node->key,*((int *)node->data)); // Imprimo sus elementos
            node=node->next; // Paso al siguiente nodo de la cubeta
        }
    }
    printf("\n"); // Imprimo salto de linea , wipu 
}


