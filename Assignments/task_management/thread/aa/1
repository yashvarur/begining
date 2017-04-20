# include <stdio.h>
# include <sys/types.h>
# include <sys/syscall.h> 
int main()
{
     printf("tgid = %d\n",getgid());
     printf("pid of a subthread = %d\n",syscall(SYS_gettid)); 
     return 0;
 
}
