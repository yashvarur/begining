#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd;
	fd = open("/dev/myChar", O_RDWR);
	if (fd < 0) {
		perror ("Unable to open my device");
	}
	else {
		printf ("File opened successfully %d\n",fd);
	}
	getchar();
	close(fd);
	return 0;
}
