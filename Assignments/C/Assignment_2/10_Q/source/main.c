/* program to print prime number using recurssion */
#include"header.h"
int main()
{
	int num, f = 0, i = 2, j;
	printf("enter the last number\n");
	num=int_read();
	for(j = 2 ; j <= num ; j++)
	{	
		f = prime(j, i);
		if( f!=0 )
		printf("%d\n",f);
	}
	return 0;
}
