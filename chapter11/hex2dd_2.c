#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned int hex = 0;
    int i;

    if (strlen(argv[1]) != 10 || argv[1][0] != '0' || argv[1][1] != 'x') {
        printf("Error: %s\n", argv[1]);
        printf("Usage: %s <hex number>\n", argv[0]);
        exit(1);
    }

    sscanf(argv[1], "%x", &hex);
    /* printf("%x\n", hex); */
    for (i = 3; i >= 0; i--) {
        printf("%d%s", (hex >> i*8) & 0xff, (i==0 ? "" : ".")); /* Mind the endian */
    }
    printf("\n");
    return 0;
}

