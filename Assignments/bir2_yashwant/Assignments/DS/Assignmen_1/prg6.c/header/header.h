#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE * enque(NODE*p);
NODE * deque(NODE*p);
void display(NODE*p);
