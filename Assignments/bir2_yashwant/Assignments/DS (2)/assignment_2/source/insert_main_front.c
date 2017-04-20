#include"header.h"
MNODE * insert_front(MNODE*p)
{
	int ele;
	MNODE *new;
	MNODE *last;
	
	new = malloc(sizeof(MNODE));
	new->mprev = NULL;
        new->mnext = NULL;
        printf("enter the element to insert\n");
        scanf("%d",&ele);
        new->mdata = ele;
	if(p == NULL) {
		p = new;
		p -> mnext = p;
		p -> mprev = p;
	}
	else {
		last = p -> mprev;
		new  -> mnext  = p;
		p -> mprev = new;
		new -> mprev = last;
		last -> mnext = new;
		}
	return new;
}
