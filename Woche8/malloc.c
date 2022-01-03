#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *zeichen;
    zeichen = malloc(100); //memory allocation, Rückgabe ist ein pointer
    free(zeichen);         // Speicherplatz direkt wieder freigeben


    int groesse = 0;
    char *puffer = 0; // Pointer auf den Speicherplatz

    printf("Wie viel Speicherplatz soll reserviert werden? ");
    scanf("%d", &groesse);
    printf("Ok, reserviere nun %d Byte Speicherplatz \n", groesse);
    puffer = malloc(groesse);

    int i;
    for (i = 0; i < 99; i++)
    {
        puffer[i] = 'a';
    }
    puffer[99] = '\0'; // null ist ein Terminator, der beendet die Zeichenkette
    printf("%s\n", puffer);
    free(puffer);
    return 0;
}