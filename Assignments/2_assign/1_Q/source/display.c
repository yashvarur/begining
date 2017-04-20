#include "header.h"
LIST * display_operation (LIST * START)
{
	int ch;
	printf ("\n1 - display forward\n2 - display reverse\n");
	printf ("3 - display system \n4 - exit\n");
	ch = read_int ();
		switch ( ch ) {	
				case 1 : START = display_forward(START);
                                        break;
                                case 2 : START = display_reverse(START);
                                        break;
				case 3 : START = display_system(START);
                                        break;
				case 4 : exit(0);
					break;
				default : printf ("Invalid number, Enter again\n");
					break;
			}
		
	return START;
}
	
