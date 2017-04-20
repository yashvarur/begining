#include "header.h"
SUB * delete_subnode_front (SUB * START)
{ 
	SUB * temp1;
	SUB * temp = START;
	if (!START) {
		printf ("Main list is empty\n");
		return START;
	}

	if (temp -> next == START ) { 
			printf ("Front node %d is deleted\n", temp -> data);
			START = NULL;
			return START;
	}
	
			temp1 = START;
     		START -> prev -> next = START -> next;
     		START -> next -> prev = START -> prev;
			printf ("Front node %d is deleted\n", temp1 -> data);
			START = START -> next;
			free (temp1);
		 	return START;
	

	return START;
}
     		
