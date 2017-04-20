# include <stdio.h>
# include <sys/mman.h>
# include <fcntl.h>           /* For O_* constants */
# include <sys/stat.h>        /* For mode constants */
# include <semaphore.h>
int main()
{
        int fd;
        int *p;
        sem_t *sem;
        sem = sem_open("/sem1",O_RDWR);
		printf("%d\n",sem);
        fd = shm_open("/mem1",O_CREAT|O_RDWR,0777);
        if(fd == -1)
                printf("error in creating/opening the shared memory\n");
        if(ftruncate(fd,100) == -1)
                printf("error in truncating\n");
        p = mmap(NULL,100,PROT_READ|PROT_WRITE|PROT_EXEC,MAP_SHARED,fd,0); 
        sem_post(sem);	
       	*(p + 0) = 10;
	printf("value in p2 = %d\n",*p);
	getchar();
         return 0;
}

