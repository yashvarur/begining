#include"header.h"	/* function to display number in binary format */
void fun(int num) {
	int t;
	for(t=128;t>0;t=t/2)
	if((num&t)==0)
        printf("0");
        else
        printf("1");
}

