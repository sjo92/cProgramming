#include <stdio.h>

/*
12. Vergleichen Sie zwei beliebige Zeichenketten alphabetisch miteinander. Berück- sichtigen Sie dabei drei mögliche Ergebnisse: Die erste Zeichenkette ist alphabe- tisch kleiner, größer oder gleich der zweiten Zeichenkette. Zum (alphabetischen)
3
Vergleich zweier Zeichen können Sie der Einfachheit halber die ASCII-Tabelle ver- wenden, so dass A<a ist.
Beispiel: ”Banane” ist alphabetisch kleiner als ”Hallo Welt”.
*/

int main()
{
    char first[100];
    char second[100];

    int sum1 = 0;
    int sum2 = 0;

    int i;

    printf("Bitte geben Sie die 1. Kette ein: ");
    scanf("%s", first);

    printf("Bitte geben Sie die 2. Kette ein: ");
    scanf("%s", second);

    for (i = 0; first[i] != '\0'; i++)
    {
        sum1 = first[i] + 0 + sum1;
    }
    i = 0;
    for (i = 0; second[i] != '\0'; i++)
    {
        sum2 = second[i] + 0 + sum2;
    }
    if (sum1 > sum2)
    {
        printf("%s ist alphabetisch größer als %s\n", first, second);
    }
    else if (sum1 < sum2)
    {
        printf("%s ist alphabetisch größer als %s\n", second, first);
    }
    else
    {
        printf("%s ist alphabetisch gleich groß wie %s\n", first, second);
    }
}