#include"header.h"
NODE * insert_front(NODE*p)
{
	int ele;
	NODE *new;
	NODE *last;
	
	new = malloc(sizeof(NODE));
	new->prev = NULL;
        new->next = NULL;
        printf("enter the element to insert\n");
        scanf("%d",&ele);
        new->data = ele;
	if(p == NULL) {
		p = new;
		p -> next = p;
		p -> prev = p;
	}
	else {
		last = p -> prev;
		new  -> next  = p;
		p -> prev = new;
		new -> prev = last;
		last -> next = new;
		}
	return new;
}
