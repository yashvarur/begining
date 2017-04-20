#include "header.h"
SUB * delete_subnode_rear (SUB * START)
{ 
	SUB * temp = START;
	if (!START) {
		printf ("Main list is empty\n");
		return START;
	}

	if (temp -> next == START ) { 
			printf ("Rear node %d is deleted\n", temp -> data);
			START = NULL;
			return START;
	}
	
			temp = START -> prev;
     		temp -> prev -> next = temp -> next;
     		temp -> next -> prev = temp -> prev;
			printf ("Rear node %d is deleted\n", temp -> data);
			free (temp);
		 	return START;
	

	return START;
}
     		
