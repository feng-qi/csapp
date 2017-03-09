#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned int   hex = 0;
    struct in_addr addr;

    if (strlen(argv[1]) != 10 || argv[1][0] != '0' || argv[1][1] != 'x') {
        printf("Error: %s\n", argv[1]);
        printf("Usage: %s <hex number>\n", argv[0]);
        exit(1);
    }

    sscanf(argv[1], "%x", &hex);
    addr.s_addr = htonl(hex);
    printf("%s\n", inet_ntoa(addr));

    return 0;
}

