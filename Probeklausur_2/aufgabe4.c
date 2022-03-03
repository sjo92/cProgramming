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

/* Die Liste Rückwärts anpassen und ausgeben

Beispiel: (3->2->1->0->NULL)

1. Iteration (3->2->1->0->NULL)
iterator: 3 / next: 2
prev->nachfolger: NULL / prev: 3 /iterator: 2

2. Iteration (2->1->0->NULL)
iterator: 2 / next: 1
prev->nachfolger: 3 / prev: 2 /iterator: 1

3. Iteration (1->0->NULL)
iterator: 1 / next: 0
prev->nachfolger: 2 / prev: 1 /iterator: 0

4. Iteration (0->NULL)
iterator: 0 / next: NULL
prev->nachfolger: 1 / prev: 0 /iterator: NULL

Schleife Ende
ausgeben(prev): (0->1->2->3->NULL)
ausgeben(iterator): (NULL)

 */
void liste_rwts_ausgeben(struct Knoten *iterator)
{
	struct Knoten *prev = NULL;

	while (iterator != NULL)
	{
		struct Knoten *next = NULL;
		next = iterator->nachfolger;			 // speichern den aktuellen nächsten Knoten in next
		iterator->nachfolger = prev;			 // Pointer umbiegen an prev
		prev = iterator;						 // nächster Schritt wie i++ in For Schleife
		prev->nachfolger = iterator->nachfolger; // nur zum Verständnis. Der Wert von prev (iterator->nachfolger) wird in prev->nachfolger gesetzt.
		iterator = next;						 // nächster Schritt wie i++ in For Schleife
	}
	liste_ausgeben(prev);
}

void liste_rwts_ausgeben_2(struct Knoten *iterator)
{
	struct Knoten *prev = malloc(sizeof(struct Knoten)); //-> Am Ende kommt ein Extra 0 raus.

	while (iterator != NULL)
	{
		struct Knoten *next = NULL;
		next = iterator->nachfolger; // speichern den aktuellen nächsten Knoten in next
		iterator->nachfolger = prev; // Pointer umbiegen an prev
		prev = iterator;			 // nächster Schritt wie i++ in For Schleife
		iterator = next;			 // nächster Schritt wie i++ in For Schleife
	}
	liste_ausgeben(iterator); // Hier zum testen, der korrekte Wert ist eigentlich prev, nicht iterator
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
	liste_rwts_ausgeben(liste);
	return 0;
}
