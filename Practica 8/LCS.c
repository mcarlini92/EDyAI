#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (a > b ? a : b)
#define MAXLONG 10
int table[MAXLONG][MAXLONG];

int LCS(char X[], int szX, char Y[], int szY) {
	int i, j;
	for (i=0; i<=szX; i++) 
		table[i][0]=0; // Y0
		
	for (j=1; j<=szY; j++)
		table[0][j]=0; // X0
		
	for (i=1; i<=szX; i++) // Xi
		for (j=1; j<=szY; j++) // Yj
			if ( X[i] == Y[j] )
				table[i][j] = table[i-1][j-1] + 1;
			else
				table[i][j] = max(table[i-1][j], table[i][j-1]);
				
	return table[szX][szY];
}

int main (){
	char *X, *Y;
	int szX, szY; 
	X = "ABCB";
	szX = 4;
	Y = "BDCAB";
	szY = 5;
	printf("Resultado: %d", LCS(X, szX, Y, szY));
	return 0;
}
