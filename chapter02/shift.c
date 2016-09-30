#include <stdio.h>

int main(void)
{
    int      lval = 0xFECDBA98  << 32;
    int      aval = 0xFECDBA98  >> 36;
    unsigned uval = 0xFECDBA98u >> 40;

    printf("lval:\t%x\n" ,lval);
    printf("aval:\t%x\n" ,aval);
    printf("uval:\t%x\n" ,uval);
    return 0;
}
