#include"header.h"
NODE* insert_front(NODE *p)
{
	int ele;
	NODE *new_node;
	printf("enter the element to insert\n");
	scanf("%d",&ele);
	l++;
	new_node = malloc(sizeof(NODE));
	new_node->data = ele;
	if(p == NULL) {
		p = new_node;
	}
	else {
		new_node->next = p;
		p = new_node;
	}
	return(p);
}
