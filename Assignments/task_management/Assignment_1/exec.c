# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
int main(int argc,char **argv)
{
    pid_t pid;
	char *a[10];
	a[0] = argv[1];
	a[1] = argv[2];
	a[2] = argv[3];
	a[3] = argv[4];
	a[4] = argv[5];
	a[5] = (char*)NULL;
    	pid = fork();
    	if(pid > 0) {
    	    wait(NULL);
    	    printf("end of parent\n");
    	}
    	else {
    	    execvp(a[0],a);
    	}
}
