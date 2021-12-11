#include <stdio.h>

int eingabeaufforderung(int i)
{
    int zahl;
    printf("Bitte geben Sie %d. Zahl ein: \n", i + 1);
    scanf("%d", &zahl);
    return zahl;
}
void ausgabe(int zahl1, int zahl2)
{
    printf("Zahl1: %d, Zahl2: %d \n", zahl1, zahl2);
}

void summe_ausgabe(int summe)
{
    printf("Summe ist: %d\n", summe);
}

int summe(int zahl1, int zahl2)
{
    int summe;
    summe = zahl1 + zahl2;
    summe_ausgabe(summe);
    return summe;
}

int main()
{
    int i;
    int zahl1;
    int zahl2;
    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            zahl1 = eingabeaufforderung(i);
        }
        else
        {
            zahl2 = eingabeaufforderung(i);
        }
    }
    ausgabe(zahl1, zahl2);
    summe(zahl1, zahl2);

    return 0;
}