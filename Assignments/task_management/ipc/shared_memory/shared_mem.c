# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/mman.h>
int main()
{

	int fd;
	int *p;
	fd = shm_open("/mymem",O_CREAT|O_RDWR,0777);
	if(fd == -1)
		printf("error in creating/opening the shared memory\n");
	if(ftruncate(fd,100) == -1)
		printf("error in truncating\n");
	p = mmap(NULL,100,PROT_READ|PROT_WRITE|PROT_EXEC,MAP_SHARED,fd,0);
	*(p + 0) = 246;
	printf("%p\n",p);
	close(fd);
}
	
	
