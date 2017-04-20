# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
int main(int argc, char *argv[])
{
	char *a[10];
	a[0] = argv[1];
	a[1] = argv[2];
	a[2] = argv[3];
	a[3] = argv[4];
	a[4] = argv[5];
	a[5] = (char*)NULL;
	pid_t pid = vfork();
	if(pid > 0 ) {
  		printf("parent\n");
		wait(NULL);
        	printf("parent at last\n");
	}
	else if(pid == 0) {
		printf("child\n");
		execvp(a[0],a);
		//exit(0);
	}
	
	return 0;
} 
