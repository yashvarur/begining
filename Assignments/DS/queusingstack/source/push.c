# include "header.h"
void push(int ele)
{
	int i;
	if(st1.top1 > 10)
		printf("stack overflow\n");
	else 
		st1.a[++st1.top1] = ele;
		
}
