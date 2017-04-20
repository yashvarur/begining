#include"header.h"
void display_main(MNODE * p)
{
	MNODE * temp;
	temp = p;
	if(p == NULL)
		printf("list is empty\n");
	else {
		printf("content of main list\n");
		while(temp -> mnext != p) {
			printf("%d\t",temp->mdata);
			temp = temp->mnext;
		}
		printf("%d\n",temp->mdata);
	}
}
