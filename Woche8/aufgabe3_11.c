/*
11. Kopieren Sie eine gegebene Zeichenkette in einen neuen Speicherbereich und wenden Sie dabei die Caesar-Verschlüsselung mit einer beliebigen Verschiebung an. Das bedeutet, dass jeder Buchstabe des Alphabets um entsprechend viele Stellen verschoben wird.
Beispiel einer Verschlüsselung um 3 Stellen: Aus ”Banane” wird ”Edqdqh”.
*/

#include <stdio.h>

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
        if (eingabe[i] >= 'A' && eingabe[i] <= 'Z')
        {
            copy[i] = (eingabe[i] - 65 + 3) % 26 + 65;
        }
        else if (eingabe[i] >= 'a' && eingabe[i] <= 'z')
        {
            copy[i] = (eingabe[i] - 97 + 3) % 26 + 97;
        }
    }

    copy[length] = '\0';

    printf("%s\n", copy);
}