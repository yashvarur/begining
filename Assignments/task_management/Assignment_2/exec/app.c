# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
int main(int argc,char **argv)
{
    pid_t pid;
    int fd;
    char *a[10];
    a[0] = argv[1];
    a[1] = argv[2];
    a[2] = argv[3];
    a[3] = argv[4];
    a[4] = (char*)NULL;

    fd = open("/dev/myChar",O_RDWR);
    pid = vfork();
    if(pid > 0) {
          printf("parent id = %d\n",getpid());
        wait(NULL);
       ioctl(fd,getpid(),123);
    }
    else if(pid == 0) {
        printf("child\n");
        ioctl(fd,getpid(),123);
        execvp(a[0],a);
        printf("exec\n");

    }
    return 0;
}
