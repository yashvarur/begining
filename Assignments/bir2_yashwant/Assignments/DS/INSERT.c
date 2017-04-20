#include"header.h"
MNODE * insert(MNODE *p)
{
	int ele;
	MNODE *temp;
	SNODE *start;
	new_sub_node = malloc(sizeof(SNODE));
	new_sub_node = NULL;

	printf("enter the main node element to insert in that particular sublist\n");
	scanf("%d",&ele);
	temp = p;
	while(temp -> snext != p) {
		if(temp -> sdata == ele) {
			printf("element is found\n");	
			break;
		}
		temp = temp -> snext;
	}
	if(temp -> snext == p) {
		if(temp -> sdata == ele){
			printf("element is found\n");
			return ;
		}
		 else
			printf("element is not found\n");
	}
	
	printf("SELECT---->");
	printf("1-insert at rear\n");	
//	printf("\t\t2-insert at front");
//	printf("\t\t3-insert at middle");
//	printf("\t\t-insert at specific position\n");
	printf("\t\t3-return to main list\n");
	printf("enter your choice\n");
	scanf("%d",&choice);
	switch(choice) {
		case 1: temp->link_sublink = insert_rear(temp->link_sublink);
			break;
	//	case 2: temp = insert_front(temp,start);
	//		break;
	//	case 3:  temp = insert_middle( temp);
	//		break;
	//	case 4:  temp -> link_sublist = insert_position( temp -> link_sublist);
	//		break;
		case 3 : return temp;
	}
}
	
	

			
			
