#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int sockfd,len,result;
	struct sockaddr_in address;
	char buf[5];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	address.sin_family=AF_INET;
	address.sin_port=9003;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	len=sizeof (address);
	result=connect(sockfd,(struct sockaddr *)&address,len);
	if(result == -1)
	{
		perror("Unable to connect!\n");
		exit(1);
	}
	while(1)
	{
		sleep(2);
		for(int i=0;i<5;i++)
		{
			buf[i]='\0';
		}
		recv(sockfd,buf,5,0);
		printf("ACK : %s\n",buf);
		if(buf[0]=='0')
		{
			buf[0]='1';
		}
		else buf[0]='0';
		send(sockfd,buf,5,0);
	}
	return 0;
}
