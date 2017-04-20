#include"header.h"
NODE* enque(NODE *p)
{
	int ele;
	NODE *new_node;
	NODE *temp;

	printf("enter the element to insert\n");
        scanf("%d",&ele);
	new_node = malloc(sizeof(NODE));
	new_node->data = ele;
	new_node->next = NULL;
	if( p == NULL)
		p = new_node;
	else {
		temp = p;
		while(temp->next != NULL)
			temp  = temp->next;
		temp->next = new_node;
	}
	return (p);
}
