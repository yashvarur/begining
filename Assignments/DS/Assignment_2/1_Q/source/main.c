#include "header.h"
int main()
{
	int ch;
	LIST * list;
	list = (LIST * ) malloc (sizeof(LIST));
	list = NULL;
	while (1) {
	printf ("MAIN LIST\n");
	printf ("Enter your choice\n");
	printf ("1 - Creation of list\n2 - Insert operation\n3 - Delete operation\n");
	printf ("4 - search operation\n5 - display operation\n6 - exit\n");
	ch = read_int ();
		switch ( ch ) {
				case 1 : list = create_list(list);
					break;
				case 2 : list = insert_operation(list);
					break;	
				case 3 : list = delete_operation(list);
					break;
				case 4 : list = search_operation(list);
					break;
				case 5 :printf ("elements of nodes are\n"); 
					list = display_operation(list);
					break;
				case 6 : exit(0);
					break;
				default : printf ("Invalid number, Enter again\n");
					break;
			}
		}
	return 0;
}
	
