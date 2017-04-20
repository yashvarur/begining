#include "header.h"
LIST * search_operation (LIST * START)
{
	int ch;
	
	printf ("\n1 - Search sublist value\n2 - Search system value\n");
	printf ("3 - Search maximum in sublist\n");
	printf ("4 - Search maximum in system\n");
	printf ("5 - Search minimum in sublist\n");
	printf ("6 - Search miminum in system\n7 - exit\n");
	ch = read_int ();
		switch ( ch ) {
				case 1 : START = search_sublist_value (START);
						 break;
				case 2 : START = search_system_value (START);
						 break;	
				case 3 : START = search_sublist_max (START);
						 break;
				case 4 : START = search_system_max (START);
						 break;
				case 5 : START = search_sublist_min (START);
						 break;
				case 6 : START = search_system_min (START);
						 break;
				case 7 : exit(0);
					break;
				default : printf ("Invalid number, Enter again\n");
					break;
			}
		
	return START;
}
	
