#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    int i = 0;

    printf("Command line arguments:\n");
    while (*argv) {
        printf("    argv[%2d]: %s\n", i++, *argv++);
    }

    printf("\nEnvironment variables:\n");
    i = 0;
    while (*envp) {
        printf("    envp[%2d]: %s\n", i++, *envp++);
    }

    return 0;
}
