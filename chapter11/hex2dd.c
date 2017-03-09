#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void str2dec(int *result, char *pos);

int main(int argc, char *argv[])
{
    int   dec[4], i;
    char *pos;

    if (strlen(argv[1]) != 10 || argv[1][0] != '0' || argv[1][1] != 'x') {
        printf("Error: %s\n", argv[1]);
        printf("Usage: %s <hex number>\n", argv[0]);
        exit(1);
    }

    pos = &argv[1][2];
    for (i = 0; i < 4; i++) {
        str2dec(&dec[i], &argv[1][2*(i+1)]);
    }
    printf("%d.%d.%d.%d\n", dec[0], dec[1], dec[2], dec[3]);
    return 0;
}

void str2dec(int *result, char *pos)
{
    int i;
    *result = 0;

    if (*pos >= '0' && *pos <= '9')
        *result += (*pos - '0') * 16;
    else if (*pos >= 'a' && *pos <= 'f')
        *result += (*pos - 'a' + 10) * 16;
    else if (*pos >= 'A' && *pos <= 'F')
        *result += (*pos - 'A' + 10) * 16;
    else {
        fprintf(stderr, "Bad format\n");
        exit(1);
    }
    ++pos;
    if (*pos >= '0' && *pos <= '9')
        *result += (*pos - '0');
    else if (*pos >= 'a' && *pos <= 'f')
        *result += (*pos - 'a' + 10);
    else if (*pos >= 'A' && *pos <= 'F')
        *result += (*pos - 'A' + 10);
    else {
        fprintf(stderr, "Bad format\n");
        exit(1);
    }
}
