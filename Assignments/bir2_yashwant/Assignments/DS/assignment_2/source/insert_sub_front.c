#include"header.h"
MNODE * insert_sub_front(MNODE *p,SNODE *start)
{
	SNODE *new;
	SNODE *last;
	int ele;
	new = malloc(sizeof(SNODE));
	printf("enter the element to insert into sublist\n");
	scanf("%d",&ele);
	new -> sprev = NULL;
	new -> snext = NULL;
	new -> sdata = ele;
	if(start == NULL) {
		start = new;
		start -> sprev = new;
		start -> snext = new;
		p -> link_sublist = start;
		return p;
	}
	else {
		last = start -> sprev;
		new  -> snext  = start;
		start -> sprev = new;
		new -> sprev = last;
		last -> snext = new;
		p -> link_sublist = start;
		return p;
	}
}
