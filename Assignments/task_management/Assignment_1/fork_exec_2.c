# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
int main()
{
    pid_t pid;
    pid = fork();
    if(pid > 0) {
        printf("Parent process\n");
        wait(NULL);
    }
    else(pid == 0) {
        printf("In Child\n");
        execv

   }

