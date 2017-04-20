#include "header.h"
LIST * search_system_min (LIST * START)
{
	int min = 0;
	LIST * temp = START;
	SUB * temp1;
	if (!START) {
			printf("System is empty\n");
			return START;
	}
	printf ("Main node elements are :\n");
	START = display_system(START);
	min = temp -> data;
	while (temp -> next != START) {
			if (temp -> data < min)
				min = temp -> data;
			if (temp -> sub_ls) {
                        temp1 = temp -> sub_ls;
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
			}
			temp = temp -> next;
		}
	if (temp -> next == START ) {
			if (temp -> data < min)
					min = temp -> data;
			if (temp -> sub_ls) {
                        temp1 = temp -> sub_ls;
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
                     	 }
			}	
	printf (" Minimum in system is = %d\n",min);
	return START;
}
	
