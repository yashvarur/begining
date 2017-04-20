#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd,i;
	fd = open("/dev/myChar", O_RDWR);
	int *ptr;
	if (fd < 0) {
		perror ("Unable to open my device");
	}
	else {
		printf ("File opened successfully %d\n",fd);
	}
	ptr = mmap(NULL, 0x10000000, PROT_WRITE |PROT_EXEC,MAP_SHARED, fd, 0);
	printf("%x\n",ptr);
  //  *ptr = 1i0;
  //  printf("gggg\n");
    for (i = 0;i < 0x10000000 / 4; i++) {
        *(ptr + i) = 0x12909;
    }
//    printf("goo");
    getchar();
	close(fd);
	return 0;
}
