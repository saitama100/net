#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
	int serv_sockfd,serv_len,cli_sockfd, cli_len;
	char buf[5];
	char f='1';
	struct sockaddr_in serv_address, cli_address;
	serv_sockfd=socket(AF_INET,SOCK_STREAM,0);
	serv_address.sin_family=AF_INET;
	serv_address.sin_port=9003;
	serv_address.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv_len=sizeof(serv_address);
	bind(serv_sockfd,(struct sockaddr*)&serv_address,serv_len);
	listen(serv_sockfd,5);
	cli_len = sizeof(cli_address);
	cli_sockfd = accept(serv_sockfd,(struct sockaddr*)&serv_address,&serv_len);
	while(1)
	{
		sleep(2);
		for(int i=0;i<5;i++)
		{
			buf[i]='\0';
		}
		buf[0]=f;
		send(cli_sockfd,buf,5,0);
		for(int i=0;i<5;i++)
		{
			buf[i]='\0';
		}
		recv(cli_sockfd,buf,5,0);
		printf("FRAME : %s\n",buf);
		if(f=='0')
		{
			f='1';
		}
		else f='0';
	}
	return 0;
}
