#include"header.h"
int fib(int num)
{
	if( ( num == 1 ) || ( num == 0 ) ) 
		return 0;
	else if( num == 2 )
		return 1;
	else
		return fib(num-1) + fib(num-2);
}
