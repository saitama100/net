#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main()
{
	int cs;
	unsigned int l;
	char ch;
	struct sockaddr_in c,s;
	s.sin_family=AF_INET;
	s.sin_addr.s_addr= htonl(INADDR_ANY);
	s.sin_port=8889;
	cs=socket(AF_INET,SOCK_DGRAM,0);
	bind(cs,(struct sockaddr *)&s,sizeof(s));
	recvfrom(cs,&ch,1,0,(struct sockaddr *)&c,&l);
	ch++;
	sendto(cs,&ch,1,0,(struct sockaddr *)&c,l);
	
	return 0;
}

	
