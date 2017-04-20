#include"header.h"
NODE* insert_middle(NODE *p)
{
	int ele;
	int i;
	int count=0;
	NODE *new_node;
	NODE *e;
	NODE *temp;
	l++;
        printf("enter the element to insert\n");
        scanf("%d",&ele);
        new_node = malloc(sizeof(NODE));
        new_node->data = ele;
        if(p == NULL) {
                p = new_node;
        }
	else {
		temp = p;
		while(temp->next != NULL) {
			temp = temp->next;
			count++;
		}
		count = count + 1;
		temp = p;
		count = count/2;
		for(i=0 ;i< (count-1);i++) {
			temp = temp->next;
		}
		e = temp->next;
		temp->next = new_node;
		new_node->next = e;     
	}
	return(p);
}
