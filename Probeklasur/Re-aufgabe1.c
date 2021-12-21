#include <stdio.h>

int main()
{
    int zahl[20];
    int i;
    for (i = 0; i < 20; i++)
    {
        if (i < 2)
        {
            zahl[i] = 1;
        }
        else
        {
            zahl[i] = zahl[i - 2] + zahl[i - 1];
        }
    }
    for (i = 0; i < 20; i++)
    {
        printf("%d", zahl[i]);
        if (i == 19)
        {
            printf("\n");
        }
        else
        {
            printf(", ");
        }
    }
}