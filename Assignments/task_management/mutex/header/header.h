# define _GNU_SOURCE
# include <time.h>
# include <sched.h>
# include <stdlib.h>
# define STACK_SIZE 8195
# include <stdio.h>
# include <sys/wait.h>
# include <sys/utsname.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sched.h>
# include <sys/syscall.h>
typedef struct list
{
	int seconds;
	 int sec;
	char *msg;
	struct list *next;
}NODE;
typedef struct mutex_struct
{
        pthread_mutex_t mutex;
        NODE *head;
}MUTEX;

char line[100];
void insert(NODE* new_node);
void thread_fun(void*p);
NODE *head = NULL;
NODE *create_node(int sec,char *m);
void display(NODE *head);
MUTEX *data;

