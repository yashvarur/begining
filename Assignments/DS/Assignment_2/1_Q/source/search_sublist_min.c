#include "header.h"
LIST * search_sublist_min (LIST * START)
{
	int min = 0;
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
	while (temp -> next != START) {
		if (temp -> data != val)
			temp = temp -> next;
		else {
			if (!temp -> sub_ls) {
                        printf ("no sub nodes in list");
			} else {
                        temp1 = temp -> sub_ls;
						min = temp1 -> data;
                        while (temp1 -> next != temp -> sub_ls) {
								if (temp1 -> data < min) {
                                	min = temp1 -> data;
								}
                                temp1 = temp1 -> next;
						}
						if (temp1 -> next == temp -> sub_ls) {
							if (temp1 -> data < min)
                      			  min = temp1 -> data;
							}
						printf (" Minimum in subnode is = %d\n",min);
						return START;
			}
			break;
		}

	}
	if (temp -> next == START ) {
		if (temp -> data == val) {
			if (!temp -> sub_ls) {
					printf ("no sub nodes in list");
			} else {
                        temp1 = temp -> sub_ls;
						min = temp1 -> data;
                        while (temp1 -> next != temp -> sub_ls) {
								if (temp1 -> data < min) {
                                	min = temp1 -> data;
                                }
                                temp1 = temp1 -> next;
						}
						if (temp1 -> next == temp ->sub_ls) {
							if (temp1 -> data < min)
                    			    min = temp1 -> data;
							
							}

					printf (" Minimum in subnode is = %d\n",min);
                        }

			} else {
				printf ("Main node not present\n");
				return START;
			}
	}
return START;
}
	
