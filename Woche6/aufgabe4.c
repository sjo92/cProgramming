#include <stdio.h>

int main()
{
    char eingabe[200];
    int i;

    printf("Bitte geben Sie etwas ein: ");
    scanf("%s", eingabe);

    for (i = 0; eingabe[i] != '\0'; i++)
    {
        printf("Das Zeichen am Index %d hat den ASCII-Wert %d.\n", i, eingabe[i]);
    }

    printf("Die Zeichenkette ist nun zu Ende.\n");

    return 0;
}