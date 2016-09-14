#include <stdio.h>

int main () {
	char a[]="hola";
	printf ("Long de cadena: %d \n", longcad(a));
	system("PAUSE");
	return 0;
}

int longcad(char cadena[]) {
    int largo=0;
    while (cadena[largo]!='\0')
	largo++;
    return largo;
}