# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
int num =123;
int main()
{
	int fd;
	fd = open("/dev/myChar",O_RDWR);
	if(fd < 0) {
		printf("file opened failed\n");
		exit(0);
	}
	ioctl(fd,getpid(),&num);
        sleep(2);
        close(fd);
	return 0;
}
	
