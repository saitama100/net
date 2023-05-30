#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int sfd, len, result;
	char name[100], ser[100];
	struct sockaddr_in addr;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_port=9100;
	addr.sin_addr.s_addr = inet_addr("");
	len = sizeof(addr);
	result = connect(sfd,(struct sockaddr*)&addr, len);
	if(result == -1)
	{
		printf("Unable to connect");
		exit(0);
	}
	while(1)
	{
		printf("Enter message: ");
		scanf("%s", name);
		send(sfd,ser, strlen(ser)+1, 0);
		recv(sfd, ser, 100, 0);
		puts(ser);
	}
	return 0;
}
