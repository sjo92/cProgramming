#include <stdio.h>

/*
8. Kopieren Sie eine gegebene Zeichenkette in einen neuen Speicherbereich und verwandeln Sie dabei alle Kleinbuchstaben in Großbuchstaben.
Beispiel: Aus ”Banane” wird ”BANANE”.

*/
int main()
{
    char eingabe[100];
    char copy[100];
    int i;
    int length;

    printf("Bitte geben Sie etwas ein: ");
    scanf("%s", eingabe);

    printf("%s\n", eingabe);

    // Ascii kleinbuchstaben 97 - 122 & großbuchstaben 65 - 90

    for (i = 0; eingabe[i] != '\0'; i++)
    {
    }
    length = i;
    i = 0;

    for (i = 0; i < length; i++)
    {
        if (eingabe[i] >= 97 && eingabe[i] <= 122)
        {
            copy[i] = eingabe[i] - 32;
        }
        else
        {
            copy[i] = eingabe[i];
        }
    }

    copy[length] = '\0';

    printf("%s\n", copy);
}