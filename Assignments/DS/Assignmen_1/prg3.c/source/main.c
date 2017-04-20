#include"header.h"
int main()
{
	int choice,c = 1;
	cq.front = -1;
	cq.rear = -1;
	while(c == 1) {
		printf("\n*****CIRCULAR ARRAY******\n");
		printf("\n\nENTER");
		printf("\t1-ENQUE\n");
		printf("\t2-DEQUE\n");
		printf("\t3-DISPLAY\n");
		printf("\tPRESS ANY OTHER BUTTON TO EXIT\n");
		printf("***************************\n");		
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1: enque();
				break;
			case 2: deque();
				break;
			case 3: display();
				break;
			default:exit(0);
		}
		printf("do you want to continue...? press-1\n");
		scanf("%d",&c);
	}
	return 0;
}
	
