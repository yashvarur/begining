#include "header.h"
SUB * insert_at_position (SUB * START)
{
	if (!START) {
		printf ("sub list is empty\n");
		return START;
	}

	int num; 
	int count = 1;
	SUB * temp = START;
	SUB * new;
	printf ("Enter position in sublist to insert\n");
	num = read_int ();
	while (temp -> next != START) {
		if (count != num) {
			temp = temp -> next;
			count ++;
		}  else {
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
		if (count == num) { 
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
				printf ("Out of range\n");
				return START;
		}
	}





	return START;
}
     		
