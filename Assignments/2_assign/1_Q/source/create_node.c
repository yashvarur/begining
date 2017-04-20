#include "header.h"
LIST * create_node ()
{
	LIST * temp;
	temp = (LIST * ) malloc ( sizeof (LIST));
	temp -> next = NULL;
	temp -> prev = NULL;
	temp -> sub_ls = NULL;
	printf ("Enter data of node\n");
	temp -> data = read_int();
	return temp;
}
	

