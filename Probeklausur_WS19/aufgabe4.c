#include <stdio.h>
#include <stdlib.h>

struct Knoten
{
    int inhalt;
    struct Knoten *nachfolger;
};

struct Knoten *knoten_einfuegen(struct Knoten *anfang, int eingabe)
{
    struct Knoten *temp = malloc(sizeof(struct Knoten));
    temp->inhalt = eingabe;
    temp->nachfolger = anfang;
    if (anfang != NULL)
    {
        anfang = anfang->nachfolger;
    }
    anfang = temp;

    return anfang;
}

void liste_ausgeben(struct Knoten *anfang)
{
    printf("Die Elemente der aktuellen Liste lauten: \n");
    while (anfang != NULL)
    {
        printf("%d\n", anfang->inhalt);
        anfang = anfang->nachfolger;
    }
}

/*Den direkt vorherigen Knoten finden mit index -1 */
struct Knoten *find_knoten(struct Knoten *anfang, int index)
{
    int temp = 0;
    if (index >= 1)
    {
        while (anfang != NULL)
        {
            if (temp == index - 1)
            {
                return anfang;
            }
            temp++;
            anfang = anfang->nachfolger;
        }
    }

    return NULL;
}

int max_length(struct Knoten *anfang)
{
    int length = 0;
    while (anfang->nachfolger != NULL)
    {
        anfang = anfang->nachfolger;
        length++;
    }
    return length;
}
struct Knoten *knoten_hinzufuegen(struct Knoten *anfang, int index, int inhalt_temp)
{
    struct Knoten *temp = malloc(sizeof(struct Knoten));
    temp->inhalt = inhalt_temp;

    int length = max_length(anfang);
    if (length < index)
    {
        printf("Die angegebene Index ist zu groß!! Maximale Index ist %d.\n", length);
        return anfang;
    }

    if (anfang == NULL)
    {
        return NULL;
    }
    if (index == 0)
    {
        temp->nachfolger = anfang;
        printf("\n/* ACHTUNG */ \n%d wird in %d. Position hinzugefügt.\n\n", temp->inhalt, index);
        anfang = temp;
    }
    else
    {
        struct Knoten *temp_1 = find_knoten(anfang, index);
        struct Knoten *target = temp_1->nachfolger;
        printf("\n/* ACHTUNG */ \n%d wird in %d. Position hinzugefügt.\n\n", temp->inhalt, index);
        if (temp_1 != NULL && target != NULL)
        {
            temp_1->nachfolger = temp;
            temp->nachfolger = target;
        }
        else if (target == NULL)
        {
            temp_1->nachfolger = temp;
            temp->nachfolger = NULL;
        }
    }
    return anfang;
}
struct Knoten *knoten_loeschen(struct Knoten *anfang, int index)
{
    int temp = 0;
    int length = max_length(anfang);
    if (length < index)
    {
        printf("Die angegebene Index ist zu groß!! Maximale Index ist %d.\n", length);
        return anfang;
    }

    if (anfang == NULL)
    {
        return NULL;
    };
    if (index == 0)
    {
        struct Knoten *neu_anfang = NULL;
        printf("\n/* ACHTUNG */ \n%d in %d. Position wird gelöscht.\n\n", anfang->inhalt, index);
        neu_anfang = anfang->nachfolger;
        free(anfang);
        anfang = neu_anfang;
    }
    else
    {
        struct Knoten *temp_1 = find_knoten(anfang, index);
        struct Knoten *target = temp_1->nachfolger;
        printf("\n/* ACHTUNG */ \n%d in %d. Position wird gelöscht.\n\n", target->inhalt, index);
        if (temp_1 != NULL && target != NULL)
        {
            temp_1->nachfolger = target->nachfolger; // nachfolger überspringen
            free(target);
        }
        else if (target == NULL)
        {
            temp_1->nachfolger = NULL;
        }
    }
    return anfang;
}

int main()
{
    struct Knoten *anfang = NULL;
    anfang = knoten_einfuegen(anfang, 12);
    anfang = knoten_einfuegen(anfang, 23);
    anfang = knoten_einfuegen(anfang, 24);
    anfang = knoten_einfuegen(anfang, 25);
    liste_ausgeben(anfang);
    anfang = knoten_loeschen(anfang, 3);
    liste_ausgeben(anfang);
    anfang = knoten_hinzufuegen(anfang, 2, 55);
    liste_ausgeben(anfang);
    return 0;
}