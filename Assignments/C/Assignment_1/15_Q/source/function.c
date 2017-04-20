#include"stdio.h"	/* function to swap the two number without using third variable */
void fun(int a,int b)
{
	printf("a=%d,b=%d\n",a,b);
        a=a^b;
        b=a^b;
        a=a^b;
        printf("a=%d,b=%d\n",a,b);
}
