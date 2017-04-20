#include"header.h"
NODE* delete_rear(NODE * p)
{
	NODE *temp1;
	NODE *temp2;
	temp2 = p;
	l--;
	int count=0;
	if(p == NULL) {
		printf("no contents\n");
		return NULL;
	}
	else {
		temp1 = p;
		while(temp1->next != NULL) {
			temp2 = temp1; 
			temp1 = temp1->next;
			count++;
		}
		if(count == 0) {
			p = NULL;
		}
		else
		temp2->next = NULL;
		printf("element %d is succesfully removed \n",temp1->data);
		free(temp1);	
	}	
		return(p);		
}
