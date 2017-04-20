#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd;
    int pid;
    int a = 123;
	fd = open("/dev/myChar", O_RDWR);
    pid = getpid();
    printf("%d\n",pid);
	if (fd < 0) {
		perror ("Unable to open my device");
	}
	else {
		printf ("File opened successfully %d\n",fd);
	}
    ioctl(fd,pid,a);
	getchar();
	close(fd);
	return 0;
}
