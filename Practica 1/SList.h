#ifndef __SLIST_H__    //La estructura #ifndef - #define - #endif   permite evitar reinclusiones del archivo de encabezados.
#define __SLIST_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data); //VisitorFuncInt es el identificador de un puntero a función que recibe como argumentos (int data, void *extra_data) y devuelve void.
/**                                                          //SI SE BORRA EL ASTERISCO TMB FUNCA! OJO, VER QUE ESTÁ PASHANDO!!!
 * Los campos son privados, y no deberian ser accedidos
 * desde el codigo cliente.
 */
typedef struct _SList {                                // Renombro la estructura _SList {int data; struct_SList *next} como SList.
        int    data;
        struct _SList *next;
} SList;

#define slist_data(l)       (l)->data                  // Renombro (nodo)->data como slist_data(nodo)
#define slist_next(l)       (l)->next                  // Renombro (nodo)->next como slist_data(next)

/**
 * Agrega un elemento al final de la lista, en complejidad O(n).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
SList *slist_append(SList *list, int data);

/**
 * Agrega un elemento al inicio de la lista, en complejidad O(1).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
SList *slist_prepend(SList *list, int data);

/**
 * Destruccion de la lista.
 */
void  slist_destroy(SList *list);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void  slist_foreach(SList *list, VisitorFuncInt visit, void *extra_data);

//--------------COMIENZO LOS EJERCICIOS-----------------------

//Ejercicio 2.1 - crear slist_has_next que diga si hay un proximo nodo, devuelve 0 si no hay más nodos, o 1 en caso contrario.

int slist_has_next(SList *list);

//Ejercicio 2.2 - crear slist_length que devuelva un entero con la longitud de la lista.

int slist_length(SList *list);

//Ejercicio 2.3 - crear slist_concat que permita concatenar 2 listas.

SList *slist_concat(SList *lista1, SList *lista2);

//Ejercicio 2.4 - crear slist_insert que permita insertar un elemento en una posición arbitraria.

void slist_insert(SList *lista, int posicion, int dato);

//Ejercicio 2.5 - crear slist_remove que permita eliminar un elemento de una posición arbitraria.

void slist_remove(SList *lista, int posicion);

//Ejercicio 2.6 - crear slist_contains que diga si un elemento está en una lista

int slist_contains(Slist *lista, int nro);

//Ejercicio 2.7 - crear slist_index que diga en qué posición de la lista está el elemento está en una lista, si el mismo está en la lista.

unsigned int slist_index(SList *lista, const int dato);

//Ejercicio 2.8 - crear slist_intersect que contenga los elementos comunes de 2 listas.

SList * slist_intersect(SList *lista1, SList *lista2);

//Ejercicio 2.9 - Salteado

//Ejercicio 2.10 - crear slist_sort que ordene las listas en función de una función pasada por parametro que devuelva valores como strcmp()

typedef int (*ComparaFunc) (SList *a, SList *b); //Lo mejor hubiera sido generalizar usando:   typedef int (*ComparaFunc) (void *a, void *b) y lueg
                                                 //en la función de comparación castear los parámetros recibidos para q sean del tipo SList*  :(Slist *)punteroavoid;

void slist_sort(SList *lista, ComparaFunc comp);

#endif /* __SLIST_H__ */

