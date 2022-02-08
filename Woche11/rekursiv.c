#include <stdio.h>

long fakultaet(int x)
{
    if (x < 1)
        return 1;
    return fakultaet(x - 1) * x;
}

long summe(int x)
{
    if (x < 1)
        return 0;
    return summe(x - 1) + x;
}

int main()
{
    printf("%ld\n", summe(100));
}
/*
50 --> 40 --> 30 --> 20 -->10


*/
