#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    struct stat stat_val;
    char *type, *readok;

    if (stat(argv[1], &stat_val) != 0) {
        fprintf(stderr, "stat error: %s\n", strerror(errno));
        exit(1);
    }
    if (S_ISREG(stat_val.st_mode))
        type = "regular";
    else if (S_ISDIR(stat_val.st_mode))
        type = "directory";
    else
        type = "other";
    if ((stat_val.st_mode & S_IRUSR))
        readok = "yes";
    else
        readok = "no";

    printf("type: %s, read: %s\n", type, readok);

    return 0;
}
