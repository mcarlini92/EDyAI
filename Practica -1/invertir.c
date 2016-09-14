#include <stdio.h>

int main () {
	invertir (1000);
	printf ("\n");
	system("PAUSE");
	return 0;
}

int invertir (int n) {
	int digito = 0;
	while (n > 0) {
		digito = n % 10;
		n /= 10;
		printf( "%d", digito); 
	}
}