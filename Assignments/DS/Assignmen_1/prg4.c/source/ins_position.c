#include"header.h"
NODE* insert_position(NODE *p)
{
	int ele;
	int i;	
	int pos;
	NODE *e;
        NODE *new_node;
        NODE *temp;
        printf("enter the element to insert\n");
        scanf("%d",&ele);
	printf("enter the position to insert\n");
	scanf("%d",&pos);
	if(pos <= (l+1)) {
		new_node = malloc(sizeof(NODE));
       		new_node->data = ele;
       		new_node->next = NULL;
       		if( p == NULL)
               		p = new_node;
		else {
			temp = p;
			if(pos == 1) {
				new_node->next = temp;
				p = new_node;
			}
			else {
				for(i = 0;i < (pos-2);i++)
					temp = temp->next;
				e = temp->next;
				temp->next = new_node;
				new_node->next = e;
			}
		}
	}
	else {
		printf("you entered invalid position\n");
	}
	return (p);
}
			
