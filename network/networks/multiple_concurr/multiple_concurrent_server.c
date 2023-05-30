#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
void revstr(char *str)
{
	int i,len;
	char ac[100];
	strcpy(ac,str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		str[i]=ac[len-i-1];
	}
}
int main()
{
	int serv_sockfd,cli_sockfd,x;
	int serv_len,cli_len;
	struct sockaddr_in serv_address,cli_address;
	char a[100];
	int i,j,size;
	serv_sockfd=socket(AF_INET,SOCK_STREAM,0);
	serv_address.sin_family=AF_INET;
	serv_address.sin_port=9007;
	serv_address.sin_addr.s_addr=INADDR_ANY;
	serv_len=sizeof(serv_address);
	bind(serv_sockfd,(struct sockaddr*)&serv_address,serv_len);
	
	listen(serv_sockfd,5);
	
	while(1)
	{
	
		printf("server is waiting...");
		cli_len=sizeof(cli_address);
		cli_sockfd=accept(serv_sockfd,(struct sockaddr*)&cli_address,&cli_len);
		
		if(fork()==0)
		{
		close(serv_sockfd);
		for(;;)
		{
			x=sizeof(a);
			read(cli_sockfd,a,sizeof(a));
			printf("reading message from client:");
			puts(a);
			
				printf("message sending to client");
				revstr(a);
				write(cli_sockfd,a,sizeof(a));
		}
		close(cli_sockfd);
		}
		else
		{
			printf("error");
		}
		}
	return 0;
}
		

