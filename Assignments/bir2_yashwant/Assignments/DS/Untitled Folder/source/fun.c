/*
#include"header.h"
MNODE * in(MNODE *p, SNODE *start)
{
	SNODE *new;
	SNODE *last;
	new = malloc(sizeof(SNODE));
	new->sprev = NULL;
	new->snext = NULL;
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
	*/	
