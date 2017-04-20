# include <unistd.h>
# include <stdio.h>
int main()
{
      pid_t pid;
      int a = 10;
      pid = vfork();
      if( pid > 0 ) {
            printf("parent\n");
            printf("parent pid = %d\n",getpid());
            printf("value of a in parent = %d\n",a);
            wait(NULL);
            printf("value of a in child after changing into parent = %d\n",a);
       }
       else if(pid == 0) {
           printf("child\n");
           printf("child pid = %d\n",getpid());
           a = 20;
           printf("value of a in child = %d\n",a);
           exit(0);
       }
       return 0;
}

