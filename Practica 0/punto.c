#include <stdio.h>
#include <stdlib.h>

struct punto {
	int x;
	int y;
};

void medio (struct punto pt1, struct punto pt2){
	struct punto ptm;
	ptm.x=((pt1.x+pt2.x)/2);
	ptm.y=((pt1.y+pt2.y)/2);
	printf("Punto medio: (%d, %d)", ptm.x, ptm.y);
}

struct punto makepoint (int x, int y) {
	struct punto temp;
	temp.x= x;
	temp.y= y;	
	return temp;	
}

int main () {
	medio(makepoint(1, 2), makepoint(3, 4));
	system("PAUSE");
	return 0;
}