#include <stdio.h>
#include <stdlib.h>

#define MAX 9

int sudoku[MAX][MAX];

void print_sodoku(void) {
	int i, j;
	printf("\n");
	for(i=0; i < MAX; i++) {
		for(j=0; j < MAX; j++)
			printf("%d", sodoku[i][j]);
		printf("\n");
  }
}

int factible_fila(int fila, int valor){
	int i;
	for(i=0; i < MAX; i++)
		if (sudoku[fila][i]==valor)
			return 0;
	return 1;
}


int factible_col(int col, int valor){
	int i;
	for(i=0; i < MAX; i++)
		if (sudoku[i][col]==valor)
			return 0;
	return 1;
}

int factible_disp(int fila, int col){
	if(sudoku[fila][col] = 0)
		return 1;
	return 0;
}

int factible_cuad(int fila, int col, int valor){
	int i, j;
	if(0 <= fila <= 2 && 0 <= col <= 2){
		for(i=0; i <= 2; i++)
			for(j=0; j <= 2; j++)
				if(sudoku[i][j] == valor)
					return 0;
		return 1;
	}
	
	if(0 <= fila <= 2 && 3 <= col <= 5){
		for(i=0; i <= 2; i++)
			for(j=3; j <= 5; j++)
				if(sudoku[i][j] == valor)
					return 0;
		return 1;
	}
	
	if(0 <= fila <= 2 && 6 <= col <= 8){
		for(i=0; i <= 2; i++)
			for(j=0; 6 <= 8; j++)
				if(sudoku[i][j] == valor)
					return 0;
		return 1;
	}
	
	if(3 <= fila <= 5 && 0 <= col <= 2){
		for(i=3; i <= 5; i++)
			for(j=0; j <= 2; j++)
				if(sudoku[i][j] == valor)
					return 0;
		return 1;
	}
	
	if(3 <= fila <= 5 && 3 <= col <= 5){
		for(i=3; i <= 5; i++)
			for(j=3; j <= 5; j++)
				if(sudoku[i][j] == valor)
					return 0;
		return 1;
	}
	
	if(3 <= fila <= 5 && 6 <= col <= 8){
		for(i=3; i <= 5; i++)
			for(j=0; 6 <= 8; j++)
				if(sudoku[i][j] == valor)
					return 0;
		return 1;
	}
	
	if(6 <= fila <= 8 && 0 <= col <= 2){
		for(i=6; i <= 8; i++)
			for(j=0; j <= 2; j++)
				if(sudoku[i][j] == valor)
					return 0;
		return 1;
	}
	
	if(6 <= fila <= 8 && 3 <= col <= 5){
		for(i=6; i <= 8; i++)
			for(j=3; j <= 5; j++)
				if(sudoku[i][j] == valor)
					return 0;
		return 1;
	}
	
	if(6 <= fila <= 8 && 6 <= col <= 8){
		for(i=6; i <= 8; i++)
			for(j=0; 6 <= 8; j++)
				if(sudoku[i][j] == valor)
					return 0;
		return 1;
	}
}

int es_factible(int fila, int col, int valor){
	if (factible_fila(fila, valor) && factible_col(col, valor) && factible_cuad(fila, col, valor) && factible_disp(fila, col))
		return 1;
	return 0;
}

void backtraking(){
	int i, int j, int aux;
	
	for(i=0; i < MAX; i++)
		for (j=0; j < MAX; j++)
			for(aux=1; aux <= 9; aux++)
				if (es_factible(i, j, aux)){
					sudoku[i][j] = aux;
					backtraking();
					sudoku[i][j] = 0;
				}
	printf("No existe solucion \n");
	return;
}

int main() {
	int i, j;
	for(i=0; i < MAX; i++)
		for (j=0; j < MAX; j++)
			sudoku[i][j] = 0;
			
	sudoku[1][0] = 5;
	sudoku[1][4] = 8;
	sudoku[0][6] = 3;
	sudoku[0][7] = 6;
	sudoku[2][7] = 2;
	
	backtraking();
	return 0;
}