#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hashtable.h"

int equals(void *key1, void *key2) { // Funcion para comparar key cuando estas son numeros
    int *p = key1;
    int *q = key2;

    return *p == *q;
}

int equals2(void *key1, void *key2) { // Funcion para comparar key cuando son char
    char *p = key1;
    char *q = key2;

    return (strcmp(p,q)==0);
}

unsigned int hash(void *key) { // Funcion hash , dividiendo por 10
    int *p = key;
    return *p % 10;
}

//R numero de cubetas
unsigned int hashnat(void *key,unsigned int R) { // Divido la key por el numero de cubetas
    int *p = key;
    return *p % R;
}

unsigned int hashmult(void *key,unsigned int R) {
    int *p = key;
    double A=0.6180339887;
    return (unsigned int)floor(R*((*p)*A - floor((*p)*A)));
}

unsigned int stringtonat(void *key, unsigned int R)
{
    int i=0;
    char * c = key;
    unsigned int sum=0;
    while (c[i]!='\0') {
        sum += c[i]*pow((double)256,(double)i);
        i++;
    }
    return hashmult(&sum,R);
}



int main(void) {
    char nombre1 [] = {'P','1','\0'};
    char nombre2 [] = {'P','2','\0'};
    char nombre3 [] = {'P','3','\0'};
    char nombre4 [] = {'P','1','\0'};

    int tel1=12345;
    int tel2=12346;
    int tel3=12347;
    int tel4=12348;

    int R = 10;

    Hashtable *ht = hashtable_new(R, stringtonat, equals2);

    hashtable_insert(ht, nombre1, &tel1);
    hashtable_insert(ht, nombre2, &tel2);
    hashtable_insert(ht, nombre3, &tel3);

    printf("Imprimo lista con 3 elementos: \n");
    hashtable_print(*ht);

    hashtable_insert(ht, nombre4, &tel4);

    printf("Imprimo lista con 3 elementos con un data cambiado: \n");
    hashtable_print(*ht);

    hashtable_delete(ht, nombre1);

    printf("Imprimo lista con 2 elementos: \n");
    hashtable_print(*ht);

    ht=hashtable_resize(ht);

    printf("Imprimo lista con 2 elementos pero con el doble de tamanio: \n");
    hashtable_print(*ht);

    hashtable_destroy(ht);

    return 0;
}
