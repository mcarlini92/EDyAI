# include <stdio.h>
# include <string.h>

# define CONST 100

typedef struct {
char pregunta[CONST];
char a[CONST];
char b[CONST];
char c[CONST];
char temp;
} Arreglo;

Arreglo A[1000];

main(){
int n, x, y;
FILE *pout;
printf("Dame el numero de elementos que quieras ingresar: ");
scanf("%d", &n);
for( x = 0; x < n; x++){
printf("Ingresando elemento %d\n", x + 1);
printf("Dame pregunta: \n"); scanf("%s", A[ x ].pregunta);
printf("Dame a: \n"); scanf("%s", A[ x ].a);
printf("Dame b: \n"); scanf("%s", A[ x ].b);
printf("Dame c: \n"); scanf("%s", A[ x ].c);
printf("Dame un caracter (diferente de espacio ' ' y de '\\n' ): \n"); scanf(" %c", &A[ x ].temp);
}

/* Imprimir lo que lei*/
pout = fopen("archivo.txt","w");
for( x = 0; x < n; x++){
fprintf(pout, "Elemento %d\n", x + 1);
fprintf(pout, "Pregunta: %s\n", A[ x ].pregunta);
fprintf(pout, "a: %s\n", A[ x ].a);
fprintf(pout, "b: %s\n", A[ x ].b);
fprintf(pout, "c: %s\n", A[ x ].c);
fprintf(pout, "temp: %c\n", A[ x ].temp);

}
return 0;	
}
