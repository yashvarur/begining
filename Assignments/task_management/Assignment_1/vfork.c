# include <stdio.h>
# include <unistd.h>
int a = 10;
int main()
{
	pid_t pid;
	pid = vfork();
	register int b = 40;


	if(pid > 0) {
		wait(NULL);
		printf("parent\n");
		printf("%u\n",&a);
		printf("%d\n",a);
		printf ("b = %d\n",b);

	}
	else {


		printf("%u\n",&a);

		a = 20;
		b = 10;
		printf("Child\n");
		exit(0);
	}
	return 0;
}

