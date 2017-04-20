
#define _GNU_SOURCE
# include <sys/wait.h>
# include <sys/utsname.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h> 
# include <sched.h>

#include <sys/syscall.h>
# define STACK_SIZE  8192
int thread_function(void *p);
int fun(void *p);
int process_function(void *p);
int thread_function(void *p) 
{
    	char* stack;
	int pid;
	int b = 10;
	printf("adress of b in thread = %p\n",&b);
	//printf("adress of a in thread = %p\n",(int*)p);
	printf("i am  in thread function\n ");
	printf("tgid of fun = %d\n ",getpid());	
	printf("pid of fun = %ld\n",syscall(SYS_gettid));
	getchar();
//	stack = malloc(STACK_SIZE);
  //  	int pid = clone(process_function,stack + STACK_SIZE,SIGCHLD,NULL);
    //	getchar();
    //	printf("process getchar()\n");
    	if(pid == -1)
        	printf("  thread clone failed\n");
    	else
        	printf("thread successful creation\n");
        	
}


int main()
{
	char *stack;
	int a = 10;
	void *p = &a;
	stack = malloc(STACK_SIZE);
	printf("adress of a in main = %p\n",&a);
	int pid = clone(thread_function,stack + STACK_SIZE,(CLONE_THREAD|CLONE_VM|CLONE_SIGHAND|CLONE_FS),&a);
	getchar();
    	printf("process getchar()\n");
	if(pid == -1) 
		printf("main clone creation failed\n");
	else
		printf("main successful creation\n");

		printf("main tgid of main = %d\n ",getpid());
		printf("main pid of main = %ld\n",syscall(SYS_gettid));
}
# if 0
int process_function(void *p)
{
    char *stack;
    printf("i am in processs\n");
    printf("process get tgid = %d\n",getpid());
	printf("process pid of fun = %ld\n",syscall(SYS_gettid));
	stack = malloc(STACK_SIZE);
    int pid = clone(thread_function,stack + STACK_SIZE,(CLONE_THREAD|CLONE_VM|CLONE_SIGHAND|CLONE_FS),NULL);
    
    printf("process getchar()\n");
    if(pid == -1)
        printf("  thread clone failed\n");
    else
        printf("thread successful creation\n");
    return 0;
}    
int fun(void *p)
{
    printf("hi \n");
}
# endif
