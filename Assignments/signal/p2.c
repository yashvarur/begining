#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
 
    printf("received SIGHUP\n");
}

int main(void)
{
	printf("%d\n",getpid());
  	if (signal(SIGHUP, sig_handler) == SIG_ERR)
  	printf("\ncan't catch SIGINT\n");
	while(1)
	   ;	
  return 0;
}
