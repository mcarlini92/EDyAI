#include <stdio.h>
#include <stdlib.h>

enum PALO {ORO, ESPADA, BASTO, COPAS};

struct carta {
	enum PALO palo;
	int numero;
};

int main(void) {
	struct carta mazo[48];
	int i;
	int z;
	for (i = 0; i < 12; i++) {
		mazo[i].palo = ORO;
		mazo[i].numero = i + 1;
	}

	for (i = 12; i < 24; i++) {
		mazo[i].palo = ESPADA;
		mazo[i].numero = i - 11 ;
	}

	
	for (i = 24; i < 36; i++) {
		mazo[i].palo = BASTO;
		mazo[i].numero = i - 23 ;
	}

	for (i = 36; i < 48; i++) {
		mazo[i].palo = COPAS;
		mazo[i].numero = i - 35 ;
	}
	for(z=0; z < 48; z++){
		printf("Palo:%d\tNumero:%d\n", mazo[z].palo, mazo[z].numero); 	
	}
	system("PAUSE");
	return 0;
}
	
		
	
	
