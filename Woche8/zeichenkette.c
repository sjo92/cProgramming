#include <stdio.h>
#include <stdlib.h>

// Zählt die Anzahl Zeichen einer Zeichenkette bis zum Terminator
// Terminator wird nicht mitgezählt
int my_strlen(char *zk)
{
    int count = 0;
    while (zk[count] != '\0')
        count++;
    return count;
}

// Char Count - Zählt wie oft ein Zeichen in einer Zeichenkette vorkommt
int charcount(char *zk, char zeichen)
{
    int anzahl;
    int i = 0;
    while (zk[i] != '\0')
    {
        if (zk[i] == zeichen)
        {
            anzahl++;
        }
        i++;
    }
}

// String Duplicate - Kopiert eine Zeichenkette in einen neu allokierten Speicherbereich
char *my_strdup(char *orig)
{
    int laenge = my_strlen(orig) + 1; // +1 wegen Terminator
    char *kopie = malloc(laenge);
    int i;
    for (i = 0; i < laenge; i++)
    {
        kopie[i] = orig[i];
    }
    return kopie;
}

// String reverse - Kopiert eine Zeichenkette gespiegelt in einen neu allokierten Speicherbereich
char *my_strrev(char *orig)
{
    int laenge = my_strlen(orig);     // Ohne Terminator
    char *kopie = malloc(laenge + 1); // Denoch mit Speicherplatz füer Terminator reservieren.
    int i;
    for (i = 0; i < laenge; i++)
    {
        kopie[i] = orig[laenge - 1 - i];
    }
    kopie[laenge] = '\0'; //Ans Ende noch den Terminator
    return kopie;
}

// String increase - kopiert die Zeichenkette und nimmt jeweils das nächste höhere Zeichen
// Aus A wird B, aus M wird N und so weiter
char *my_strinc(char *orig)
{
    int laenge = my_strlen(orig);
    char *kopie = malloc(laenge + 1);
    int i;

    for (i = 0; i < laenge; i++)
    {
        kopie[i] = orig[i] + 1; //ASCII-Code imkrementieren
    }
    kopie[laenge] = '\0';
    return kopie;
}

// Palindrom - Erzeugt aus der gegebenen Zeichenkette durch Anstellen der kopierten, gespiegelten Zeichenkette ein Palindrom
char *my_palindrom(char *orig)
{
    int laenge = my_strlen(orig);
    char *neu = malloc(laenge * 2 + 1);
    int i;
    /*
    for (i=0; i<laenge*2; i++) {
        if(i<laenge){
            neu[i]=orig[i];
        } else {
            neu[i]=orig[laenge*2-1-i];
        }
    }
    */

    for (i = 0; i < laenge; i++)
    {
        neu[i] = orig[i];
    }
    for (i = 0; i < laenge; i++)
    {
        neu[i + laenge] = orig[laenge - 1 - i];
    }

    neu[laenge] = '\0';
    return neu;
}

// String Consonant - kopiert alle Zeichen außer Vokale
char* strcons(char* orig) {
    int orig_laenge = my_str(orig);
    char* neu=malloc(orig_laenge+1);
    int neu_laenge=0;
    int i;
    for(i=0; i<orig_laenge; i++) {
        if(orig[i]!='a'&&orig[i]!='A'&&orig[i]!='e'&&orig[i]!='E'&&orig[i]!='i'&&orig[i]!='I'&&orig[i]!='o'&&orig[i]!='O'&&orig[i]!='u'&&orig[i]!='U') {
            neu[neu_laenge]=orig[i];
            neu_laenge++;
        }
    }
    neu[neu_laenge] ='\0';
    neu = realloc(neu, neu_laenge+1);
    return neu;

}

int main()
{
    // Testen der Funktionen
    return 0;
}