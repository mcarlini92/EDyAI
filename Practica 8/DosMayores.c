#include <stdio.h>
#include <stdlib.h>

void solve(int data1[], int sz1, int data2[], int sz2, int r[]) {
	int i = 0, j = 0, k, aux;

	for (k = 0; k < sz1 + sz2; k++) {
		if (i < sz1 && j < sz2 && data1[i] >= data2[j] || i < sz1 && j >= sz2){
			aux = i;
			r[0] = data2[i++];
		}
		else if (i < sz1 && j < sz2 && data2[j] >= data1[i] || j < sz2 && i >= sz1){
			aux = j;
			r[0] = data2[j++];
		}
	}
	i = 0, j = 0;
	for (k = 0; k < sz1 + sz2; k++) {
		if (i < sz1 && j < sz2 && data1[i] <= data2[j] && i != aux || i < sz1 && j >= sz2 && i != aux)
			r[1] = data1[i++];
		else if (i < sz1 && j < sz2 && data2[j] <= data1[i] && j != aux || j < sz2 && i >= sz1 && j != aux)
			r[1] = data2[j++];
	}
}


int *divandcon(int data[], int sz) {
	int *sol = malloc(sizeof(int) * 2);
	int mid = sz/2;
	int *sub1, *sub2;

	if (sz == 1){
		sol[0] = data[0];
		return sol;
	}

	sub1 = divandcon(data, mid);
	sub2 = divandcon(data + mid, sz - mid);

	solve(sub1, mid, sub2, sz - mid, sol);

	free(sub1);
	free(sub2);

  return sol;
}

int main(void) {
	int i;
	int lst[] = { 3, 5, 1, 4, 2 };
	int *r = divandcon(lst, 5);

	for (i = 0; i < 2; i++)
		printf("%d\t", r[i]);
	puts("");
  
	return 0;
}