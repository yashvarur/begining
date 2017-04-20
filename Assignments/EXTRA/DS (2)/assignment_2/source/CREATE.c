#include"header.h"
MNODE * creation(MNODE *start)
{
	int choice;
	int c = 1;
	while(c==1) {
		printf("CREATION------->");
		printf("1-insert at rear\n");
		printf("\t\t2-insert at front\n");
		printf("\t\t3-display\n");
		printf("\t\t4-exit\n");
		printf("\t\tenter your choice\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1: start = insert_rear(start);
				break;
			case 2: start = insert_front(start);
				break;
			case 3: display_main(start);
				break;
			default: return start;
			
		}
	}
	return start;
}
