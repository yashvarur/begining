#include "header.h"
LIST * create_list(LIST * list)
{
	int ch;
	printf ("SUB LIST\n");
	printf ("1 - Insert front\n2 - Insert rear\n3 - exit\n");
	ch = read_int ();
		switch ( ch ) {
				case 1 : list = insert_front(list);
					break;
				case 2 : list = insert_rear(list);
					break;	
				case 3 : exit(0);
					break;
				default : printf ("Invalid number, Enter again\n");
					break;
			}
		
	return list;
}
	
