//malloc realloc und free
#include <stdio.h>
#include <stdlib.h> //standard library

int main()
{
    int anzahl;
    printf("Wie viele Zahlen sollen eingelesen werden? ");
    scanf("%d", &anzahl);
    printf("Ok, es werden nun %d Zahlen eingelesen. \n", anzahl);
    int *zahlen = malloc(anzahl * sizeof(int)); // ACHTUNG!! int hat andere Speicherplatz
    int i;
    for (i = 0; i < anzahl; i++)
    {
        printf("Bitte gebe die %d. Zahl ein: ", i + 1);
        scanf("%d", &zahlen[i]);
    }
    for (i = 0; i < anzahl; i++)
    {
        printf("Die %d. Zahl ist die %d.\n", i + 1, zahlen[i]);
    }
    printf("Sollen es vielleicht ein paar Zahlen mehr sein? ");
    scanf("%d", &anzahl);
    zahlen = realloc(zahlen, anzahl); //reallocation, Speicherplatz nachträglich verkleinern oder vergrößern
    free(zahlen);
    return 0;
}

/*
malloc(Größe) reserviert Speicherplatz für Größe Bytes - zurückgeliefert wird der Printer auf den Speicherbereichsanfang
realloc(Pointer, Größe) verändern der reservierten Speicherplatzgröße zurückgeliefert wird der Pointer auf den Speicherbereichsanfang

man realloc
*/