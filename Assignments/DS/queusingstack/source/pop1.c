# include "header.h"
int pop1()
{
	int ele;
	if(st2.top2 < 0)
		printf("no element stack over flow in stack2\n");
	else {
		ele =  st2.b[st2.top2--];
	}
	return ele;
		
}
