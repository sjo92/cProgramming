#include <stdio.h>

int main()
{
    char eingabe[100];
    char copy[100];

    int i;
    int j;
    int length;

    printf("Bitte geben Sie etwas ein: ");
    scanf("%s", eingabe);

    for (i = 0; eingabe[i] != '\0'; i++)
    {
        copy[i] = eingabe[i];
    }

    copy[i] = '\0';

    printf("%s", copy);
    return 0;
}
