#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
# include <unistd.h>
int main()
{
       int fd,i;
       pid_t pid;
	
	fd = open("/dev/myChar", O_RDWR);
	int *ptr;
	pid = fork();
	if(pid > 0) {
		pid_t p = getpid();
		printf("parent pid = %d\n",p);
		ioctl(fd,p,128);
	}
	else if(pid == 0) {
		pid_t p;
		p = getpid();
		printf("child pid = %d\n",getpid());
		ioctl(fd, pid,128);
        exit(0);
	}
	close(fd);
	return 0;
}
