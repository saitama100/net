
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main()
{
	int sfd,slen,result;
	struct sockaddr_in address;
	char str[100],ser[100];

	sfd=socket(AF_INET,SOCK_STREAM,0);
	address.sin_family=AF_INET;
	address.sin_port=8800;
	address.sin_addr.s_addr= htonl(INADDR_ANY);
	slen=sizeof(address);

	result=connect(sfd,(struct sockaddr*)&address,slen);

	while(1){
        printf("Enter the message: ");
        scanf("%s",str);
        write(sfd,str,sizeof(str));
        printf("message Sent\n");
        read(sfd,ser,sizeof(ser));
        printf("reading from server : %s\n",ser);
    }

	close(sfd);
	
	return 0;
}

