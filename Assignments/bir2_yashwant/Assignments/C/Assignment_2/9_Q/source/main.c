/* program to check wheather given number is prime or not*/
#include "header.h"
int main()
{
	int num, f = 0, i = 2;
	printf("enter the number\n");
	num = int_read();
	f = prime_check(num,i);
	if( f == 0)
                printf("not a prime number\n");
        else
                printf("given number in prime number\n");
	return 0;
}
	
	
