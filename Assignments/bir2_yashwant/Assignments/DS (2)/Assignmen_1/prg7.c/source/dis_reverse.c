#include"header.h"
void display_reverse(NODE * p)
{
	NODE *temp = p;
	if(p ==NULL)
		printf("list is empty\n");
	else {
		temp = p -> prev;
		while(temp -> prev != p -> prev) {
			printf("%d\t",temp->data);
			temp = temp -> prev;
		}
		printf("%d\n",temp->data);
	}
}
