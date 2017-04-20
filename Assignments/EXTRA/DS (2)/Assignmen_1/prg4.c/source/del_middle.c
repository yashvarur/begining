#include"header.h"
NODE *delete_middle(NODE*p)
{
	int c;
	NODE *temp1,*temp2;
	int i;
	NODE *prev;
	temp1 = p;
	temp2 = p;
	l--;
	if(p == NULL) {
		printf("no contents\n");
		return NULL;
	}
	else {
		while(temp1->next != NULL) {
			temp1 = temp1->next;
			c++;
		}
	c = c + 1;
	c = c / 2;
	for(i=0;i<=(c-1);i++) {
		prev = temp2;
		temp2 = temp2->next;
	}
	temp1 = p;
	prev->next = temp2->next;
	printf("element removed is %d\n",temp2->data);
	free(temp2);
	if(temp1->next == NULL)
		p = NULL;
	}
	
	return p;	
}
