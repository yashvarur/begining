#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <linux/types.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/tcp.h>


struct ethhdr1
{
  unsigned char h_dest[ETH_ALEN];	/* destination eth addr */
  unsigned char h_source[ETH_ALEN];	/* source ether addr    */
  __be16 h_proto;		/* packet type ID field */
};

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


int
main ()
{
  int i;
  char *buffer = (char *) malloc (200);
  struct ethhdr1 *eh;
  struct iphdr1 *ip;
  struct ifreq req;
  char * data = (char *) malloc (100);
  int soc = socket (AF_INET/*PF_PACKET*/, SOCK_RAW, IPPROTO_RAW);

  if (socket < 0)
    {
      perror ("Error in create\n");
      exit (0);
    }

  while (1)
    {
	//getchar();
      int size = read (soc, buffer, 1000);
      ip = (struct iphdr1 *) buffer;
      printf ("\n\nip header\n\n");
      printf ("header len : %d\n", ip->ihl);
      printf ("version    : %d\n", ip->version);
      printf ("tos        : %d\n", ip->tos);
      printf ("total len  : %d\n", ip->tot_len);
      printf ("id         : %d\n", ip->id);
      printf ("frag off   : %d\n", ip->frag_off);
      printf ("ttl        : %d\n", ip->ttl);
      printf ("protocol   :");
      if (ip->protocol == 1)
	    printf (" ICMP\n");
      else if (ip->protocol == 2)
	    printf (" IGMP\n");
      else if (ip->protocol == 6)
	    printf (" TCP\n");
      else if (ip->protocol == 17)
	    printf (" UDP\n");
      else if (ip->protocol == 89)
	    printf (" OSPF\n");	
    else
		printf("RAW\n");
      printf ("check sum  : %d\n", ip->check);
      struct in_addr in;
      in.s_addr = ip->saddr;
      char *ptr = inet_ntoa (in);

      printf ("source addr: %s\n", ptr);
      in.s_addr = ip->daddr;
      ptr = inet_ntoa (in);
      printf ("dest addr  : %s\n", ptr);
	  data = (char *) (buffer + sizeof(struct iphdr1));
	  printf("data = %s\n",data);

  }

  return 0;
}

