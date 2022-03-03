#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"

struct Element
{
    int inhalt;
    struct Element *nachfolger;
};

struct Element *add_anfang(struct Element *anfang, int wert)
{
    struct Element *temp = malloc(sizeof(struct Element));
    temp->inhalt = wert;
    temp->nachfolger = anfang;
    return temp;
}

void liste_ausgeben(struct Element *anfang)
{
    while (anfang != NULL)
    {
        printf("%4d\t", anfang->inhalt);
        anfang = anfang->nachfolger;
    }
    printf("\n");
}

struct Element *liste_loeschen(struct Element *anfang, int input)
{
    int index = 0;
    if (anfang == NULL)
    {
        printf("Die Liste ist leer!\n");
        return NULL;
    }
    // Das erste Element löschen
    if (input == 0)
    {
        printf("Das erste Element %d wird gelöscht\n", anfang->inhalt);
        // Erstes Element löschen
        struct Element *neuer_anfang = anfang->nachfolger;
        free(anfang);
        anfang = neuer_anfang;
    }
    else
    {

        // Weiter hinten hinten löschen
        int i = 0;
        while (i < input - 1 && anfang != NULL)
        {
            i++;
            anfang = anfang->nachfolger;
        }
        // Wir sind nun beim Vorgänger des zu löschenden Elements
        struct Element *loesch_mich = anfang->nachfolger;
        if (loesch_mich != NULL)
        {
            // Mitten in der Liste wird gelöscht
            anfang->nachfolger = loesch_mich->nachfolger;
            free(loesch_mich);
        }
        else
        {
            // Letztes Element wird gelöscht
            anfang->nachfolger = NULL;
        }
    }
    return anfang;
}

void get_element(struct Element *anfang, int input)
{
    int index = 0;
    while (anfang != NULL)
    {
        if (input == index)
        {
            printf("%d.tes Element lautet: %d\n", input, anfang->inhalt);
        }
        anfang = anfang->nachfolger;
        index++;
    }
}

int main()
{
    int userinput = 0;
    struct Element *anfang = malloc(sizeof(struct Element));
    anfang = add_anfang(anfang, 10);
    anfang = add_anfang(anfang, 20);
    anfang = add_anfang(anfang, 30);
    anfang = add_anfang(anfang, 40);

    liste_ausgeben(anfang);
    printf("Bitte geben Sie den gewünschten Index ein: \n");
    scanf("%d", &userinput);
    get_element(anfang, userinput);
    anfang = liste_loeschen(anfang, userinput);
    liste_ausgeben(anfang);
    return 0;
}