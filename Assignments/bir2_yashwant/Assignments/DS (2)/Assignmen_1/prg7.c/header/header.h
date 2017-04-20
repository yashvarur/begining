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
void display_reverse(NODE * p);
NODE * insert_front(NODE*p);
