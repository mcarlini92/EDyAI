#include <stdio.h>

int main () {
	int fahr, cels;
	cels = 0;
		while (cels <= 200) {
			fahr = 1.8 * cels +32;
			printf("%d\t%d\n",cels,fahr);
			cels = cels + 30;
	}
	system("PAUSE");
	return 0;
}