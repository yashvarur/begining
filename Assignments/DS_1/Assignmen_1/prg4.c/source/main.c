#include"header.h"
int main()
{
	NODE *start;
	int c = 1;
	int ch;
	start = (NODE*)malloc(sizeof(NODE));
	start = NULL;
	while(c == 1) {
		printf("ENTER\n");
		printf("\t1-insert at rear\n\t2-insert at front\n\t3-insert at middle\n");
		printf("\t4-insert at specified position\n\t5-delete at rear\n\t6-delete at front\n");
		printf("\t7-delete at middle\n\t8-delete at specified position\n\t9-display\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch) {
			case 1:start = insert_rear(start);
		       		break;
			case 2: start = insert_front(start);
		       		break;
			case 3: start = insert_middle(start);
				break;
			case 4: start = insert_position(start);
				break;
			case 5: start = delete_rear(start);
				break;
			case 6: start = delete_front(start);
				break;
			case 7: start = delete_middle(start);
				break;
			case 8: start = delete_position(start);
				break;
			case 9: display(start);
				break;
		       default: exit(0);
		}
		printf("press 1-to continue\n");
		scanf("%d",&c);
	}

	return 0;
}
