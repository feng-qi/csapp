#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include "../chapter10/rio/rio.h"

#define MAXLINE 4096

int open_clientfd(char *hostname, int port);

int main(int argc, char *argv[])
{
    int clientfd, port;
    char *host, buf[MAXLINE];
    rio_t rio;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }
    host = argv[1];
    port = atoi(argv[2]);

    if ((clientfd = open_clientfd(host, port)) < 0) {
        fprintf(stderr, "open_clientfd error: %s\n", hstrerror(h_errno));
        exit(-1);
    }
    rio_readinitb(&rio, clientfd);

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        rio_writen(clientfd, buf, strlen(buf));
        rio_readlineb(&rio, buf, MAXLINE);
        fputs(buf, stdout);
    }
    close(clientfd);

    return 0;
}
