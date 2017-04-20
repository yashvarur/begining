#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int fd[2];

pthread_mutex_t mutex;

/*This function continously reads fd[0] for any input data byte If available, prints */

void *reader()
{
	
	char *ptr = malloc(200);
	int result;
	char ch;
	sleep(5);
	printf("Locking the mutex\n");
	pthread_mutex_lock(&mutex);
	close(fd[1]);
	int f = 1;
	while(1) {	
		result = read (fd[0],&ch,1);
		if(result != 1) {
			//perror("read");
			break;	
		}
		printf("READER ==> %c\n",ch);	
	}
	printf("Unlocking the mutex\n");
	pthread_mutex_unlock(&mutex);
}

/*This function continously writes Capital Alphabet into fd[1] Waits if no more space is available*/

void *writer_ABC()
{
	int result;
	pthread_mutex_lock(&mutex);	
	char ch='A';
	while(ch != 'Z'){
		result = write(fd[1],&ch,1);
		if (result != 1){
				perror
					("write");
				exit(2);
		}
		printf("Writer_ABC:%c\n",ch);
		ch++;
	}
	result = write(fd[1],&ch,1);
	if (result != 1){
			perror("write");
				exit(2);
	}
	printf("Writer_ABC:%c\n",ch);
	pthread_mutex_unlock(&mutex);
}

/* This function continously writes small Alphabet into fd[1] Waits if no more space is available */
void * writer_abc()
{
	int result;
	pthread_mutex_lock(&mutex);
	char ch='a';
	while(ch != 'z'){
		result =write(fd[1],&ch,1);
		
		if(result != 1){
				perror("write");
				exit(2);
		}
		printf("Writer_abc:%c\n",ch);
		if(ch == 'z')
			ch ='a'-1;
		ch++;
	}
	result = write(fd[1],&ch,1);
	if(result != 1){
			perror("write");
			exit(2);
	}
	printf("Writer_abc:%c\n",ch);
	pthread_mutex_unlock(&mutex);
}

int main()
{
	pthread_t tid1,tid2,tid3;
	int result;
	result = pipe(fd);
	if(result < 0){
			perror("pipe");
			exit(1);
	}

	pthread_create(&tid2,NULL,writer_ABC,NULL);
	pthread_create(&tid3,NULL,writer_abc,NULL);
	pthread_create(&tid1,NULL,reader,NULL);

	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
	pthread_join(tid1,NULL);
}
