# include <stdio.h>
# include <string.h> 
# include <stdlib.h>
# include <unistd.h>
int main()
{

	int i = 0;
	char *a[20];
	char *path;
	char *input;
	input = malloc(100);
	path = malloc(100);
	while(1) {		
		pid_t pid;
		printf("$");
		fgets(input,20,stdin);
		*( input + ( strlen ( input ) ) - 1 ) = '\0'; /* read a command through keyboard */
		a[i] = strtok(input," ");	/* tokanising the input command */
		path = a[i];
		i++;
		do {
			a[i] = strtok(NULL," ");
		}while(a[++i]);

		if(!strcmp(path,"exit"))
			exit(0);

		pid = vfork();		/* creating the child process*/
		if(pid > 0) {
			wait(NULL);
		}
		else if(pid == 0) {
			if(path)
			execvp(path,a);	/* replace the current process by new process */
			else
			fprintf(stderr,"command not found");
		}
		else
			printf("fork failed\n");
	}
}
	

		

