#include "header.h"
SUB * insert_before_value (SUB * START)
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
					if (temp == START) {
							new = create_subnode();
							new -> next = START;
							new -> prev = START -> prev;
							START -> prev -> next = new;
							START -> prev = new;
							START = new;
							break;
					} else {
							new = create_subnode();
							new -> prev = temp -> prev;
							new -> next = temp;
							temp -> prev -> next = new;
							temp -> prev = new;
					        break;
					}
			 }
	}
	if (temp -> next == START ) {
		if (temp -> data == num) {
				if (temp == START) {
						new = create_subnode();
						new -> next = START;
						new -> prev = START;
						START -> next = new;
						START -> prev = new;
						START = new;
				} else {

				new = create_subnode();
				new -> prev = temp -> prev;
				new -> next = temp;
				temp -> prev -> next = new;
				temp -> prev = new;
				}
		} else {
				printf ("Element not present\n");
				return START;
		}
	}





	return START;
}
     		
