
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main()
{
	int sfd, cfd, slen, clen;
	struct sockaddr_in saddr, caddr;
	char a[100], b[100];

	saddr.sin_family = AF_INET;
	saddr.sin_port = 8800;
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);
	slen = sizeof(saddr);

	sfd = socket(AF_INET, SOCK_STREAM, 0);

	bind(sfd, (struct sockaddr *)&saddr, slen);
	listen(sfd, 1);

	printf("SERVER IS WAITING......\n");
	clen = sizeof(caddr);
	cfd = accept(sfd, (struct sockaddr *)&caddr, &clen);
    printf("Connect to client\n");
	while(1){
        read(cfd, a, sizeof(a));
	    printf("\nReading message from client: %s\n",a);
		printf("Enter message : ");
	    scanf("%s",b);
    	write(cfd, b, sizeof(b));
    }
	close(sfd);
	close(cfd);
	return 0;
}
