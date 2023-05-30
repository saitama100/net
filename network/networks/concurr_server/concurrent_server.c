#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
void reverse(char *str)
{
	int i, n, temp;
	n = strlen(str);
	for(i=0 ; i<n/2 ; i++)
	{
		temp = str[i];
		str[i] = str[n-i-1];
		str[n-i-1] = temp;
	}
}
int main()
{
	int serv_sockfd, clen, newsockfd;
	char str[100];
	struct sockaddr_in saddr, caddr;
	if((serv_sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("Cannot create socket\n");
		exit(0);
	}
	saddr.sin_family=AF_INET;
	saddr.sin_port=9104;
	saddr.sin_addr.s_addr=INADDR_ANY;
	if(bind(serv_sockfd,(struct sockaddr*)&saddr, sizeof(saddr))<0)
	{
		printf("Unable to bind local address\n");
		exit(0);
	}
	listen(serv_sockfd,5);
	while(1)
	{
		clen=sizeof(caddr);
		newsockfd = accept(serv_sockfd,(struct sockaddr*)&caddr,&clen);
		if(newsockfd<0)
		{
			printf("Accept error\n");
			exit(0);
		}
		if(fock() == 0)
		{
			close(serv_sockfd);
			recv(newsockfd, str, 100, 0);
			reverse(str);
			puts(str);
			send(newsockfd,str, strlin(str)+1, 0);
			close(newsockfd);
			exit(0);
		}
		close(newsockfd);
	}
}
