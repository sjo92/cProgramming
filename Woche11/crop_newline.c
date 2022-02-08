#include <stdio.h>

void newline(char *arr)
{
    int i = 0;
    while (arr[i] != '\n')
    {
        i++;
    }
    arr[i] = '\0';
}
