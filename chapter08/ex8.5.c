#include <unistd.h>
#include <stdio.h>

unsigned int snooze(unsigned int secs)
{
    unsigned int time_slept;

    time_slept = sleep(secs);
    printf("Slept for %d of %d secs.\n", secs - time_slept, secs);
    return time_slept;
}
