#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

int main()
{
    int sfd, slen, result;
    struct sockaddr_in address;
    char a[100], b[100];

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = 8800;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    slen = sizeof(address);

    result = connect(sfd, (struct sockaddr *)&address, slen);

    printf("Enter the message: ");
    gets(a);
    write(sfd, a, sizeof(a));
    printf("Connected successfully\n");
    read(sfd, b, sizeof(b));
    printf("reading from server : %s\n", b);

    close(sfd);

    return 0;
}
