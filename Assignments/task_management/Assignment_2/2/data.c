#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
# include <unistd.h>
int a = 10;
int main()
{
       int fd,i;
       pid_t pid;
	
	fd = open("/dev/myChar", O_RDWR);
	int *ptr;
	pid = vfork();
	if(pid > 0) {
		pid_t p = getpid();
		printf("parent pid = %d\n",p);
		
        printf("value of variable in parent = %d\n",a);
        
	}
	else if(pid == 0) {
		pid_t p;
		p = getpid();
		printf("child pid = %d\n",getpid());
        a = 20;
        printf("value of variable in child = %d\n",a);
		exit(0);
	}
	close(fd);
	return 0;
}
