#include "header.h"
LIST * display_system (LIST * START)
{
	LIST * temp;
	temp = START;
	SUB * temp1;
	if ( !START ) {
		printf ("No elements to display\n");
		return START;
	}
	while (temp -> next != START) {
		printf ("%d | ",temp -> data);
		if (!temp -> sub_ls) {
			printf ("no sub nodes");
			} else {
			temp1 = temp -> sub_ls;
			while (temp1 -> next != temp -> sub_ls) {
				printf ("%d ",temp1 -> data);
				temp1 = temp1 -> next;
				}
			printf ("%d ",temp1 -> data);
			}
		printf ("\n");
		temp = temp -> next;
	}
	if (temp -> data) {// its to check delete_rear 
		printf ("%d | ",temp ->data);
		if (!temp -> sub_ls) {
			printf ("no sub elements");
			} else {
			 temp1 = temp -> sub_ls;
                        while (temp1 -> next != temp -> sub_ls) {
                                printf ("%d ",temp1 -> data);
                                temp1 = temp1 -> next;
                                }
			printf ("%d ", temp1 -> data );
			}
			printf ("\n");
		}
	
	return START;
}
