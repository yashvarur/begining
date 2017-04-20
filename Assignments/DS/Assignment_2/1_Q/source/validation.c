#include "header.h"

int read_int()
{
    int i = 0, j, c = 1, number = 0;
    double d = 0;
    char *str = (char *) malloc(500 * sizeof(char));
    while (c) {
	i = 0;

	fgets(str, 5000, stdin);

	__fpurge(stdin);
	*(str + strlen(str) - 1) = '\0';

	while ((*(str + i) == ' ') || (*(str + i) == '\t')) { /* removing the immidiate spaces*/
	    i++;
	}

	for (j = strlen(str) - 1; j >= 0; j--) {	//to remove trailing spaces

	    if (*(str + j) != ' ' && *(str + j) != '\t'
		&& *(str + j) != '\n')
		break;
	    *(str + j) = '\0';
	}

	while (*(str + i) != '\0') {
	    if ((*(str + i) == '+') || (*(str + i) == '-')) {
		    i++;
		    if (!((*(str + i) >= 48) && (*(str + i) <= 57))) {
		        c = 1;
		        break;
		    }
	    }



	    if ((*(str + i) >= 48) && (*(str + i) <= 57)) {
		i++;
		c = 0;
	    } else {
		c = 1;
		break;
	    }
/*	if (*(str + i) ==' ') {
	while (*(str + i) != '\0') {
		if(*(str + i) != ' ') {
		 c=1;
		goto label_1;

	  	} else {
			  
	 	 	i++;
	  	}
	   }
	}*/

	}
	if (c == 1) {
	    printf("Invalid number, Enter again\n");

	} else {
	    d = convert_to_int(str);
	    if (d > INT_MAX || d < INT_MIN) {
		printf
		    ("Out of range,\n Enter valid number between range -2147483648 to +2147483647\n");
		c = 1;
	    } else
		c = 0;
	}


    }
    number = (int) d;
    return number;
}

double convert_to_int(char *str)
{
    double a = 0;
    int i = 0, f = 0;
    while ((*(str + i) == ' ') || (*(str + i) == '\t')) {
	i++;
    }

    if (*(str + i) == '-') {	// check for negative number
	i++;
	f = 1;
    }
    if (*(str + i) == '+')
	i++;

    while (*(str + i) != '\0') {
	a = a * 10 + (*(str + i) - 48);	// convert sting to integer
	i++;
    }
    if (f) {
	a = 0 - a;
    }
    // d=(double)a;    
    return a;
}
