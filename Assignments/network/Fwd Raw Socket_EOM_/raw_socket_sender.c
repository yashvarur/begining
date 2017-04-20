#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/tcp.h>
#define MAX 1024


struct iphdr1
{
    unsigned char ihl:4, version:4;
    unsigned char tos;
    unsigned short tot_len;
    unsigned short id;
    unsigned short frag_off;
    unsigned char ttl;
    unsigned char protocol;
    unsigned short check;
    __be32 saddr;
    __be32 daddr;
};

int main ()
{
    struct sockaddr_in saddr, daddr;
    struct iphdr1 *ip;
    char *buffer = (char *) malloc (2000);
    int sock;

    ip = (struct iphdr1 *) buffer;
    ip -> ihl = 5;
    ip -> version = 4;
    ip -> tos = 0;
    ip -> tot_len = 25;
    ip -> protocol = IPPROTO_RAW;
    daddr.sin_addr.s_addr = inet_addr("172.16.9.136");
    daddr.sin_family = AF_INET;

    ip->saddr = saddr.sin_addr.s_addr;
    ip->daddr = daddr.sin_addr.s_addr;
    sock = socket (AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sock < 0){
        perror("socket failed");
        exit(1);
    }
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("172.16.9.136");
#if 0
    s_addr.sin_addr.s_addr = inet_addr ("172.16.5.190"); 
    d_addr.sin_addr.s_addr = inet_addr ("172.16.5.190"); 
    d_addr.sin_family = AF_INET;

    ip -> saddr = s_addr.sin_addr.s_addr;
    ip -> daddr = d_addr.sin_addr.s_addr;

    sock = socket (PF_INET/*PF_PACKET*/, SOCK_RAW, IPPROTO_RAW);
    perror ("socket");

    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = ip->daddr; 
#endif
    strncpy ((char*)(ip+1), "yash",4);
   while (1)
    {
        ssize_t size = sendto (sock, buffer, 25,0, (struct sockaddr *) &saddr,sizeof (saddr));
        if(size == -1)
            perror ("sendto");

    }

    return 0;
}

