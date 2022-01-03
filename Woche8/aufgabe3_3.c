#include <stdio.h>
#include "readtext.c"

int count_char(char *str)
{
    int count;
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        i++;
    }
    return i;
}

int main()
{
    char *text = 0;
    char *copy = 0;
    int i;
    printf("Enter String: ");
    text = readtext();
    int length = count_char(text);

    copy = malloc(length);
    for (i = 0; i < length; i++)
    {
        copy[i] = text[i];
    }

    printf("Original: %s, %p \n copy: %s, %p\n", text, &text, copy, &copy);
    free(text);
    free(copy);
    return 0;
}