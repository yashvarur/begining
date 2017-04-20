#include"header.h"   
void binary(int num)		/* function to display number in binary format */
{	
	int i;
	for(i = 31; i >= 0; i--) {
		printf("%d", ( ( num >> i ) & 1 ) ? 1 : 0 );      
		if ( !(i % 8) )
			printf ("\t");
	}
	printf("\n");
}
