#include <string.h>
#include "figure2.4.h"

int main(void)
{
    const char *s = "abcdef";
    show_bytes((byte_pointer) s, strlen(s));

    return 0;
}
