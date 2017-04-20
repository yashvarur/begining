# include <stdio.h>
# include <fcntl.h>
# include <sys/mman.h>
int main()
{
        int a;
        int fd;
	int *p;
        fd = shm_open("/mymem",O_RDWR,0666);
        if(fd == -1)
                printf("error in creating/opening the shared memory\n");
        if(ftruncate(fd,100) == -1)
                printf("error in truncating\n");
        p = mmap(NULL,100,PROT_READ|PROT_WRITE|PROT_EXEC,MAP_SHARED,fd,0);
	    printf("%d\n",*(p + 0));
        close(fd);
}

