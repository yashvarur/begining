#include "header.h"
LIST * search_system_max (LIST * START)
{
	int max = 0;
	LIST * temp = START;
	SUB * temp1;
	if (!START) {
			printf("System is empty\n");
			return START;
	}
	printf ("Main node elements are :\n");
	START = display_system(START);
	max = temp -> data;
	while (temp -> next != START) {
			if (temp -> data > max)
				max = temp -> data;
			if (temp -> sub_ls) {
                        temp1 = temp -> sub_ls;
                        while (temp1 -> next != temp -> sub_ls) {
								if (temp1 -> data > max) {
                                	max = temp1 -> data;
								}
                                temp1 = temp1 -> next;
						}
						if (temp1 -> next == temp -> sub_ls) {
							if (temp1 -> data > max)
                      			  max = temp1 -> data;
							}
			}
			temp = temp -> next;
		}
	if (temp -> next == START ) {
			if (temp -> data > max)
					max = temp -> data;
			if (temp -> sub_ls) {
                        temp1 = temp -> sub_ls;
                        while (temp1 -> next != temp -> sub_ls) {
								if (temp1 -> data > max) {
                                	max = temp1 -> data;
                                }
                                temp1 = temp1 -> next;
						}
						if (temp1 -> next == temp ->sub_ls) {
							if (temp1 -> data > max)
                    			    max = temp1 -> data;
							
								}
                     	 }
			}	
	printf (" Maximum in system is = %d\n",max);
	return START;
}
	
