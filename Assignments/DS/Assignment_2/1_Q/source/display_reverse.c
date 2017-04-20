#include "header.h"
LIST * display_reverse (LIST * START)
{
	int val;
	LIST * temp = START;
	SUB * temp1 , * temp2;
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
                        temp1 = temp -> sub_ls -> prev;
			temp2 = temp1;
                        while (temp2 -> prev != temp1) {
                                printf ("%d ",temp2 -> data);
                                temp2 = temp2 -> prev;
                                }
                        printf ("%d ",temp2 -> data);
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
                        temp1 = temp -> sub_ls -> next;
			temp2 = temp1;
                        while (temp2 -> prev != temp1) {
                                printf ("%d ",temp2 -> data);
                                temp2 = temp2 -> prev;
                                }
                        printf ("%d ",temp2 -> data);
                        }
                printf ("\n");

		} else {
			printf ("Element not present\n");
			return START;
		}
	}	
return START;
}
	
