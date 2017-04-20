#include"header.h"
NODE * delete_front(NODE *p)
{
	NODE *temp,*new_node;
	temp = p;
	l--;
	if(p == NULL) {
		printf("no content\n");
		return NULL;
	}
	else {
		if(temp->next == NULL) {
			p = NULL;
			printf("element %d is successfully removed\n",temp->data);
			free(temp);
		}
		else {
			new_node =temp->next;
			printf("element %d is successfully removed\n",temp->data);
			free(temp);
			p = new_node;
		}
	}
	return p;
}
