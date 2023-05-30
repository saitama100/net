#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main()
{
    int cs;
	unsigned int l;
	char ch;
	struct sockaddr_in c;
	c.sin_family=AF_INET;
	c.sin_addr.s_addr= htonl(INADDR_ANY);
	c.sin_port=8889;
	cs=socket(AF_INET,SOCK_DGRAM,0);
    printf("\n Enter Character  : ");
    scanf("%c",&ch);
    l=sizeof(c);
	sendto(cs,&ch,1,0,(struct sockaddr *)&c,l);
	recvfrom(cs,&ch,1,0,(struct sockaddr *)&c,&l);
    printf("\n Received Character : %c",ch);
    return 0;

}
