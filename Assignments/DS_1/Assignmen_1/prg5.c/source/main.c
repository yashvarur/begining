#include"header.h"
int main()
{
	NODE *start;
	start = (NODE*)malloc(sizeof(NODE));
	start = NULL;
	int c = 1;
	int choice;
	while(c == 1) {
		printf("\nENTER");
		printf("\t\t1-PUSH\n");
		printf("\t\t2-POP\n");
		printf("\t\t3-DISPLAY\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1:start = push(start);
				break;
			case 2:start = pop(start);
				break;
			case 3:display(start);
				break;
			default:exit(0);
		}
		printf("press 1-continue\n");
		scanf("%d",&c);
	}
	return 0;
}
