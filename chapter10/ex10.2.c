#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd1, fd2;
    char c;
    fd1 = open("./foobar.txt", O_RDONLY, 0);
    fd2 = open("./foobar.txt", O_RDONLY, 0);

    read(fd1, &c, 1);
    read(fd2, &c, 1);

    printf("c = %c\n", c);

    return 0;
}
