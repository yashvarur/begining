#include "header.h"
SUB * insert_after_value (SUB * START)
{
	if (!START) {
			printf ("sub list is empty\n");
			return START;
	}
	int num; 
	SUB * temp = START;
	SUB * new;
	printf ("Enter subnode value\n");
	num = read_int ();
	while (temp -> next != START) {
		if (temp -> data != num)
			temp = temp -> next;
	         else {
					new = create_subnode();
					new -> next = temp -> next;
					new -> prev = temp;
					temp -> next -> prev = new;
					temp -> next = new;
					 break;
			 }
	}
	if (temp -> next == START ) {
		if (temp -> data == num) {
				new = create_subnode();
				new -> next = temp -> next;
				new -> prev = temp;
				temp -> next -> prev = new;
				temp -> next = new;

		} else {
				printf ("Element not present\n");
				return START;
		}
	}





	return START;
}
     		
