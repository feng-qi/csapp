#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    struct in_addr addr;

    if (argc != 2) {
        printf("Usage: %s <dotted-decimal>\n", argv[0]);
        exit(1);
    }

    if (inet_aton(argv[1], &addr)) {
        fprintf(stderr, "usage: %s <dotted-decimal>\n", argv[0]);
        exit(1);
    }
    printf("%#x\n", ntohl(addr.s_addr));
    return 0;
}
