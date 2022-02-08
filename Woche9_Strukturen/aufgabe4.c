
#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"
#include <string.h>

void get_numbers(int num_coin)
{
    switch (num_coin)
    {
    case 1:
        printf("Eine ");
        break;
    case 2:
        printf("Zwei ");
        break;
    case 3:
        printf("Drei ");
        break;
    case 4:
        printf("Vier ");
        break;
    default:
        printf("%d", num_coin);
        break;
    }
}
void get_coins(int betrag)
{
    int coins[8] = {200, 100, 50, 20, 10, 5, 2, 1};
    int i = 0;

    do
    {
        int num_coin = 0;

        if (betrag / coins[i] >= 1)
        {
            // 835 /200 = 4, restbetrag: 835-(4*200)
            num_coin = betrag / coins[i];
            get_numbers(num_coin);

            if (i <= 1)
            {
                printf("%d-", coins[i] / 100);
                printf("Euro-");
            }
            else
            {
                printf("%d-", coins[i]);
                printf("Cent-");
            }

            if (num_coin > 1)
            {
                printf("Muenzen\n");
            }
            else
            {
                printf("Muenze\n");
            }
        }
        betrag = betrag - (num_coin * coins[i]);
        i++;
    } while (betrag != 0);
}

int runden_100(double eingabe)
{
    int copy;
    copy = (int)(eingabe * 1000);
    if (copy % 10 >= 5)
    { //8.345+0.005 = 8.35
        copy = (int)((eingabe + 0.005) * 1000 / 10);
    }
    else //8.340+0.005 = 8.34
        copy = (int)((eingabe)*1000) / 10;

    return copy;
}

void aufgabe_1()
{
    double eingabe;
    int x;
    printf("Wie gross ist der Euro-Betrag, welcher in moeglichst wenig Muenzen aufgeteilt werden soll?");
    scanf("%lf", &eingabe);
    x = runden_100(eingabe);
    get_coins(x);
}

int readint()
{
    int zahl = 0;
    int size = 10;
    int pos = 0;
    int i = 0;
    int vorzeichen = 1;
    char c;
    char *nums = malloc(size);

    do
    {
        c = getchar();
        if (c != 10)
        {
            nums[pos] = c;
            pos++;

            if (pos == size)
            {
                size = size + size;
                nums = realloc(nums, size);
            }
        }
    } while (c != 10);
    nums[pos] = '\0';

    while ((nums[i] >= '0' && nums[i] <= '9') || nums[i] == '-' || nums[i] == '+')
    {
        if (nums[0] == '-')
        {
            vorzeichen = -1;
        }
        if (nums[i] >= '0' && nums[i] <= '9')
        { //133 (1. Runde):1 (2): 13 =10*1+3 (3) 133: 100*1+10*3+3
            zahl = zahl * 10 + (nums[i] - '0');
        }
        else if (i != 0 && (nums[i] == '-' || nums[i] == '+'))
        {
            zahl = zahl * vorzeichen;
            free(nums);
            return zahl;
        }
        i++;
    }
    zahl = zahl * vorzeichen;
    free(nums);
    return zahl;
}

void aufgabe_2()
{
    int zahl;
    printf("Bitte geben Sie eine Zahl ein: ");
    zahl = readint();
    printf("Die Zahl lautet %d.(%p)\n", zahl, &zahl);
}

struct Tupel
{
    int x;
    int y;
    int z;
};

void tupel_einlesen(struct Tupel *eingabe)
{
    printf("Wie lautet der Wert für x? ");
    eingabe->x = readint();
    printf("Wie lautet der Wert für y? ");
    eingabe->y = readint();
    printf("Wie lautet der Wert für z? ");
    eingabe->z = readint();
}

void tupel_ausgeben(struct Tupel *eingabe)
{
    printf("(%d, %d, %d)\n", eingabe->x, eingabe->y, eingabe->z);
}

void tupel_addieren(struct Tupel *a, struct Tupel *b, struct Tupel *result)
{
    result->x = a->x + b->x;
    result->y = a->y + b->y;
    result->z = a->z + b->z;

    tupel_ausgeben(result);
}
void aufgabe_3()
{
    struct Tupel *vektor_a = malloc(sizeof(struct Tupel));
    tupel_einlesen(vektor_a);
    struct Tupel *vektor_b = malloc(sizeof(struct Tupel));
    tupel_einlesen(vektor_b);
    struct Tupel *vektor_add = malloc(sizeof(struct Tupel));
    tupel_addieren(vektor_a, vektor_b, vektor_add);
}

