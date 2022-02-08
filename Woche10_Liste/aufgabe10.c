#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"

struct Element
{
    int inhalt;
    struct Element *nachfolger;
};

void liste_rekursiv_ausgeben(struct Element *anfang)
{
    if (anfang != NULL)
    {
        printf("%d ", anfang->inhalt);
        liste_rekursiv_ausgeben(anfang->nachfolger);
    }
}

void liste_rekursiv_rueckwaerts_ausgeben(struct Element *anfang)
{
    if (anfang != NULL)
    {
        liste_rekursiv_ausgeben(anfang->nachfolger);
        printf("%d ", anfang->inhalt);
    }
}

void value_init(struct Element *element1, struct Element *element2, struct Element *element3, struct Element *element4)
{
    element1->inhalt = 10;
    element1->nachfolger = element2;

    element2->inhalt = 20;
    element2->nachfolger = element3;

    element3->inhalt = 30;
    element3->nachfolger = element4;

    element4->inhalt = 40;
    element4->nachfolger = NULL;
}

void liste_einfuegen(struct Element **anfang, struct Element *neu)
{

    neu->inhalt = 42;
    neu->nachfolger = *anfang;
    *anfang = neu;
    printf("neu: %d\n", neu->inhalt);
    printf("anfang: %p\n", anfang);
}

void liste_ausgeben(struct Element *anfang)
{
    struct Element *temp = anfang;
    while (temp != NULL)
    {
        printf("%d\n", temp->inhalt);
        temp = temp->nachfolger;
    }
}

void liste_delete(struct Element *anfang, struct Element **element_target)
{
    struct Element *temp = anfang;
    struct Element *temp2 = *element_target;
    while (temp != NULL)
    {
        if (temp->nachfolger == *element_target)
        {
            temp->nachfolger = temp2->nachfolger;
        }
        temp = temp->nachfolger;
    }
}
void liste_ausgeben_index(struct Element *anfang)
{
    int index = 0;
    printf("Bitte geben Sie den gewünschten Index ein:");
    scanf("%d", &index);
    int temp_ind = 0;
    struct Element *temp = anfang;
    while (temp != NULL)
    {
        if (temp_ind == index)
        {
            printf("%d. Index / Element : %d\n", index, temp->inhalt);
        }
        temp = temp->nachfolger;
        temp_ind++;
    }
}

int main()
{
    struct Element *element1 = malloc(sizeof(struct Element));
    struct Element *element2 = malloc(sizeof(struct Element));
    struct Element *element3 = malloc(sizeof(struct Element));
    struct Element *element4 = malloc(sizeof(struct Element));
    struct Element *anfang = NULL;
    anfang = element1;

    struct Element *neu = malloc(sizeof(struct Element));
    value_init(element1, element2, element3, element4);
    liste_einfuegen(&anfang, neu);
    liste_ausgeben(anfang);
    liste_delete(anfang, &element3);
    liste_ausgeben_index(anfang);
}