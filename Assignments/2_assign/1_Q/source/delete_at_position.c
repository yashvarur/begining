#include "header.h"
SUB * delete_at_position (SUB * START)
{
	if (!START) {
			printf ("no sub elements in list\n");
			return START;
	}
	int num; 
	int count = 1;
	SUB * temp = START;
	printf ("Enter position in sublist to delete\n");
	num = read_int ();
	if (num == 1) {
			START = delete_subnode_front(START);
			return START;
	}
	while (temp -> next != START) {
		if (count != num) {
			temp = temp -> next;
			count ++;
		}  else {
							temp -> prev -> next = temp -> next;
							temp -> next -> prev = temp -> prev;
							printf ("%d is deleted\n", temp -> data);
							free (temp);
					        return START;
			 }
	}
	if (temp -> next == START ) {
		if (count == num) { 
				temp -> prev -> next = temp -> next;
				temp -> next -> prev = temp -> prev;
				printf ("%d is deleted\n", temp -> data);
				free (temp);
		        return START;	
		} else {
				printf ("Out of range\n");
				return START;
		}
	}
	return START;
}
     		
