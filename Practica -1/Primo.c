#include <stdio.h>

int isprime (int n) {
	int i;
	int p = 1;
	for (i=2;(p==1) && (i < n);i++) 
		if ((n%i)==0) 
			p = 0;		
return p;
}

int main () {
	printf ("Resultado : %d . \n", isprime (41));
	system("PAUSE");
	return 0;
}