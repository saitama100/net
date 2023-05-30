#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int sfd, len, result;
	struct sockaddr_in addr;
	char name[100], ser[100];
	sfd=socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_port=8000;
	addr.sin_addr.s_addr = inet_addr("10.10.9.248");
	len = sizeof(addr);
	result = connect(sfd,(struct sockaddr*)&addr, len);
	
	
		if(result == -1)
		{
			printf("Unable to connect");
			exit(1);
		}
		while(1)
		{
			printf("Enter message: ");
			gets(name);
			write(sfd,name,sizeof(name));
			read(sfd, ser,sizeof(ser));
			printf("reading from server:");
			puts(ser);
		}
	
	return 0;
}
