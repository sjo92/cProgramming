#include <stdio.h>
/*

7. Kopieren Sie aus einer gegebenen Zeichenkette alle Zeichen außer den Vokalen in einen neuen Speicherbereich.

*/
int main()
{
    char eingabe[100];
    char copy[100];
    int length;
    int i;
    int j;

    printf("Bitte geben Sie etwas ein: ");
    scanf("%s", eingabe);

    for (i = 0; eingabe[i] != '\0'; i++)
    {
    }
    length = i;
    i = 0;
    j = 0;
    for (i = 0; i < length; i++)
    {
        if (!(eingabe[i] == 'a' || eingabe[i] == 'A' || eingabe[i] == 'e' || eingabe[i] == 'E' || eingabe[i] == 'i' || eingabe[i] == 'I' || eingabe[i] == 'o' || eingabe[i] == 'O' || eingabe[i] == 'u' || eingabe[i] == 'U'))
        {
            copy[j] = eingabe[i];
            j++;
        }
    }
    copy[j] = '\0';

    printf("Die kopierte Kette ist: %s\n", copy);
}