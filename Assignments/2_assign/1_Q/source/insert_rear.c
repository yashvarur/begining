#include "header.h"
LIST* insert_rear (LIST * START)
{
	LIST * temp;
	if ( ! (START) ) {
	temp = create_node();
	START = temp;
	} else {
		temp = START;
		while (temp -> next != NULL) {
			temp = temp -> next;
		}
		temp -> next = create_node();
	}
	return START;
}
			 
