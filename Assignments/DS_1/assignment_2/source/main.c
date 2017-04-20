#include"header.h"
int main()
{
	MNODE *start;
	start = malloc(sizeof(MNODE));
	start = NULL;
	int c = 1;
	int choice;
	while(c==1) {
		printf("\t\t1-CREATION\n");
		printf("\t\t2-INSERTION\n");
		printf("\t\t3-DELETION\n");
		printf("\t\t4-SEARCH\n");
		printf("\t\t5-DISPLAY\n");
		printf("\t\t6-EXIT\n");	
		printf("\t\tenter your choice\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1: start = creation(start);
				break;
//			case 2: start = insert(start);
//				break;
			default : exit(0);
		}

	}
	return 0;
}
