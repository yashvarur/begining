#include<header.h>
void push(int ele)
{
	if(st.top > MAX - 1)
		printf("stack is full\n");
	else 
		st.s[++st.top] = ele;
	
}
