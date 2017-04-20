#include "header.h"
int t_count(int num)
{
	int count = 0;
	
	if(num==0) {
		count=32;
	}
		
	while (num) {
		if ( num & 1 )
			break;
		count++;
		num = num >> 1;
	}

	return count;
}
