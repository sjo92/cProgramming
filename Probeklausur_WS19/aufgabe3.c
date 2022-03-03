#include <stdio.h>
#include <stdlib.h>
#include "../Woche10_Liste/readtext.c"

int main()
{
    int i = 0;
    int buchstaben = 0;
    int ziffern = 0;

    /*Benutzereingabe fragen und die Eingabe in der Char Zeichenkette "eingabe" sichern*/
    printf("Bitte geben Sie etwas ein: ");
    char *eingabe = readtext();

    /*Benutzereingabe in einer Schleife durchlaufen um zu überprüfen ob mehr Buchstaben oder Ziffern vorhanden sind*/
    while (eingabe[i] != '\0')
    {

        if (eingabe[i] >= 'A' && eingabe[i] <= 'Z' || eingabe[i] >= 'a' && eingabe[i] <= 'z')
        {
            buchstaben++;
        }
        if (eingabe[i] >= '0' && eingabe[i] <= '9')
        {
            ziffern++;
        }
        i++;
    }

    /*Benutzereingabe ausgeben je nach der Konditionen*/
    for (i = 0; eingabe[i] != '\0'; i++)
    {
        // Wenn Buchstaben mehr als Ziffern sind, werden Buchstaben ausgegeben.
        if (buchstaben > ziffern)
        {
            if (eingabe[i] >= 'A' && eingabe[i] <= 'Z' || eingabe[i] >= 'a' && eingabe[i] <= 'z')
            {
                printf("%c", eingabe[i]);
            }
        }
        // Wenn Ziffern mehr als Buchstaben sind, werden Ziffern ausgegeben.
        else if (buchstaben < ziffern)
        {
            if (eingabe[i] >= '0' && eingabe[i] <= '9')
            {
                printf("%c", eingabe[i]);
            }
        }
    }

    /*Falls Buchstaben gleich viel wie Ziffern beinhaltet, werden eine Warnung ausgegeben*/
    if (buchstaben == ziffern)
    {
        printf("Die Menge der Buchstaben und die Menge der Ziffern sind in diesem Text gleich!\n");
    }
    else
    { // Für die Formate am Ende des Programmes einen Zeilenumbruch ausgegeben
        printf("\n");
    }

    // Der Speicherplatz für die bereits verwendete Zeichenkette freischalten
    free(eingabe);

    return 0;
}