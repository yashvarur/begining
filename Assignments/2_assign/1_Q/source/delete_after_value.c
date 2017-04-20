#include "header.h"
SUB * delete_after_value (SUB * START)
{
	int num; 
	SUB * temp1;
	SUB * temp = START;
	if (!START) {
			printf ("Main list is empty\n");
			return START;
	}
	printf ("Enter subnode value\n");
	num = read_int ();
	if (temp -> next == temp) {
			if(temp -> data == num) {
					printf ("No elements after %d to deleted\n", temp -> data);
					return START;
			} else {
					printf ("Element not present\n");
					return START;
			}
	}

	while (temp -> next != START) {
		if (temp -> data != num)
			temp = temp -> next;
	         else {
					 temp1 = temp -> next;
					 temp -> next -> next -> prev = temp;
					 temp -> next = temp -> next -> next;
					 printf ("%d is deleted\n", temp1 -> data);
					 free(temp1);
					 return START;
			 }
	}
	if (temp -> next == START ) {
		if (temp -> data == num) { 
					 temp1 = temp -> next;
					 temp -> next -> next -> prev = temp;
					 temp -> next = temp -> next -> next;
					 printf ("%d is deleted\n", temp1 -> data);
					 START = START -> next;
					 free(temp1);
		} else {
				printf ("Element not present\n");
				return START;
		}
	}

	return START;
}
     		
