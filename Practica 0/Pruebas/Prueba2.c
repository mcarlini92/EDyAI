#include <stdio.h>
#include <stdlib.h>

struct contacto {
	char nom[100];
	int tel[100];
	unsigned int edad;
};

int main () {
	struct contacto agenda[4]={{"NombreUno",{0,3,4,5},15},{"NombreDos",{0,3,4,4},17}};
	printf("Nombre %s , Tel %n , Edad %d",agenda[0].nom, agenda[0].tel, agenda[0].edad);
	system("PAUSE");
	return 0;
}