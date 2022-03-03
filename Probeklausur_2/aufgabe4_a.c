#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct Knoten
{
	int inhalt;
	struct Knoten *nachfolger;
};

// Fügt einen neuen Knoten am Anfang der Liste hinzu
// 1. Parameter ist der Integer-Inhalt des neu zu erzeugenden Knotens
// 2. Parameter ist der bisherige Anfang der Liste
// Rückgabewert ist der neue Anfang der Liste
struct Knoten *knoten_am_anfang_einfuegen(int inhalt, struct Knoten *anfang)
{
	struct Knoten *neu = malloc(sizeof(struct Knoten)); // Speicherplatz reservieren
	neu->inhalt = inhalt;								// Inhaltswert setzen
	neu->nachfolger = anfang;							// Bisheriger Listenanfang nun an 2. Stelle
	return neu;
}

// Gibt die Liste in Vorwärtsreihenfolge auf dem Bildschirm aus
void liste_ausgeben(struct Knoten *iterator)
{
	while (iterator != NULL)
	{
		printf("%p\t %d\n", iterator, iterator->inhalt);
		iterator = iterator->nachfolger;
	}
}
void liste_ausgeben_rek(struct Knoten *iterator)
{
    if(iterator!=NULL) {
        printf("%p\t %d\n", iterator, iterator->inhalt);
        liste_ausgeben_rek(iterator->nachfolger);
    }
}

void liste_rwts_ausgeben_2(struct Knoten *iterator)
{
    if (iterator!=NULL) {
        liste_rwts_ausgeben_2(iterator->nachfolger);
        printf("%d\n", iterator->inhalt);
    }
}

int main()
{
	struct Knoten *liste = NULL;
	int eingabe = 0;
	// Liste einlesen
	do
	{
		printf("Bitte eine Zahl eingeben: ");
		scanf("%d", &eingabe);
		liste = knoten_am_anfang_einfuegen(eingabe, liste);
	} while (eingabe != 0);
	// Liste vorwärts ausgeben
	printf("Vorwärts:\n");
	liste_ausgeben_rek(liste);
	// Liste rückwärts ausgeben
	printf("Rückwärts:\n");
	liste_rwts_ausgeben_2(liste);
	return 0;
}
