#include <stdio.h>
#include "mov.h"
#include "entrada.h"
#include "salida.h"
#include "cruz.h"
#include "vertices.h"
#include "aristas.h"
#include "cruzopo.h"
#include "extendercruzopo.h"
#include "posicesqui.h"
#include "orientesqui.h"

#define MAX1	9
#define MAX2	12

int cubo[MAX2][MAX1] = {{0}};

void solucionar_cubo()
{
	formar_cruz();
	insertar_vertices();
	insertar_aristas();
	cruz_cara_opuesta();
	extender_cruz_opuesta();
	posicionar_esquina();
	orientar_vertice();
	acomodar_ultima_capa();
}

int main()
{
	llenar_cubo();
	solucionar_cubo();
	if(testing_comprobar_cubo()!=1)
		{
			printf("ERROR!\n");
			return 0;
		}
	imprimir_receta();
	printf("\n");
	
	return 0;	
}
