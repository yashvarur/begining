/*program to rorate a bits */
#include"header.h"
int main()
{	
	int nb, di;
	unsigned int num;
	printf("enter the number in decimal foramt\n");
	num = int_read();
	printf("entered number in binary format\n");
	binary(num);
	printf("enter the number of bits\n");
	nb = int_read();
	printf("enter the direction 0-right to left\n 1-left to right\n");
	di = int_read();
	rotate_bit(num, nb, di);


	return 0;
}
