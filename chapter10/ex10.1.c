#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd1, fd2;

    fd1 = open("./ex10.1.c", O_RDONLY, 0);
    close(fd1);
    fd2 = open("../chapter09/ex9.5.c", O_RDONLY, 0);
    printf("fd2 = %d\n", fd2);

    return 0;
}
