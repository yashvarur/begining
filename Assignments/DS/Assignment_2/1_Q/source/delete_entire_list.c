#include "header.h"
LIST * delete_entire_list (LIST * START, LIST * temp)
{
	if (!START) {
			printf ("No main nodes\n");
			return START;
	}
	if (temp == START) {
		if (temp -> next == START) {
				printf ("%d is deleted\n",temp -> data);
				free (START);
				START = NULL;
				return START;
		} else {
				temp -> prev -> next = temp -> next;
				temp -> next -> prev = temp -> prev;
			    printf ("%d is deleted\n", temp -> data);
				START = START -> next;
			    free (temp);
				return START;
		}
	}
	
	temp -> prev -> next = temp -> next;
	temp -> next -> prev = temp -> prev;
	printf ("%d is deleted\n", temp -> data);
	free (temp);
	return START;
}
     		
