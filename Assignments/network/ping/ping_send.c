#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <linux/ip.h>
#include <linux/icmp.h>
#include <string.h>
#include <unistd.h>
# define SIZE 2000
char sendbuf [SIZE];
char recvbuf[SIZE];
int main()
{
	int fd;
	int len;
	struct icmphdr *icmp;
	struct sockaddr_in send;
	send.sin_family = AF_INET;
	send.sin_addr.s_addr = inet_addr("172.16.6.136");
	icmp = (struct icmphdr *)sendbuf;
	icmp -> type = ICMP_ECHO;
	icmp -> code = 0;
	len = sizeof(recvbuf);
	fd = socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);
	if(sendto(fd,sendbuf,20,0,(struct sockaddr*)&send,sizeof(send)));
		printf("send %d size of data\n",sizeof(sendbuf));
	if(fd,recvbuf,20,0,(struct sockaddr*)&send,&len)
		printf("%d data is received\n",sizeof(recvbuf));
		printf("%c\n",recvbuf[0]);
	
	return 0;
}
