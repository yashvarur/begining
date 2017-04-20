#include"header.h"
MONODE * insert_sub_rear(MNODE *p, SNODE *start)
{
	SNODE *new;
	SNODE *last;
	int ele;
	new = malloc(sizeof(SNODE));
	printf("enter the element to insert at sublist\n");
	scanf("%d",&ele);
	new -> sprev = NULL;
	new -> snext = NULL;
	new -> sdata = ele;
	if(start == NULL) {
		start = new;
		start -> sprev = new;
		start -> snext = new;
		p -> sub_list = start;
		return p;
	}	
	else {
		last = start -> sprev;
		last -> snext = new;
		start -> sprev = new;
		new -> sprev = last;
		new -> snext = start;
		p -> sub_list = start;
		return p;			
	}

}
		
