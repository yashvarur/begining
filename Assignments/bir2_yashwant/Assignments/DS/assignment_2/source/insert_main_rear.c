#include"header.h"
MNODE * insert_rear(MNODE * p)
{
	MNODE *new;
	MNODE *last;
	int ele;	
	new = malloc(sizeof(MNODE));
	new->mprev = NULL;
	new ->link_sublist = NULL;
	new->mnext = NULL;
	printf("enter the element to insert\n");
	scanf("%d",&ele);
	new->mdata = ele;
	if(p == NULL) {
		p = new;
		p -> mnext = new;
		p -> mprev = new;
	}
	else {
		last = p -> mprev;
		last -> mnext = new;
		p -> mprev = new;
		new -> mprev = last;
		new -> mnext = p;			
	}
	return p;
}
