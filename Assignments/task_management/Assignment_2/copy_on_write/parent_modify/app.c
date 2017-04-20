# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
int ar[1024] = {1,2,3};
int a = 10;
int main()
{
	pid_t pid;
	int fd;
	fd = open("/dev/myChar",O_RDWR);
	pid = fork();
	if(pid > 0) {	
		printf("parent process\n");
        ioctl(fd,getpid(),&a);
        a = 10;
        ioctl(fd,getpid(),&a);
	}
	else if(pid == 0) {
		printf("child process\n");
		ioctl(fd,getpid(),&a);
	}
	else
		printf("invalid\n");
}	
