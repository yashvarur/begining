/* function to perform bit copy from source to destination */
#include "header.h"
int main()
{

	int snum, dnum, s, d,flag = 1;
	
	printf("enter the source number\n");\
	snum = int_read();                 

	printf("enter the destination number\n");
	dnum = int_read();

	printf("\nsource number in binary number\n");
 	binary(snum);

	printf("\ndestination number in binary format\n");
	binary(dnum);

	printf("\nenter the bit position in source\n");
	while(flag) {
		s = int_read();
		if((s < 0) || ( s > 32))  {
			printf("invalid bit position enter again\n");	
			flag=1;
		}
		else 		
			break;
	}
	flag=1;		
	printf("\nenter the bit position in destination\n");
	while(flag) {
                d = int_read();
                if(( d < 0)|| (d > 32))  {
                        printf("invalid bit position enter again\n");
                        flag=1;
                }
                else
                        break;
        }
	bit_cp(s,d,snum,dnum);

	return 0;
}
	 
