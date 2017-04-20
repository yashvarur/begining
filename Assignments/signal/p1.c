# include <stdio.h>
# include <signal.h>
# include <unistd.h>
void handler(int num) {
	printf("signal caught\n");	
}
int main()
{
	pid_t pid;
	pid = fork();
	signal(SIGKILL,handler);
	if(pid) {
		printf("Parent\n");
		wait(NULL);
		printf("PPPPPP\n");
	}
	else {
		printf("child\n");
		kill(getppid(),SIGKILL);
		printf("dfllkdfjgldk\n");
	}
	return 0;
}
	
