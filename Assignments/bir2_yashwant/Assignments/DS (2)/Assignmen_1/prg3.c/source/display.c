#include"header.h"
void display()
{
	int i;
	if(cq.front == -1)
		printf("no content to display\n");
	
	if(cq.front<=cq.rear)
 	{
		printf("content of circular queue\n");
		for(i = cq.front ; i <=cq.rear ; i++)
			printf("%d\t",cq.s[i]);
	}
	else {
		for(i = cq.rear ; i < cq.front ; i++)
                        printf("%d\t",cq.s[i]);

		for(i=cq.front;i<MAX;i++)
			printf("%d\t",cq.s[i]);
	}	
	printf("\n");
}
