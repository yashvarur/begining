#include"header.h"	/* function to count number of bits set in given number */
void fun(int num)
{
	int i,l=0;
	for(i=8;i>0;i=i/2)
        {
                if((num&i)==0)
                printf("0");
                else
                {
                        printf("1");
                        l++;
                }
        }

        printf("number of bitb sets=%d",l);
}
