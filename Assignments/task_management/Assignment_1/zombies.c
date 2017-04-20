# include <unistd.h>
# include <stdio.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid > 0) {
		printf("parent pid = %d\n",getpid());
	//	getchar();
	}
	else if(pid == 0) {
		abort();
		printf("child = %d\n",getpid());
	}
	else
		fprintf(stderr,"error");
	return 0;
}
