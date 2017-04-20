#include "header.h"
LIST * insert_front (LIST * START)
{
	LIST * temp;
	if (!(START)) {
		temp = create_node();
		START = temp;
		temp -> next = START;
		temp -> prev = START;
	} else {
		temp = create_node();
		temp -> next = START;
		temp -> prev = START -> prev;
		START -> prev -> next = temp;
		START -> prev = temp;
	        START = temp;
	}
	return START;
}
     		
