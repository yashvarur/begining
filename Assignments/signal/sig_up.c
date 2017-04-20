#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#if 0
void sig_handler(int signo)
{
  printf("%d\n",signo);
  if (signo == SIGINT)
    printf("received SIGINT\n");
}
#endif
int main(void)
{
  	if (signal(SIGINT, sig_handler) == SIG_ERR)
  	printf("\ncan't catch SIGINT\n");
	while(1)
	   ;	
  return 0;
}
