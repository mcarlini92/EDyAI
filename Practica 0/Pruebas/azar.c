#include <stdio.h>
#include <stdlib.h>
#include<time.h>
 
int main()
{
    int num,c;
    srand(time(NULL));
    for(c=1;c<=10;c++)
    {
        num=1+rand()%(11-1);
        printf("Numero: %d\n",num);
    }
	system("PAUSE");
    return 0;
}