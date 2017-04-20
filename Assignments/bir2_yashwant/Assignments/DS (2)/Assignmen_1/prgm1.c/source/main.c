#include"header.h"
int main()
{
	int choice;
	int ele;
	int pos;
	int item;
	int c = 1;	
	st.top = -1;	
	while(c == 1) {
		printf("************MENU*******************");
		printf ("\n\nENTER\t\t\t");
		printf ("1-PUSH\n");
		printf ("\t\t\t2-POP\n");
		printf ("\t\t\t3-DISPLAY\n");
		printf("\t\t\t4-PUSH-required position\n");
		printf("\t\t\t5-POP-the element in required position\n");
		printf("PRESS ANY OTHER BUTTON TO EXIT\n");
		printf("***********************************");
		printf ("\nenter your choice\n");
		scanf ("%d",&choice);
		switch(choice) {	
			case 1: printf ("enter the element to push\n");
				scanf("%d",&ele);
				push(ele);
				break;

			case 2: pop();
				break;

			case 3: printf ("CONTENT OF STACK\n");
				display();
				break;

			case 4: printf("enter the element to push\n");
				scanf("%d",&item);
				printf("enter the position to insert the element\n");
				scanf("%d",&pos);
				pushn(pos,item);
				break;

			case 5: printf("enter the position to delete that element\n");
                                scanf("%d",&pos);
                                popn(pos);
                                break;

			default: exit(0);
		}
		printf("\npress-1 continue\n");
		scanf("%d",&c);
	}
	return 0;
}

