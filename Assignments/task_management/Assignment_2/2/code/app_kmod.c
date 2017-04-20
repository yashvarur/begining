#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
# include <unistd.h>
int a = 10;
int main()
{
	int fd,i;
    int pid;
	
	fd = open("/dev/myChar", O_RDWR);
	if(fd < 0) {
		perror ("Unable to open my device");
	}
	else {
		printf ("File opened successfully %d\n",fd);
	}
   
    pid = fork();
    if(pid > 0) {
           pid_t p;
           p = getpid();
           printf("parent pid = %d\n",p);
           printf("parent code section physical adress(main)=");
	       ioctl(fd, p,&a);
    }
    else if(pid == 0) { 
           pid_t  p;
           p = getpid();
           printf("child pid = %d\n",p);
           printf("child code section physical adress(main)=");
           a = 49; 
           ioctl(fd, p, &a);
           exit(0);
    }
	close(fd);
	return 0;
}
