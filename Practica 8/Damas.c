#include <stdio.h>
#include <stdlib.h>


int solve (int posI, int posF, int dim){
	static int table[dim][dim] = { 0 };
	if(posI==posF)
		return (MAX-1);
	



}



int main (){
	int posIni, posFin, dim;
	scanf("Dimension nxn: %d", &dim);
	scanf("Posicion inicial Fila: 1, Columna: %d", &PosIni);
	scanf("Posicion final Fila: 8, Columna: %d", &PosFin);
	solve(posIni, posFin, dim);
	return 0;
}