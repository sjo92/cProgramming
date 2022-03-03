
#include <stdlib.h>
#include <stdio.h>
//#include "readtext.c"
/*
int readint()
{
    int zahl = 0;              //Speicher für berechneten Integer
    char *buffer = readtext(); //Benutzereingabe

    int i = 0;
    if (buffer[0] == '-' || buffer[0] == '+')
        i = 1; // Erstes Zeichen minus überspringen
    while (buffer[i] >= '0' && buffer[i] <= '9')
    {                                       //solange Zahlen in Zeichenkette
        zahl = zahl * 10 + buffer[i] - '0'; // Bisherigen Integer mal 10 plus Wert der aktuellen Ziffer
        i++;
    }
    if (buffer[0] == '-') // Bei negativer Zahl, Integer umdrehen
    {
        zahl = -zahl;
    }

    free(buffer);

    return zahl;
}
*/

int readint()
{
    int zahl = 0;
    int vorzeichen = 1; // 1 für positiv und -1 für negativ
    char zeichen = getchar();
    if (zeichen == '-')
    {
        vorzeichen = -1;
        zeichen = getchar();
    }
    if (zeichen == '+')
    {
        zeichen = getchar();
    }

    while (zeichen >= '0' && zeichen <= '9')
    {
        zahl = zahl * 10 + zeichen - '0';
        zeichen = getchar();
    }
    while (zeichen != '\n')
    {
        zeichen = getchar();
    }
    zahl = vorzeichen * zahl;
    return zahl;
}
int main()
{
    printf("Bitte geben Sie eine Zahl ein: ");
    int zahl = readint();
    printf("Die Zahl lautet %d. \n", zahl);
    return 0;
}