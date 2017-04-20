# define  _GNU_SOURCE
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
void *thread_function(char*p)
{
	printf("i am in thread function\n");
	int i = 0;
        char *a[20];
        char *path;
        char *input;
        input = malloc(10);
        path = malloc(10);
        pid_t pid;
	    int fd = open("/dev/mychar",O_RDWR);
	    ioctl(fd,getpid(),123);
        printf("$");
        fgets(input,10,stdin);
        *( input + ( strlen ( input ) ) - 1 ) = '\0';
        a[i] = strtok(input," ");
        path = a[i];
        printf("strtok = %s\n",path);
        i++;
        do {
                a[i] = strtok(NULL," ");
         }while(a[++i]);

         pid = fork();
         if(pid > 0) {
                    wait(NULL);
         }
         else if(pid == 0) {
                   execvp(path,a);
                   fprintf(stderr,"command not found");
         }
         else
                 printf("fork failed\n");

}
	

int main(int argc,char**argv)
{
	pthread_t tid;
	int status;
	int fd;
        fd = open("/dev/myChar",getpid(),123);
	ioctl(fd,getpid(),123);
	status = pthread_create(&tid,NULL,thread_function,NULL);
	if(status != 0) {
		printf("thrad creation failed\n");
	}
    printf("coming\n");
	ioctl(fd,getpid(),123);
	pthread_exit(0);
	return 0;
}
