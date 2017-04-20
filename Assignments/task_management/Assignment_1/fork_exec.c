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
	int flag = 0;
	input = malloc(10);
	path = malloc(10);
	while(1) {		
		pid_t pid;
		printf("$");
		fgets(input,10,stdin);
		*( input + ( strlen ( input ) ) - 1 ) = '\0';
		a[i] = strtok(input," ");
	 	path = a[i];
		i++;
		do {
			a[i] = strtok(NULL," \n");
		}while(a[++i]);
		if(strcmp(path,"exit") == 0)
			exit(0);
		pid = fork();
		if(pid > 0) {
			wait(NULL);
	            	//printf("%s\n",a[i]);
		}
		else if(pid == 0) {
			printf("==>%s\n",path);
			execvp(path,a);
			fprintf(stderr,"command not found");
		}
		else
			printf("fork failed\n");
	}
}
	

		

