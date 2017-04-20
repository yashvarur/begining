#include"header.h"
int main()
{
	int choice;
	NODE *start;
	start = malloc(sizeof(NODE));
	start = NULL;
	int c = 1;
	
	while(c==1) {
		printf("\t\t1-insert at rear\n");
		printf("\t\t2-insert at front\n");
		printf("\t\t3-delete at rear\n");
		printf("\t\t4-delete at front\n");
		printf("\t\t5-display forward\n");
		printf("\t\t6-display reverse\n");
		printf("\t\tenter your choice\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1: start = insert_rear(start);
				break;
			case 2: start = insert_front(start);
				break;
			case 3: start = delete_rear(start);
                                break;
			case 4: start = delete_front(start);
				break;
			case 5: display(start);
				break;
			case 6: display_reverse(start);
				break;
			default :exit(0);
		}

	}
	return 0;
}
