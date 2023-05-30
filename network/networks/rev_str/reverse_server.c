#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>

void revstr(char *str){

    int i, len;
    char ac[100];
    strcpy(ac,str);
    len = strlen(str);
    for (i = 0; i < len; i++){  
        str[i] = ac[len - i - 1];
    }  
}
int main(){
	int serv_sockfd, serv_len;
	struct sockaddr_in serv_address;
	char b[100], x;
	serv_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	serv_address.sin_family = AF_INET;
	serv_address.sin_port = 8004;
	serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_len = sizeof(serv_address);
	bind(serv_sockfd, (struct sockaddr*) &serv_address, serv_len);
	printf("Waiting for message..");
	x=sizeof(b);
	recvfrom(serv_sockfd,b, sizeof(b), 0, (struct sockaddr*) &serv_address, &serv_len);
	printf("Recieved\n");
	puts(b);
	printf("Sending..\n");
	revstr(b);
	puts(b);
	close(serv_sockfd);
	return 0;

}
