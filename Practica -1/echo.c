#include <stdio.h>

int main () {
	int i = 0;
	char c;
	while (i < 5) {
		c = getchar ();
		printf ("%c",c);
		i++;
	}
	system("PAUSE");
	return 0;
}
