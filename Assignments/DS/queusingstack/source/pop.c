# include "header.h"
void pop()
{
	int i;
	int j;
	if(st1.top1 < 0)
		printf("no element to pop\n");
	else {
		j =  st1.top1;
		for(i = 0; i < j; i++) {
			push1(st1.a[st1.top1--]);
		}
		printf("poped element = %d\n",st1.a[st1.top1--]);
		i = st2.top2;
		for(;i >= 0; i--)
			push(pop1());

	}				
}
