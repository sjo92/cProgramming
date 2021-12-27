#include <stdio.h>
#include <stdlib.h>

int main()
{
    char text[100];
    char spiegel[100];
    char palin[100];
    printf("Bitte geben Sie etwas ein: ");
    scanf("%s", text);
    int i;
    int length = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
    }
    length = i;
    i = 0;
    int j = 0;
    for (i = 0; i < length; i++)
    {
        j = length - i - 1;
        spiegel[i] = text[j];
    }
    spiegel[length] = '\0';
    printf("The original text ist: %s\n", text);
    printf("The mirrored text ist: %s\n", spiegel);
}