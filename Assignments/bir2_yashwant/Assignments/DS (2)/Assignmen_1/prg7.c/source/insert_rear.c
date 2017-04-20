#include"header.h"
NODE * insert_rear(NODE * p)
{
	NODE *new;
	NODE *last;
	int ele;
	
	new = malloc(sizeof(NODE));
	new->prev = NULL;
	new->next = NULL;
	printf("enter the element to insert\n");
	scanf("%d",&ele);
	new->data = ele;
	if(p == NULL) {
		p = new;
		p -> next = new;
		p -> prev = new;
	}
	else {
		last = p -> prev;
		last -> next = new;
		p -> prev = new;
		new -> prev = last;
		new -> next = p;			
	}
	return p;
}
