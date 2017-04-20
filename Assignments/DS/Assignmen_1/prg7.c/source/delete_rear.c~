#include"header.h"
NODE * delete_rear(NODE * p)
{
	NODE *last;
	NODE *temp;

		if(p == NULL) {
			printf("list is empty\n");
			return p;
		}
		if(p -> next == p)  {
			printf("removed data %d\n",p->data);
			return NULL;
		}
		else {
			temp = p -> prev;
			last = temp -> prev;
			p -> prev = last;
			last -> next = p;
			printf("removed data = %d\n",temp -> data);
			free(temp);
			return p;
		}
	
}
