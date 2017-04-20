# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
int main()
{
	int fd;
	fd = open("/dev/myChar",O_RDWR);
	if( fd < 0 ) {
		printf("file open failed\n");
	}
	else {
		ioctl(fd,getpid(),23);
	}
}	
		
