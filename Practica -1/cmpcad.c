#include <stdio.h>

int main () {
	char cad1[]="holaS";
	char cad2[]="hola";
	printf ("Resultado: %d \n", cmpstr(cad1,cad2));
	system("pause");
	return 0;
}

int longcad(char cadena[]) {
    int largo=0;
    while (cadena[largo]!='\0')
	largo++;
    return largo;
}

int cmpstr (char cad1[], char cad2[]) {
	int i;
	int res= 1;
	int a= longcad(cad1);
	int b= longcad(cad2);
	if (a !=b)
		res= 0;
	for (i=0; (cad1[i]!='\0') && (cad2[i]!='\0') && (res== 1); i++) {
		if (cad1[i]!=cad2[i]) {
			res= 0;
		}
	}
	return res;
}