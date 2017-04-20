# include <unistd.h>
# include <stdio.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid > 0) {
		printf("parent pid = %d\n",getpid());

	}
	else if(pid == 0) {
		printf("child = %d\n",getpid());
		getchar();
		printf("parent terminated\n");
	}
	else
		fprintf(stderr,"error");
	return 0;
}
