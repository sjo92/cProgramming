#include <stdio.h>

struct Person
{
    char vorname[100];
    char nachname[100];
    int alter;
};

void person_ausgeben(struct Person person)
{
    printf("%s %s ist %d Jahre alt. \n", person.vorname, person.nachname, person.alter);
}

struct Person person_einlesen()
{
    struct Person new;
    printf("Vorname: ");
    scanf("%s", new.vorname);
    printf("Nachname: ");
    scanf("%s", new.nachname);
    printf("Alter: ");
    scanf("%d", &new.alter);

    return new;
}

/*
void person_einlesen() {
    char vorname[100];
    char nachname[100];
    int alter;
    printf("Vorname: ");
    scanf("%s", vorname);
    printf("Nachname: ");
    scanf("%s", nachname);
    printf("Alter: ");
    scanf("%d", alter);

    return (vorname, nachname, alter);
}
*/
int main()
{
    struct Person dozent;
    dozent = person_einlesen();
    person_ausgeben(dozent);
    return 0;
}