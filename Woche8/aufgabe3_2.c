#include <stdio.h>
#include "readtext.c"
#define VAR 100

int count_char(char *str, char c)
{
    int count;
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int i;
    int length;
    char c;
    char *test = 0;
    printf("Bitte geben Sie etwas ein: ");
    test = readtext();
    printf("Bitte geben Sie ein Zeichen: ");
    scanf("%c", &c);

    int count = count_char(test, c);
    printf("The text has %d times of %c\n", count, c);
}