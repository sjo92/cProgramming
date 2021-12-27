#include <stdio.h>

/*
10. Kopieren Sie eine gegebene Zeichenkette in einen neuen Speicherbereich und wenden Sie dabei die ROT13-Verschlüsselung an. Das bedeutet, dass die ersten 13 Buchstaben des Alphabets mit den letzten 13 Zeichen vertauscht werden.
Beispiel: Aus ”Banane” wird ”Onanar”.
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
        if ((eingabe[i] >= 'A' && eingabe[i] <= 'M'))
        {
            copy[i] = eingabe[i] + 13;
        }
        else if ((eingabe[i] >= 'a' && eingabe[i] <= 'm'))
        {
            copy[i] = eingabe[i] + 13;
        }
        else if ((eingabe[i] >= 'N' && eingabe[i] <= 'Z') || (eingabe[i] >= 'n' && eingabe[i] <= 'z'))
        {
            copy[i] = eingabe[i] - 13;
        }
    }

    copy[length] = '\0';

    printf("%s\n", copy);
}