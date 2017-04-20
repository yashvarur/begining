#include"header.h"
int main()
{
	int c=1;
	int choice;
	q.front = -1;
	q.rear = -1;
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
		case 1: enque();
			break;
		case 2: deque();
			break;
		case 3: display();
			break;
		default: exit(0);
	}
	printf("press 1-to continue\n");
	scanf("%d",&c);
	}
	return 0;
}
