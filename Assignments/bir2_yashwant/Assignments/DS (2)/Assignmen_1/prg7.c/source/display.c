#include"header.h"
void display(NODE * p)
{
	NODE * temp;
	temp = p;
	if(p == NULL)
		printf("list is empty\n");
	else {
		printf("content of list\n");
		while(temp -> next != p) {
			printf("%d\t",temp->data);
			temp = temp->next;
		}
		printf("%d\n",temp->data);
	}
}
