#include <stdio.h>

int main () {
	int i = 0;
	char p = ' ';
	while (1) {
		char c = getchar ();
		if (c=='a')
			(p = 'u');
		else if (c=='e')
			(p = 'o');
		else if (c=='i')
			(p = 'i');
		else if (c=='o')
			(p = 'e');
		else if (c=='u')
			(p = 'a');
		else
			( p = c );
		printf ("%c",p);
	}	
	return 0;
}
