# include "header.h"
int main()
{

        st1.top1 = -1;
        st2.top2 = -1;
        int choice;
        int ele;
        while(1) {
                printf("enter 1-enque\n");
                printf("enter 2-deque\n");
                printf("enter 3-display\n");
                printf("enter your choice\n");
                scanf("%d",&choice);
                switch(choice) {
                        case 1:
                                printf("enter the element to enque into the queue\n");
                                scanf("%d",&ele);
                                push(ele);
                                break;
                        case 2:
                                pop();
                                break;
                        case 3:
                                display();
                                break;
                        default:
                                printf("invalid choice\n");
                                break;
                }
        }
        return 0;
}

