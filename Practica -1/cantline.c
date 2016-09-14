#include <stdio.h>

int lc (){
	int i = 0;
	char c = getchar ();
	if (c == EOF)
		return 0;
	while (c != EOF) {
			if (c == '\n') {
			i++;
			}
		c = getchar();
	}
	return i;
}


int main () {
	printf ("Resultado : %d . \n", lc ());
	system("PAUSE");
	return 0;
}
