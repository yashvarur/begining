#include"header.h"
unsigned int reverse(unsigned int num) /*function to reverse a number */
{	
	int i;
	unsigned int t=0;
	for(i = 31 ; i >= 0 ; i--)
	{
		t  = t | ( ( num & 1 ) << i);
		num = num >> 1;
		
		
	}
	
	return t;
}
