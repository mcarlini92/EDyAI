#include <stdio.h>

int main () {
	printf("%d \n", dig (123));  
	system("PAUSE");
	return 0;
}

int cantdig (int num) {
  if (num != 0) {
    int n = 0;
    while (num > 0) {
      ++n;
      num /= 10;
    }
    return n;
  } else
    return 1;
}