struct PERSON
{
    char *vorname;
    char *nachname;
    int alter;
    int gender;
};

void person_validieren(struct PERSON *person)
{
    int error = 0;
    int i = 0;

    if (person->vorname == NULL)
    {
        printf("Der Vorname fehlt! Bitte geben Sie erneut einen Name ein: ");
        person->vorname = readtext();
    }
    else
    {
        while (person->vorname[i] != '\0')
        {
            if (!(person->vorname[i] >= 'A' && person->vorname[i] <= 'Z') && !(person->vorname[i] >= 'a' && person->vorname[i] <= 'z'))
            {
                error++;
            }
            i++;
        }
        if (error >= 1)
        {
            printf("Der Vorname %s ist ungültig. Bitte geben Sie einen neuen Name ein: \n", person->vorname);
            person->vorname = readtext();
            person_validieren(person);
        }
    }
    if (!(person->alter >= 0 && person->alter <= 99))
    {
        printf("Das Alter %d ist ungültig. Bitte geben Sie eine neue Zahl ein: \n", person->alter);
        person->alter = readint();
        person_validieren(person);
    }
    if (!(person->gender >= 0 && person->gender <= 2))
    {
        printf("Das gegebene Gender %d ist ungültig. Für Gender wählen Sie eine Zahl: \n(männlich: 1, weblich: 2, keine Angabe: 0)", person->gender);
        person->gender = readint();
        person_validieren(person);
    }
}

void person_initialisieren(struct PERSON *new)
{

    new->vorname = NULL;
    new->nachname = NULL;
    new->alter = 0;
    new->gender = 0;
}

void person_einlesen(struct PERSON *new)
{
    /*
    printf("Vorname: ");
    new->vorname=readtext();*/

    printf("Nachname: ");
    new->nachname = readtext();

    printf("Alter: ");
    new->alter = readint();

    printf("Für Gender wählen Sie eine Zahl: \n(männlich: 1, weblich: 2, keine Angabe: 0) ");
    new->gender = readint();
}

void person_ausgeben(struct PERSON *person)
{
    person_validieren(person);

    if (person->gender == 1)
    {
        printf("Herr ");
    }
    else if (person->gender == 2)
    {
        printf("Frau ");
    }
    printf("%s %s ", person->vorname, person->nachname);
    printf("(% d )\n", person->alter);
}

void person_delete(struct PERSON *person)
{
    char name[100];
    char res;

    printf("Zum löschen des Datensatzes geben Sie Ihren Nachnahme nochmal ein: ");
    scanf("%s", name);

    if (strcmp(name, person->nachname) == 0)
    {
        printf("Sind Sie sicher, Ihren Datensatz zu löschen? (Y/N)\n");
        scanf("%s", &res);

        if (res == 'Y' || res == 'y')
        {
            free(person);
            printf("%s wurde gelöscht. %p", name, &person);
        }
    }
    else
    {
        printf("Der Datensatz wurde nicht gelöscht.\n");
    }
}

void alter_vergleichen(struct PERSON *person_1, struct PERSON *person_2)
{
    if (person_1->alter > person_2->alter)
    {
        printf("%s %s ist älter als %s %s.\n", person_1->vorname, person_1->nachname, person_2->vorname, person_2->nachname);
    }
    else if (person_2->alter > person_1->alter)
    {
        printf("%s %s ist älter als %s %s.\n", person_2->vorname, person_2->nachname, person_1->vorname, person_1->nachname);
    }
    else
    {
        printf("%s %s und %s %s sind beide %d Jahre alt.\n", person_1->vorname, person_1->nachname, person_2->vorname, person_2->nachname, person_2->alter);
    }
}

void aufgabe_4()
{
    struct PERSON *person_1 = malloc(sizeof(struct PERSON));
    person_initialisieren(person_1);
    person_einlesen(person_1);

    struct PERSON *person_2 = malloc(sizeof(struct PERSON));
    person_initialisieren(person_2);
    person_einlesen(person_2);
    alter_vergleichen(person_1, person_2);

    person_ausgeben(person_1);
    person_validieren(person_1);
    person_delete(person_1);
}
int main()
{
    aufgabe_3();
    return 0;
}
