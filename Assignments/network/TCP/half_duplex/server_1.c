# include <stdio.h>
# include <sys/types.h>
# include <string.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <stdio.h>
# include <sys/socket.h>
# include <sys/socket.h>
# define SIZE 1000
void func(int sock)
{
    char *buf = malloc(SIZE);
    recv(sock,buf,60,0);
    printf("%s",buf);
    char *buff = malloc(SIZE);
    printf("enter the message to send\n");
    fgets(buff,64,stdin);
    send(sock,buff,strlen(buff),0);
}

int main(int argc,char **argv)
{
	pid_t pid;
	int socket_des;	
	int a;

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(atoi(argv[1]));
 	socket_des = socket(AF_INET,SOCK_STREAM,0);
	if(socket_des == -1)
		printf("error in socket creation\n");
	if(bind(socket_des,(struct sockaddr *)&server,sizeof(server)) == -1 )
		printf("error in binding\n");
	if(listen(socket_des,SOMAXCONN) == -1)
		printf("error in listen\n");
    while(1) {
	    if( ( a = accept(socket_des,(struct sockaddr *)NULL,NULL) ) == -1)
		    printf("error in accept\n ");
        pid = fork();
        if(pid == 0) {
            close(socket_des);
            func(a);
            exit(0);
        }
        else 
            close(a);
         /*
		char *buf = malloc(SIZE);
		recv(a,buf,60,0);
		printf("%s",buf);
		char *buff = malloc(SIZE);
 		printf("enter the message to send\n");
   		fgets(buff,64,stdin);
                send(a,buff,strlen(buff),0);*/
    }
}

