#include <stdio.h>

void eingabeaufforderung_info()
{
    printf("Es ist nun eine Benutzereingabe erforderlich. \n");
}

void eingabeaufforderung_zk()
{
    eingabeaufforderung_info();
    printf("Bitte geben Sie eine Zeichenkette ein: ");
}
void eingabeaufforderung_int()
{
    eingabeaufforderung_info();
    printf("Bitte geben Sie eine ganze Zahl ein: ");
}
void ausgabe_int(int input)
{
    printf("Die Zahl lautet: %d\n", input);
}

void ausgabe_zk(char *input)
{
    printf("Die Zeichenkette lautet: %s\n", input);
}

int main()
{
    int zahl;
    char kette[10];
    char c;
    int i = 0;
    /*
    do
    {
        eingabeaufforderung_int();
        scanf("%d", &zahl);
    } while (zahl < 0);
    ausgabe_int(zahl);
    */

    /* Aufgabe d)*/
    eingabeaufforderung_zk();

    while ((c = getchar()) == '\n')
    {
        eingabeaufforderung_zk();
    }

    do
    {
        kette[i] = c;
        i++;
    } while ((c = getchar()) != '\n' && i <= 9);

    kette[i] = '\0';
    ausgabe_zk(kette);

    return 0;
}