#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig)
{
    /* printf("User hits ctrl-c after %d seconds\n", snooze(0)); */
    /* exit(0); */
    return;
}

int main()
{
    if (signal(SIGINT, handler) == SIG_ERR) {
        fprintf(stderr, "signal error: %s\n", strerror(errno));
        exit(0);
    }

    snooze(5);

    return 0;
}
