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
		printf("%d\n", iterator->inhalt);
		iterator = iterator->nachfolger;
	}
}

void liste_rwtausgeben(struct Knoten *iterator)
{
	struct Knoten *vor = NULL;

	while (iterator != NULL)
	{
		struct Knoten *next = iterator->nachfolger; // nächstes Element in der originalen Liste
		iterator->nachfolger = vor;					// Nachfolger Reversen
		vor = iterator;								// Die Reihe fortsetzen wie i++
		iterator = next;							// Die Reihe fortsetzen wie i++
	}
	liste_ausgeben(vor);
}

void liste_rwtausgeben_3(struct Knoten *iterator)
{
	if (iterator != NULL)
	{
		liste_rwtausgeben_3(iterator->nachfolger);
		printf("%d\n", iterator->inhalt);
	}
}

void liste_rwtausgeben_4(struct Knoten *iterator)
{
	int max = 100;
	int *temp = malloc(sizeof(int) * max);
	int i = 0;
	int j = 0;
	do
	{
		temp[i] = iterator->inhalt;
		if (i == max)
		{
			max = max + 100;
			temp = realloc(temp, max);
		}
		iterator = iterator->nachfolger;
		i++;
	} while (iterator != NULL);

	temp = realloc(temp, i);
	for (j = i; j > 0; j--)
	{
		printf("%d\n", temp[j]);
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
	liste_ausgeben(liste);
	// Liste rückwärts ausgeben
	printf("Rückwärts:\n");
	liste_rwtausgeben_3(liste);
	return 0;
}
