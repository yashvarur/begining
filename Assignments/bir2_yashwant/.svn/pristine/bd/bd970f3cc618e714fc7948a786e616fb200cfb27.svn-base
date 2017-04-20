#include"header.h" /* function to rorate a bits */
unsigned int rotate_bit(unsigned int num, int bit, int dir)
{
	int i;
	switch(dir) {
	
	case 0:
		printf("right to left rotation\n");
		for(i = 0 ; i < bit ; i++) {
			num = ( ( ( 1 << 31 ) & num ) >> 31 ) | ( num << 1 );
			binary(num);
		}
		
		break;
	case 1:
		printf("left to right rotation\n");
		for(i = 0;i < bit ; i++) {	
			num = ( ( num & 1 ) << 31 ) | ( num >> 1 );
			binary(num);
		}
		break;
	default:printf("invalid choice\n");
		break;
	}
	return 0;
}
