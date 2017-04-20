# include <stdio.h>
# include <signal.h>
# include <unistd.h>
void sig_handler(int signum)
{
	printf("signal recevied\n");
}
int main()
{
	pid_t pid;
  	signal(SIGUSR1,sig_handler);
	pid = fork();
	if(pid == 0) {

			printf("child process %d\n",getpid());
			kill(pid,SIGUSR1);
			exit(0);
			printf("*************\n");
	}
	else {
		wait(0);
		printf("parent %d\n",getpid());
		
	}
	
	printf("execution finished\n");
	return 0;
}
