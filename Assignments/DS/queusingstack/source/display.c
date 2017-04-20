# include "header.h"
void display()
{
	int i;
	i = st1.top1;
	if(st1.top1 == -1)
		printf("no elements to display\n");
	else {
		for(;i >= 0 ;i--)
			printf("%d\t",st1.a[i]);
		printf("\n");
	}
}

