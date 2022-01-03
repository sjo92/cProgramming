#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"

/*
Erzeugen Sie aus einer gegebenen Zeichenkette ein Palindrom durch Anstellen der gespiegelten Zeichenkette.
*/

int main()
{
    char *text;
    char *palin;
    printf("Bitte geben Sie etwas ein: ");
    text = readtext();

    int i;
    int length = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
    }
    length = i;

    palin = malloc(length * 2);
    i = 0;
    int j = 0;
    for (i = 0; i < length; i++)
    {
        palin[i] = text[i];
    }
    for (i = length - 1; i >= 0; i--)
    {
        j = (length - 1 - i) + length;
        palin[j] = text[i];
        printf("j,i = (%d, %d)\n", j, i);
    }
    text[length + length] = '\0';
    printf("The original text ist: %s\n", text);
    printf("The mirrored text ist: %s\n", palin);
}