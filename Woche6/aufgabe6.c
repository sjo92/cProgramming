#include <stdio.h>

int main()
{
    char kette[100];
    char copy[100];
    int i;
    int length;
    printf("Bitte gebe eine Zahl ein: ");
    scanf("%s", kette);

    for (i = 0; kette[i] != '\0'; i++)
    {
    }
    length = i;
    kette[i] = '\0';

    for (i = 0; kette[i] != '\0'; i++)
    {
        copy[i] = kette[length - 1 - i];
    }

    copy[i] = '\0';
    printf("Umgedreht ist es: %s\n", copy);
}