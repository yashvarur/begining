#include"header.h"	/* function to set or clear the bit */

void fun(int a,int b)
{	
	int cl,bit;
	printf("enter the bit to set");
	scanf("%d",&bit);
	a = a | (1 << bit);
        printf("after setting bit number will be=%d \n", a);
        printf("enter the bit to clear\n");
        scanf("%d",&cl);
        b=b & ~(1<<cl);
        printf("after clearing number will be=%d\n",b);
}

