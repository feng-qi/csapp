#include <stdio.h>

void inplace_swap(int *x, int *y);

int main(void)
{
    int x = 0x3c, y = 0x82;

    printf("before swap: 0x%.2x 0x%.2x\n", x, y);
    inplace_swap(&x, &y);
    printf("after swap:  0x%.2x 0x%.2x\n", x, y);
    inplace_swap(&x, &x);
    printf("bad swap:    0x%.2x\n", x);

    return 0;
}

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}
