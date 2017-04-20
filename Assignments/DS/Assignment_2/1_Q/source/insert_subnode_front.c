#include "header.h"
SUB * insert_subnode_front (SUB * START)
{
		SUB * temp;
	  if ( ! (START) ) {
			temp = create_subnode();
	     	START = temp;
	        temp -> next = START;
			temp -> prev = START;
	}else {
		temp = create_subnode();
		temp -> next = START;
		temp -> prev = START -> prev;
		START -> prev -> next = temp;
		START -> prev = temp;
	    START = temp;
	}
	return START;
}
     		
