#include "header.h"
SUB * delete_a_value (SUB * START)
{
	int num; 
	SUB * temp = START;
	if (!START) {
			printf ("Main list is empty\n");
			return START;
	}
	printf ("Enter subnode value to delete\n");
	num = read_int ();
	if (temp -> next == temp) {
			if(temp -> data == num) {
					printf ("%d is deleted\n", temp -> data);
					START = NULL;
					return START;
			} else {
					printf ("Element not present\n");
					return START;
			}
	}
	if (START -> data == num) {
			temp -> next -> prev = temp -> prev;
			temp -> prev -> next = temp -> next;
			printf ("%d is deleted\n", temp -> data);
	     	free(temp);
			START = START -> next;
		    return START;
	}
	while (temp -> next != START) {
		if (temp -> data != num)
			temp = temp -> next;
	         else {
					 temp -> next -> prev = temp -> prev;
					 temp -> prev -> next = temp -> next;
					 printf ("%d is deleted\n", temp -> data);
					 free(temp);
					 break;
			 }
	}
	if (temp -> next == START ) {
		if (temp -> data == num) {
					 temp -> next -> prev = temp -> prev;
					 temp -> prev -> next = temp -> next;
					 printf ("%d is deleted\n", temp -> data);
					 free(temp);
		} else {
				printf ("Element not present\n");
				return START;
		}
	}





	return START;
}
     		
