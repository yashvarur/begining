/* program to test and set the bits */
#include"header.h"
int main()
{
        int num1, pos,num2,flag=1;
        printf("enter the number\n");
        num1=int_read();

        printf("number in decimal format\n");\
        binary(num1);

        printf("enter the position of bit\n");
        while(flag) {
                pos = int_read();
                if(( pos < 0 ) || ( pos > 32))  {
                        printf("invalid bit position enter again\n");
                        flag=1;
                }
                else
                        break;
        }

        num2= bit_ts(num1,pos);
	binary(num2);
        return 0;
}


