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
	char name[100], ser[100];
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	address.sin_family = AF_INET;
	address.sin_port = 9055;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	len = sizeof(address);
	bind(sockfd, (struct sockaddr*) &address, len);
	printf("Enter the message: ");
	gets(name);
	sendto(sockfd, name, sizeof(name), 0, (struct sockaddr*) &address, len);
	recvfrom(sockfd, ser, sizeof(ser), 0, (struct sockaddr*) &address, &len);
	printf("Message from the server...");
	puts(ser);
	return 0;
}
