#include <stdio.h>

int main()
{
    char first[100];
    char second[100];
    char copy[100];
    int i;
    int length1;
    int length2;

    printf("Bitte geben Sie die 1. Kette ein: ");
    scanf("%s", first);

    printf("Bitte geben Sie die 2. Kette ein: ");
    scanf("%s", second);

    for (i = 0; first[i] != '\0'; i++)
    {
    }
    length1 = i;

    i = 0;
    for (i = 0; second[i] != '\0'; i++)
    {
    }
    length2 = i;

    i = 0;
    for (i = 0; i < length1; i++)
    {
        copy[i] = first[i];
    }
    for (i = 0; i < length2; i++)
    {
        copy[i + length1] = second[i];
    }
    copy[length1 + length2] = '\0';
    printf("%s", copy);
}