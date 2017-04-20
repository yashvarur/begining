#include "header.h"
LIST * display_forward (LIST * START)
{
	int val;
	LIST * temp = START;
	SUB * temp1;
        printf ("Main node elements are :\n");
	START = display_system(START);
	printf ("select one main node \n");
	val = read_int ();
	while (temp -> next != START) {
		if (temp -> data != val)
			temp = temp -> next;
		else {
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
			break;
		}
	}
	if (temp -> next == START ) {
		if (temp -> data == val) {
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

		} else {
			printf ("Element not present\n");
			return START;
		}
	}	
return START;
}
	
