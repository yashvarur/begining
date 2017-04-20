# include <stdio.h>
# include <sys/types.h> 
# include <sys/syscall.h> 
# include <pthread.h>

void *thread_create(void *p)
{
	int a = 10;
	printf("in thread function\n");
	printf("Address of a = %x\n",&a);
	printf("tgid of subthread = %d\n",getpid());	
	printf("pid of a subthread = %d\n",syscall(SYS_gettid));
	//printf("sub tgid = %d\n",getgid());
	//getchar();
	return NULL;
}

int main()
{	
	int b = 20;	
	int status;
	pthread_t tid;
	status = pthread_create(&tid,NULL,thread_create,NULL);
	//getchar();
	printf("-->tgid of process = %d\n",getpid());
	//printf("main tgid = %d\n",getgid());
	printf("pid of a process = %d\n",syscall(SYS_gettid));
	if(status != 0) {
		printf("thread creation failed\n");
	}
	printf("Address of b = %x\n",&b);
	pthread_exit(0);
	printf("hhhhhhhhhh\n");
	return 0;
}
