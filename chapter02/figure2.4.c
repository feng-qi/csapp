#include <stdio.h>
#include "figure2.4.h"

int main(void)
{
    int i;
    void *pv = (void*) &i;

    printf("int \t%-20d:", 888);
    show_int(888);
    printf("float \t%-20f:", 3.14);
    show_float(3.14);
    printf("void* \t%-20p:", pv);
    show_pointer(pv);

    return 0;
}
