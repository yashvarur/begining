#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
int a = 10;
int main()
{
	int fd,i;
       	int pid;
	
	fd = open("/dev/myChar", O_RDWR);
	int *ptr;
	if (fd < 0) {
		perror ("Unable to open my device");
	}
	else {
		printf ("File opened successfully %d\n",fd);
	}
	printf("==>%u\n",&a);
	ioctl(fd, pid, &a);
    	getchar();
        printf("value of a = %d\n",a);
	close(fd);
	return 0;
}
