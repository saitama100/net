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
    int sfd, cfd, slen, clen;
    struct sockaddr_in saddr, caddr;
    char a[100], b[100];
    time_t t;

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
    printf("\n Accepted to client\n");

    read(cfd, a, sizeof(a));
    puts(b);
    t=time(NULL);
    strftime(b, sizeof(b), "%Y-%m-%d %H:%M:%S", localtime(&t));
    write(cfd, b, sizeof(b));

    close(sfd);
    close(cfd);
    return 0;
}
