# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
void hand(int num)
{
	printf("In handler\n");
}
int fun()
{
	printf("///////////////////////\n");
	sigset_t intmask;
	if ((sigemptyset(&intmask) == -1) || (sigaddset(&intmask, SIGINT) == -1)){
  	 	perror("Failed to initialize the signal mask");
  	 	return 1;
	}
	if (sigprocmask(SIG_BLOCK, &intmask, NULL) == -1)
       		exit(1);
	signal(SIGINT,hand);
//	int *p = NULL;
//	printf("%d\n",*p);
//	printf("coming\n");
}
void sighandler(int sig_num)
{
	printf("SIGSEGV received\n");
	fun();
}

int main()
{
	int *p = NULL;
	signal(SIGSEGV,sighandler);
	printf("%d\n",*p);
	printf("blocked\n");
}
	
	
