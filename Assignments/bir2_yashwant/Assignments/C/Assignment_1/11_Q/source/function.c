#include"header.h"	/* recurssion function to calculate factorial of a number */
int fun(int num)
{
        if(num!=1)
        return fun(num-1)*num;
	else
	return 1;
}

