#include<stdio.h>
#include<stdlib.h>
typedef struct doubly_linked_list
{
	int data;
	struct doubly_linked_list *prev;
	struct doubly_linked_list *next;
}NODE;
int count;
NODE * insert_rear(NODE*p);
NODE * delete_front(NODE*p);
void display(NODE*p);
NODE * delete_rear(NODE *p);
NODE * insert_front(NODE*p);
int main()
{
	int choice;
	NODE *start;
	start = malloc(sizeof(NODE));
	start = NULL;
	int c = 1;
	
	while(c==1) {
		printf("\t\t1-insert at rear\n");
		printf("\t\t2-insert at front\n");
		printf("\t\t3-delete at rear\n");
		printf("\t\t4-delete at front\n");
		printf("\t\t5-display\n");
		printf("\t\tenter your choice\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1: start = insert_rear(start);
				break;
			case 2: start = insert_front(start);
				break;
			case 3: start = delete_rear(start);
                                break;
			case 4: start = delete_front(start);
				break;
			case 5: display(start);
				break;
			default :exit(0);
		}

	}
}
NODE * delete_rear(NODE * p)
{
	NODE *last;
	NODE *temp;

		if(p == NULL) {
			printf("list is empty\n");
			return p;
		}
		if(p -> next == p)  {
			printf("removed data %d\n",p->data);
			return NULL;
		}
		else {
			temp = p -> prev;
			last = temp -> prev;
			p -> prev = last;
			last -> next = p;
			printf("removed data = %d\n",temp -> data);
			free(temp);
			return p;
		}
	
}
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
NODE * insert_rear(NODE * p)
{
	NODE *new;
	NODE *last;
	int ele;
	
	new = malloc(sizeof(NODE));
	new->prev = NULL;
	new->next = NULL;
	printf("enter the element to insert\n");
	scanf("%d",&ele);
	new->data = ele;
	if(p == NULL) {
		p = new;
		p -> next = new;
		p -> prev = new;
	}
	else {
		last = p -> prev;
		last -> next = new;
		p -> prev = new;
		new -> prev = last;
		new -> next = p;			
	}
	return p;
}
NODE * insert_front(NODE*p)
{
	int ele;
	NODE *new;
	NODE *last;
	
	new = malloc(sizeof(NODE));
	new->prev = NULL;
        new->next = NULL;
        printf("enter the element to insert\n");
        scanf("%d",&ele);
        new->data = ele;
	if(p == NULL) {
		p = new;
		p -> next = p;
		p -> prev = p;
	}
	else {
		last = p -> prev;
		new  -> next  = p;
		p -> prev = new;
		new -> prev = last;
		last -> next = new;
		}
	return new;
}
		 
void display(NODE * p)
{
	NODE * temp;
	temp = p;
	if(p == NULL)
		printf("list is empty\n");
	else {
		printf("content of list\n");
		while(temp -> next != p) {
			printf("%d\t",temp->data);
			temp = temp->next;
		}
		printf("%d\n",temp->data);
	}
}
		
