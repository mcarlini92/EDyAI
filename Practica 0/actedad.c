#include <stdio.h>
#include <stdlib.h>

typedef struct _Agenda {
	char nom[30]; 
	int  tel[15];
	unsigned int edad;
} Agenda;

Agenda *crearcontacto() {
	int i, n, aux;
	Agenda *contacto = malloc(50*sizeof(Agenda));
	printf("Numero de contactos a ingresar: "); scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Contacto nro. %d \n", i + 1);
		printf("Nombre: "); scanf("%s", contacto[i].nom);
		printf("Telefono: "); scanf("%s",contacto[i].tel);
		printf("Edad: "); scanf("%d", &aux);
		contacto[i].edad = aux;
		printf("\n");
	}
	return (contacto);
	free(contacto);
}

int longcad(char cadena[]) {
    int largo=0;
    while (cadena[largo]!='\0')
	largo++;
    return largo;
}

Agenda *actualizaredad(Agenda *contacto) {
	int aux, nedad;
	printf("Posicion: "); scanf("%d", &aux);
	printf("Nueva edad: "); scanf("%d", &nedad);
	contacto[aux-1].edad = nedad ;
	return contacto;
}

int main () {
	int i;
	Agenda *aux2;
	aux2 = crearcontacto();
	for(i=0;longcad((aux2+i)->nom)!=0;i++)
	printf("%d. Nombre: %s Telefono: %s Edad: %d \n", i+1, aux2[i].nom, aux2[i].tel, aux2[i].edad);
	printf("\n");
	aux2 = actualizaredad(aux2);
	for(i=0;longcad((aux2+i)->nom)!=0;i++)
	printf("%d. Nombre: %s Telefono: %s Edad: %d \n", i+1, aux2[i].nom, aux2[i].tel, aux2[i].edad);
	printf("\n");
	system("PAUSE");
	return 0;
}