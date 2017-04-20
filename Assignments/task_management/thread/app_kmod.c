#include <sys/mman.h>
#include <stdio.h>
# include <pthread.h>
# include <sys/types.h>
#include <fcntl.h>
void *thread_create(void *p)
{
	printf("in thread function\n");
	pid_t pid;
    int fd;
	fd = open("/dev/myChar", O_RDWR);
	printf("pid of subthread = %d\n",getpid());
	//printf("tid of a subthread = %d\n",syscall(SYS_gettid));
	printf("sub tgid = %d\n",getgid());
	printf("sub ppid = %d\n",getppid());
	ioctl(fd,getpid(),123);
	return NULL;
}

int main()
{	
	int status,fd;
	pthread_t tid;
	status = pthread_create(&tid,NULL,thread_create,NULL);
	printf("pid of thread = %d\n",getpid());
	printf("main tgid = %d\n",getgid());
	//printf("tid of a thread = %d\n",syscall(SYS_gettid));
	int *ptr;
	pid_t pid;
	fd = open("/dev/myChar", O_RDWR);
	ioctl(fd,getpid(),123);
	if(status != 0) {
		printf("thread creation failed\n");
	}
	pthread_exit(0);
	close(fd);
	return 0;
}
