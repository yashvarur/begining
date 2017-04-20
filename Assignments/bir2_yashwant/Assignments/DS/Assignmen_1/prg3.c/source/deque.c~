#include"header.h"
void deque()
{
	
	if((cq.front == cq.rear)  &&  (cq.front == -1))
		printf("queue underflow\n");
	else {	
		printf("item removed is = %d\n",cq.s[cq.front]);
		cq.s[cq.front] = 0; 
		if(cq.front == cq.rear)
			cq.front = cq.rear = -1;
		else 
			cq.front = ( cq.front + 1) % MAX;
	}        
		
	
}
