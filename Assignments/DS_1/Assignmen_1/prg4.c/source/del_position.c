#include"header.h"
NODE *delete_position(NODE*p)
{
	NODE *temp;
	NODE *prev;
	int pos;
	int i;
	temp = p;
	 if( p == NULL) {
                printf("no contents\n");
                return NULL;
        }
	printf("enter the position to delete the element\n");
	scanf("%d",&pos);
	if(pos <= l) {
	
			temp = p;
			prev = p;
			if(pos == 1) {
				prev->next = temp->next;
				p = prev;
				printf("removed data = %d\n",temp->data);
				free(temp);
				return NULL;
			}
			else {	
				for(i = 1;i < pos;i++) {
					prev = temp;
					temp = temp->next;
				}
				prev ->next = temp->next;
				printf("element removed is %d\n ",temp->data);
				free(temp);
				
			}	
	}		
	else
		printf("invalid position\n");
	return p;
}
		
