#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
int a = 10;
int main()
{
	int fd,i;
      pid_t  pid;
	fd = open("/dev/myChar", O_RDWR);
	if (fd < 0) {
		perror ("Unable to open my device");
	}
	else {
		printf ("File opened successfully %d\n",fd);
	}
    pid = vfork();
	if(pid > 0) {
		pid = getpid();
		printf("parent\n");
		ioctl(fd, pid, &a);
	}
    else if(pid == 0) {
		    printf("child\n");
		    pid = getpid();
		    ioctl(fd,pid,&a);
            
	}
	close(fd);
	return 0;
}
