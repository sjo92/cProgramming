#include <stdio.h>

int main()
{
    char first[100];
    char second[100];
    char copy[100];
    int i1 = 0;
    int i2 = 0;
    int in = 0;
    int length1;
    int length2;
    int i;
    printf("Bitte geben Sie die 1. Kette ein: ");
    scanf("%s", first);

    printf("Bitte geben Sie die 2. Kette ein: ");
    scanf("%s", second);

    for (i = 0; first[i] != '\0'; i++)
    {
    }
    length1 = i;
    printf("length1: %d \t", length1);
    i = 0;
    for (i = 0; second[i] != '\0'; i++)
    {
    }
    length2 = i;

    while (first[i1] != '\0' || second[i2] != '\0')
    {
        if (first[i1] != '\0')
        {
            copy[in] = first[i1];
            in++;
            i1++;
        }
        if (second[i2] != '\0')
        {
            copy[in] = second[i2];
            in++;
            i2++;
        }
    }
    copy[i1 + i2] = '\0';
    printf("%s", copy);

    /*
    printf("length2: %d \t", length2);
    i = 0;
    for (i = 0; i < length1; i++)
    {
        copy[2 * i] = first[i];

        printf("(%d:%c)\t", 2 * i, copy[2 * i]);
    }
    for (i = 0; i < length1; i++)
    {
        copy[2 * i + 1] = second[i];
        printf("(%d:%c)\t", 2 * i + 1, copy[2 * i + 1]);
    }
    for (i = 0; i < length2 - length1; i++)
    {
        copy[2 * length1 + i] = second[length1 + i];
        printf("(%d:%c)\t", 2 * length1 + i, copy[2 * length1 + i]);
    }*/
}