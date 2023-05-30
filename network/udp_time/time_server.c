
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<time.h>

int main()
{
	int cs;
	unsigned int l;
	char ch,a[100],b[100];
	struct sockaddr_in c,s;
    time_t t;

	s.sin_family=AF_INET;
	s.sin_addr.s_addr= htonl(INADDR_ANY);
	s.sin_port=8889;
	cs=socket(AF_INET,SOCK_DGRAM,0);
	bind(cs,(struct sockaddr *)&s,sizeof(s));

l=sizeof(c);

	recvfrom(cs,&ch,1,0,(struct sockaddr *)&c,&l);
    printf("Message Received : %c\n",ch);
	ch++;
	sendto(cs,&ch,1,0,(struct sockaddr *)&c,l);
     printf("Message sent : %c\n",ch);


    
    recvfrom(cs,a,100,0,(struct sockaddr *)&c,&l);
    printf("Message Received : %s\n",a);

    t=time(null);
    strftime(b,100,"Date : %d-%m-%Y\nTime : %H:%M:%S:\n",localtime(&t));
	
	sendto(cs,b,100,0,(struct sockaddr *)&c,l);
     printf("Message sent : %s\n",b);

	
	return 0;
}

	
