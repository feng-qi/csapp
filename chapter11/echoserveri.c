#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

void echo(int connfd);
int open_listenfd(int port);
void echo(int connfd);

int main(int argc, char *argv[])
{
    int listenfd, connfd, port, clientlen;
    struct sockaddr_in clientaddr;
    struct hostent *hp;
    char *haddrp;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(0);
    }
    port = atoi(argv[1]);

    if ((listenfd = open_listenfd(port)) < 0) {
        fprintf(stderr, "open_listenfd error: %s\n", strerror(errno));
        exit(-1);
    }
    while (1) {
        clientlen = sizeof(clientaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen)) < 0) {
            fprintf(stderr, "accept error: %s\n", strerror(errno));
            exit(-2);
        }

        /* Determine the domain name and IP address of the client */
        hp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
                           sizeof(clientaddr.sin_addr.s_addr), AF_INET);

        // Local IP address, no domain name should be found
        // if (hp == NULL) {
        //     fprintf(stderr, "gethostbyaddr error: %s\n", strerror(errno));
        //     exit(-3);
        // }
        // haddrp = inet_ntoa(clientaddr.sin_addr);
        // printf("server connected to %s (%s)\n", hp->h_name, haddrp);

        echo(connfd);
        close(connfd);
    }

    return 0;
}
