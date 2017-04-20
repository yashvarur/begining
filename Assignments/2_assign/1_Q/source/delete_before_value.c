#include "header.h"
SUB * delete_before_value (SUB * START)
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
					printf ("No elements before %d to deleted\n", temp -> data);
					return START;
			} else {
					printf ("Element not present\n");
					return START;
			}
	}

	if (START -> next -> data == num) {
			temp1 = START;
     		START -> prev -> next = START -> next;
     		START -> next -> prev = START -> prev;
			printf ("%d is deleted\n", temp1 -> data);
			START = START -> next;
	    	free(temp1);
		 	return START;
	}

	while (temp -> next != START) {
		if (temp -> data != num)
			temp = temp -> next;
	         else {
					 temp1 = temp -> prev;
					 temp -> prev -> prev -> next = temp;
					 temp -> prev = temp -> prev -> prev;
					 printf ("%d is deleted\n", temp1 -> data);
					 free(temp1);
					 return START;
			 }
	}
	if (temp -> next == START ) {
		if (temp -> data == num) { 
					 temp1 = temp -> prev;
					 temp -> prev -> prev -> next = temp;
					 temp -> prev = temp -> prev -> prev;
					 printf ("%d is deleted\n", temp1 -> data);
					 free(temp1);
		} else {
				printf ("Element not present\n");
				return START;
		}
	}

	return START;
}
     		
