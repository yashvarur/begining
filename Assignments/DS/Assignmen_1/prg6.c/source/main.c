#include"header.h"
int main()
{
	int c=1;
	int choice;
	NODE *start;
	start = (NODE*)malloc(sizeof(NODE));
	start = NULL;
	while(c == 1) {
	printf("\n");
	printf("*********MENU**********\n");
	printf("ENTER\t");
	printf("1-ENQUE");
	printf("\n\t2-DEQUE");
	printf("\n\t3-DISPLAY\n");
	printf("\tPRESS ANY OTHER BUTTON TO EXIT\n");
	printf("***********************\n");
	printf("enter your choice\n");
	scanf("%d",&choice);
	switch(choice) {
		case 1:start= enque(start);
			break;
		case 2:start= deque(start);
			break;
		case 3: display(start);
			break;
		default: exit(0);
	}
	printf("press 1-to continue\n");
	scanf("%d",&c);
	}
	return 0;
}
