#include <stdio.h>

int main()
{
    char eingabe[100];
    int length;
    int i;
    printf("Bitte geben Sie etwas ein: ");
    scanf("%s", eingabe);

    for (i = 0; eingabe[i] != '\0'; i++)
    {
    }
    length = i;
    i = 0;
    for (i = 0; i < length; i++)
    {
        eingabe[i] = eingabe[i] + 1;
    }
    printf("%s\n", eingabe);
}