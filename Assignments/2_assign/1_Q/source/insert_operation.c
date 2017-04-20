#include "header.h"
LIST * insert_operation (LIST * START)
{
	int ch;
	int val;
	LIST * temp = START;
	if (!START) {
			printf ("Main list is empty\n");
			return START;
	}
	printf ("Insert operation :-\n");
        printf ("Main node elements are :\n");
	START = display_system(START);
	printf ("select one main node \n");
	val = read_int ();
	while (temp -> next != START) {
		if (temp -> data != val)
			temp = temp -> next;
		else {
			printf ("%d node is selected from main list\n",temp -> data);
			break;
		}
	}
	if (temp -> next == START ) {
		if (temp -> data == val) {
			printf ("%d node is selected from main list\n",temp -> data);
		} else {
			printf ("Element not present\n");
			return START;
		}
	}	
	
	printf ("\n1 - Insert subnode front\n2 - Insert sub node rear\n");
	printf ("3 - Insert after a given value in list\n");
	printf ("4 - insert before a given value in list\n");
	printf ("5 - insert in given position\n6 - exit\n");
	ch = read_int ();
		switch ( ch ) {
				case 1 : temp -> sub_ls = insert_subnode_front(temp -> sub_ls);
						 break;
				case 2 : temp -> sub_ls  = insert_subnode_rear(temp -> sub_ls);
						 break;	
				case 3 : temp -> sub_ls = insert_after_value(temp -> sub_ls);
						 break;
				case 4 : temp -> sub_ls = insert_before_value(temp -> sub_ls);
						 break;
				case 5 : temp -> sub_ls = insert_at_position(temp -> sub_ls);
						 break;
				case 6 : exit(0);
					break;
				default : printf ("Invalid number, Enter again\n");
					break;
			}
		
	return START;
}
	
