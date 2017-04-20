#include<stdio.h>
#include<stdlib.h>
typedef struct sub_list
{
	int sdata;
	struct sub_list *sprev;
	struct sub_list *snext;
}SNODE;

typedef struct main_list
{
	int mdata;
	struct main_list *mnext;
	struct main_list *mprev;
	struct sub_list *link_sublist;
}MNODE;
MNODE * insert_sub_rear(MNODE *p, SNODE *start);
MNODE * creation(MNODE*p);
MNODE * insert_front(MNODE*p);
MNODE * insert_rear(MNODE * p);
MNODE * insert(MNODE *p);
void display_main(MNODE * p);
MNODE * insert_sub_front(MNODE *p,SNODE *start);


