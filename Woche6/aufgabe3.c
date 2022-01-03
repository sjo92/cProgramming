#include <stdio.h>

int main()
{
    int i;
    for (i = 65; i < 91; i++)
    {
        printf("(%c, %c) ", i, i + 32);
    }
    return 0;
}