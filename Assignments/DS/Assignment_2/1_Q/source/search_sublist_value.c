#include "header.h"
LIST * search_sublist_value (LIST * START)
{
	int sub_val;
	int val;
	if (!START) {
			printf("Main list is empty\n");
			return START;
	}
	LIST * temp = START;
	SUB * temp1;
        printf ("Main node elements are :\n");
	START = display_system(START);
	printf ("select one main node \n");
	val = read_int ();
	printf ("Enter subnode value to search : ");
	sub_val = read_int ();
	while (temp -> next != START) {
		if (temp -> data != val)
			temp = temp -> next;
		else {
			if (!temp -> sub_ls) {
                        printf ("no sub nodes");
                        } else {
                        temp1 = temp -> sub_ls;
                        while (temp1 -> next != temp -> sub_ls) {
								if (temp1 -> data == sub_val) {
                                printf ("%d is present",temp1 -> data);
								break;
								}
                                temp1 = temp1 -> next;
                                }
						if (temp1 -> next == temp -> sub_ls) {
							if (temp1 -> data == sub_val)
                      			  printf ("%d is present",temp1 -> data);
							else {
									printf ("Sub node not present\n");
									return START;
							}
                        	}
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
								if (temp1 -> data == sub_val) {
                                printf ("%d is present",temp1 -> data);
								break;
                                }
                                temp1 = temp1 -> next;
                                }
						if (temp1 -> next == temp ->sub_ls) {
							if (temp1 -> data == sub_val)
                    			    printf ("%d is present",temp1 -> data);
							else {
									printf ("Sub node not present\n");
									return START;
							}
                        	}
						}
                printf ("\n");

		} else {
			printf ("Main node not present\n");
			return START;
		}
	}	
return START;
}
	
