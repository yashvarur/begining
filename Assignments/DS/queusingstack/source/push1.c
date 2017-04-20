# include "header.h"

void push1(int ele)
{
	if(st2.top2 > 10)
		printf("stack2 overflow\n");
	else
		st2.b[++st2.top2] = ele;
}
