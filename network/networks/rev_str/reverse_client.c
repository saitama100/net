#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int sockfd, len, x;
	struct sockaddr_in address;
	char name[100];
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	address.sin_family = AF_INET;
	address.sin_port = 8004;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	len = sizeof(address);
	bind(sockfd, (struct sockaddr*) &address, len);
	while(1){
	printf("Enter string: ");
	gets(name);
	x=sizeof(name);
	sendto(sockfd, name, x, 0, (struct sockaddr*) &address, len);
	recvfrom(sockfd, name, x, 0, (struct sockaddr*) &address, &len);
	close(sockfd);
	return 0;
}
}
