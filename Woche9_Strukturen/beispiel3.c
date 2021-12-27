#include <stdio.h>
#define ANZAHL 3
struct Kontakt
{
    char name[100];
    char nummer[100];
    struct Kontakt *partner;
};

int main()
{
    struct Kontakt eva = {"Eva", "1234", 0};
    struct Kontakt adam = {"Adam", "1234", &eva};
    eva.partner = &adam;

    printf("Die Partnerin von %s heißt %s. \n", adam.name, adam.partner->name);
    printf("Der Partner von %s heißt %s. \n", adam.partner->name, adam.partner->partner->name);

    /*
    struct Kontakt adressbuch[ANZAHL];
    for (int i = 0; i < ANZAHL; i++)
    {
        printf("%d. Adresseeintrag\n", i + 1);
        printf("Name: ");
        scanf("%s", adressbuch[i].name);
        printf("Nummer: ");
        scanf("%s", adressbuch[i].nummer);
    }
    printf("Ausgabe des Adressbuchs\n");
    for (int i = 0; i < ANZAHL; i++)
    {
        printf("Die %d. Person heißt %s und hat die Nummer %s. \n", i + 1, adressbuch[i].name, adressbuch[i].nummer);
    }
*/

    return 0;
}