#include "header.h"
SUB * insert_subnode_rear (SUB * START)
{
	SUB * temp;
	SUB * new;
	if ( ! (START) ) {
	temp = create_subnode();
	START = temp;	
	temp -> next = START;
	temp -> prev = START;
	} else {
		temp = START -> prev;
		//while (temp -> next != START) {
		//	printf ("data = %d\n",temp ->data);
		//	temp = temp -> next;
		//}
		new = create_subnode();
		temp -> next = new;
		new -> prev = temp;
		new -> next = START;
		START -> prev = new;
		
	}
	return START;
}
			 
