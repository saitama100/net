#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>

int main(){
	int sockfd, len;
	struct sockaddr_in address;
	char ch[100];
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	address.sin_family = AF_INET;
	address.sin_port = 9044;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	len = sizeof(address);
	bind(sockfd, (struct sockaddr*) &address, len);
	printf("Enter a character: ");
	scanf("%c", &ch);
	sendto(sockfd, ch, sizeof(ch), 0, (struct sockaddr*) &address, len);
	close(sockfd);
	return 0;
}
