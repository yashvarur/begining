#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <limits.h>

struct sub_list {
	int data;
	struct sub_list * next;
	struct sub_list * prev;
};
typedef struct sub_list SUB; 
struct list {
	int data;
	struct list * next;
	struct list * prev;
	struct sub_list * sub_ls;
	
};
typedef struct list LIST;

int read_int ();
double convert_to_int (char *);
LIST * create_list(LIST *);
LIST * insert_operation (LIST *); 
LIST * delete_operation (LIST *);
LIST * search_operation (LIST *);
LIST * display_operation (LIST *);
LIST * display_system (LIST *);
LIST * display_forward (LIST *);
LIST * display_reverse (LIST *);
LIST * insert_front (LIST *);
LIST * insert_rear (LIST *);
LIST * create_node ();
SUB * insert_subnode_front (SUB*);
SUB * insert_subnode_rear (SUB*);
SUB * insert_after_value (SUB*);
SUB * insert_before_value (SUB*);
SUB * insert_at_position (SUB*);
SUB * create_subnode ();
LIST * search_sublist_value (LIST *);
LIST * search_system_value (LIST *);
LIST * search_sublist_max (LIST *);
LIST * search_system_max (LIST *);
LIST * search_sublist_min (LIST *);
LIST * search_system_min (LIST *);
SUB * delete_a_value (SUB*);
SUB * delete_after_value (SUB*);
SUB * delete_before_value (SUB*);
SUB * delete_subnode_front (SUB*);
SUB * delete_subnode_rear (SUB*);
SUB * delete_at_position (SUB*);
LIST * delete_entire_list (LIST *, LIST *);
