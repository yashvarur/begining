#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
int a = 10;
int main()
{
	int fd,i;
       
	

	int *ptr;
	#if 0
	if (fd < 0) {
		perror ("Unable to open my device");
	}
	else {
		printf ("File opened successfully %d\n",fd);
	}
	#endif
	pid_t pid;
	pid = vfork();
	fd = open("/dev/myChar", O_RDWR);
	if(pid > 0) {
        pid_t p;
	printf("file descriptor in parent = %d\n",fd);
        p = getpid();
		printf("parent\n");	
		ioctl(fd, p, &a);
    	}
	else if(pid == 0) {
        pid_t p;
        p = getpid();
		
	printf("file descriptor in child = %d\n",fd);
		printf("child\n");
		ioctl(fd, p, &a);
		exit(0);
	}
        
	close(fd);
	return 0;
}
