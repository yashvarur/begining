#include"header.h"
NODE * delete_front(NODE *p)
{
	NODE *temp;

		if(p ==  NULL) {
			printf("list is empty\n");
			return NULL;
		}
	 
                if(p -> next == p)  {
                        printf("removed data %d\n",p->data);
                        return NULL;
                }

		else {
			temp = p;
			p = temp -> next; 
			p -> prev = temp -> prev;
			temp -> prev -> next = p;
			printf("removed data is %d\n",temp -> data);
			free(temp);
		
		}
		return p;
	
}
