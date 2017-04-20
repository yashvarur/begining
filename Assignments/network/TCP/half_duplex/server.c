# include <stdio.h>
# include <sys/types.h>
# include <string.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <stdio.h>
# define SIZE 1000
int main(int argc,char **argv)
{
	pid_t pid;
	int socket_des;	
	int a;
	socklen_t len;

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

	printf("server is waiting on port = %d\n",server.sin_port);
	if( ( a = accept(socket_des,(struct sockaddr *)NULL,NULL) ) == -1)
		printf("error in accept\n ");
    	while(1) {
			char *buf = malloc(SIZE);
			recv(a,buf,60,0);
			//recvfrom(a,buf, 60, 0, (struct sockaddr *)&server,&len);
			printf("%s",buf);
			char *buff = malloc(SIZE);
 			printf("enter the message to send\n");
 	  		fgets(buff,64,stdin);
			send(a,buff,strlen(buff),0);
    }
}

