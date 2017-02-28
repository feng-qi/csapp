#include <stdio.h>

int tmult_ok(int x, int y)
{
    long long pll = (long long) x*y;
    return pll = (int)pll;
}

/* compare the assembly code to see difference */
int tmult_ok_bug(int x, int y)
{
    long long pll = x*y;
    return pll = (int)pll;
}

int main(void)
{
    printf("%lld\n", (long long)(1<<30) * (1<<30));
    printf("%lld\n", ((1<<30)|1) * ((1<<30)|1));
    printf("%lld\n", (long long)((1<<30)|1) * ((1<<30)|1));
    return 0;
}

