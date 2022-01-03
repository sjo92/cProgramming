#include <stdio.h>
#include "readtext.c"
#define VAR 100

int count_char(char *str)
{
    int count;
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        i++
    }
    return i;
}

int main()
{
    int i;
    char text[VAR];
    int length;
    printf("Bitte geben Sie etwas ein: ");
    scanf("%s", text);
    printf("The text is: %s\n", text);

    length = count_char(text);

    printf("The length of the text is: %d\n", length);
}