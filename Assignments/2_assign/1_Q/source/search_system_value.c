#include "header.h"
LIST * search_system_value (LIST * START)
{
	int sub_val;
	if (!START) {
			printf("System is empty\n");
			return START;
	}
	LIST * temp = START;
	SUB * temp1;
        printf ("Main node elements are :\n");
	START = display_system(START);
	printf ("Enter node value to search : ");
	sub_val = read_int ();
	while (temp -> next != START) {
		if (temp -> data != sub_val) {
			if (temp -> sub_ls) {
                      
                        temp1 = temp -> sub_ls;
                        while (temp1 -> next != temp -> sub_ls) {
								if (temp1 -> data == sub_val) {
                                printf ("%d is present\n",temp1 -> data);
								return START;
								}
                                temp1 = temp1 -> next;
                                }
						if (temp1 -> next == temp -> sub_ls) {
							if (temp1 -> data == sub_val) {
                      			  printf ("%d is present\n",temp1 -> data);
								  return START;
							}
                        }
				}
		 } else { 
				 printf ("%d is present\n",temp -> data);
				 return START;
		 }
	temp = temp -> next;
	}
	if (temp -> next == START ) {
		if (temp -> data != sub_val) {
			if (temp -> sub_ls) {
                        temp1 = temp -> sub_ls;
                        while (temp1 -> next != temp -> sub_ls) {
								if (temp1 -> data == sub_val) {
                                printf ("%d is present\n",temp1 -> data);
								return START;
                                }
                                temp1 = temp1 -> next;
                                }
						if (temp1 -> next == temp ->sub_ls) {
							if (temp1 -> data == sub_val) {
                    			printf ("%d is present\n",temp1 -> data);
								return START;	
							}
						}
					}
		} else {
			printf ("%d is present\n", temp -> data);
			return START;
		}
		printf ("Element not present in entire system\n");
	}	

return START;
}
	
