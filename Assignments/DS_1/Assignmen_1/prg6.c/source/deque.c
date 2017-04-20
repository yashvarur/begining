#include"header.h"
NODE * deque(NODE *p)
{
	NODE *temp,*new_node;
	temp = p;

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
