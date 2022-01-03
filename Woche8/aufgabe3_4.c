#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"

int main()
{
    char *text = 0;
    char *spiegel = 0;
    char *palin = 0;
    printf("Bitte geben Sie etwas ein: ");
    text = readtext();
    int i;
    int length = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
    }
    length = i;
    spiegel = malloc(length);
    palin = malloc(length);
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