#include "header.h"
SUB * create_subnode ()
{
	SUB * temp;
	temp = (SUB * ) malloc ( sizeof (SUB));
	temp -> next = NULL;
	temp -> prev = NULL;
	printf ("Enter data of node\n");
	temp -> data = read_int();
	return temp;
}
	

