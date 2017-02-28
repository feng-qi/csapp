#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char *my_map(int fd, int length)
{
    char *s;
    if ((s = mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, 0)) == (void*)-1) {
        fprintf(stderr, "mmap error: %s\n", strerror(errno));
        exit(1);
    }
    return s;
}

int main(int argc, char *argv[])
{
    struct stat stat_val;
    int filesize;
    int fd = open(argv[1], O_RDONLY, 0);
    if (stat(argv[1], &stat_val) == -1) {
        fprintf(stderr, "stat error: %s\n", strerror(errno));
        exit(2);
    }
    filesize = stat_val.st_size;

    write(1, my_map(fd, filesize), filesize);
    printf("1\n");

    return 0;
}
