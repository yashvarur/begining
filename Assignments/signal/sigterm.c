#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

volatile sig_atomic_t done = 0;

void term(int signum)
{
	done = 1;
}

int main(int argc, char *argv[])
{
	struct sigaction action;
	memset(&action, 0, sizeof(struct sigaction));
	action.sa_handler = term;
	sigaction(SIGHUP, &action, NULL);

	int loop = 0;
	while (!done)
	{
		printf("pid = %d\n",getpid());
		int t = sleep(10);
		/* sleep returns the number of seconds left if
		 * interrupted */
		printf("********* %d\n",t);
		while (t > 0)
		{
			printf("Loop run was interrupted with %d "
			       "sec to go, finishing...\n", t);
			t = sleep(t);
		}
		printf("Finished loop run %d.\n", loop++);
	}

	printf("done.\n");
	return 0;
}
