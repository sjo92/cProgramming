#include <stdio.h>
#define VAR 100

int main()
{
    int i;
    char text[VAR];
    int length;
    int a = 0;
    printf("Bitte geben Sie etwas ein: ");
    scanf("%s", text);
    printf("The text is: %s\n", text);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 'a')
        {
            a++;
        }
    }

    length = i;
    i = 0;
    char sec[length];
    for (i = 0; text[i] != '\0'; i++)
    {
        sec[i] = text[i];
    }
    printf("The length of the text is: %d\n", length);
    printf("The text has %d times of 'a'\n", a);
    printf("The copy of the text is: %s\n", sec);
}