#include "header.h"
LIST * delete_operation (LIST * START)
{
	int ch;
	int val;
	LIST * temp = START;
	if (!START) {
			printf ("Main list is empty\n");
			return START;
	}
	printf ("Delete operation :-\n");
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
	printf ("1 - delete a value in sublist\n");
	printf ("2 - delete after a given value in sublist\n");
	printf ("3 - delete before a given value in sublist\n");
	printf ("4 - delete subnode front\n5 - delete subnode rear\n");
	printf ("6 - delete subnode in given position\n");
	printf ("7 - delete a given main list\n8 - exit\n");
	ch = read_int ();
		switch ( ch ) {
				case 1 : temp -> sub_ls = delete_a_value (temp -> sub_ls);
						 break;
				case 2 : temp -> sub_ls = delete_after_value(temp -> sub_ls);
						 break;
				case 3 : temp -> sub_ls = delete_before_value(temp -> sub_ls);
						 break;
				case 4 : temp -> sub_ls = delete_subnode_front(temp -> sub_ls);
						 break;
				case 5 : temp -> sub_ls  = delete_subnode_rear(temp -> sub_ls);
						 break;	
				case 6 : temp -> sub_ls = delete_at_position(temp -> sub_ls);
						 break;
				case 7 : START = delete_entire_list ( START, temp );
						 break;
				case 8 : exit(0);
						break;
				default : printf ("Invalid number, Enter again\n");
						break;
			}
		
	return START;
}
	
