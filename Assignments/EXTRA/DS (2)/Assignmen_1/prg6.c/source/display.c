#include"header.h"
void display(NODE *p)
{
	NODE *temp;
	temp = p;
	if(p == NULL)	
		printf("no element to display\n");
	else  {
		printf("content of queue\n");
		while(temp->next != NULL) {
			printf("%d\t",temp->data);
			temp = temp->next;
		}
		printf("%d\n",temp->data);
	}
}
	
