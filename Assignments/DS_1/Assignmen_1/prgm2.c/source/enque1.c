#include"header.h"
void enque()
{
	int ele;
	printf("enter the element to enque\n");
	scanf("%d",&ele);
	if((q.front == -1) && (q.rear == -1))
		q.front=q.front+1;
	if(q.rear > (MAX-1)) 
		printf("queue overflow\n");

	else if( (q.front == (MAX-2)) && (q.rear == (MAX-1)) )
		printf("queue exception cant insert\n ");

	else 
		q.a[++q.rear] = ele;
}
		
		
