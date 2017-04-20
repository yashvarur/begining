# if 1
# include <stdio.h>
struct stack_1
{
	int a[10];
	int top1;
}st1;

struct stack_2
{
	int b[10];
	int top2;
}st2;


void push(int);
void pop();
void display();
void display_1();
int pop1();
void push1(int ele);

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

void display()
{
	int i;
	i = st1.top1;
	for(;i >= 0 ;i--)
		printf("%d\t",st1.a[i]);
	printf("\n");
}

void push(int ele)
{
	int i;
	if(st1.top1 > 10)
		printf("stack overflow\n");
	else 
		st1.a[++st1.top1] = ele;
		
}
void pop()
{
	int i;
	int j;
	if(st1.top1 < 0)
		printf("no element to pop\n");
	else {
		j =  st1.top1;
		for(i = 0; i < j; i++) {
			push1(st1.a[st1.top1--]);
		}
		printf("poped element = %d\n",st1.a[st1.top1--]);
		i = st2.top2;
		for(;i >= 0; i--)
			push(pop1());

	}				
}

int pop1()
{
	if(st2.top2 < 0)
		printf("no element stack over flow in stack2\n");
	else 
		return st2.b[st2.top2--];
}

void push1(int ele)
{
	if(st2.top2 > 10)
		printf("stack2 overflow\n");
	else
		st2.b[++st2.top2] = ele;
}
	
# endif	
		
	

