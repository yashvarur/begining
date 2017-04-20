#include"header.h"
void popn(int pos)
{
	int ele;
	int i;
	if(pos < 0)
		printf("stack underflow\n");
	else {
		ele = st.s[st.top - pos];
		if(ele == 0)
			printf("no elements to remove\n");
		else {
			printf("element removed form stack is = %d \n",ele);
			st.s[st.top-pos]^=st.s[st.top-pos];
		}
	}
}
