#include <stdio.h>
#include "readtext.c"

struct PERSON {
    char *vorname;
    char *nachname;
    int alter;
    char *geschlecht;
};

struct PERSON *person_einlesen(struct PERSON *temp) {
    printf("Vorname: ");
    temp->vorname=readtext();
    printf("Nachname: ");
    temp->nachname=readtext();
    
    printf("Alter: ");
    scanf("%d", &temp->alter);
    getchar();
    printf("Geschlecht: [W: 0, M: 1]\n");
    temp->geschlecht=readtext();
    return temp;
}
void person_validieren(struct PERSON *temp) {

    if(temp->vorname[0]=='\0') {
        printf("Vorname fehlt!\n");
    }
    if(temp->nachname[0]=='\0') {
        printf("Nachname fehlt!\n");
    }
    if(temp->geschlecht[0]=='\0') {
        printf("Das Geschlecht fehlt!\n");
    }
}

void person_ausgeben(struct PERSON *person) {
    if(person->geschlecht[0] =='0') {
        printf("Frau ");
    }else if (person->geschlecht[0] =='1') {
        printf("Herr ");
    }
    printf("%s ", person->vorname);
    printf("%s ", person->nachname);
    printf("(%d)\n", person->alter);
} 

struct PERSON * person_loeschen(struct PERSON *person) {
    if (person!=NULL) {

    free(person);
    person=NULL;
    printf("Die Person wurde erfolgreich gelöscht.\n");
    }
    return person;
}

void person_vergleichen(struct PERSON *person_a, struct PERSON *person_b) {
    if(person_a->alter >person_b->alter) {
        printf("%s ist %d Jahre älter als %s\n", person_a->vorname, person_a->alter-person_b->alter, person_b->vorname);
    } else if (person_b->alter >person_a->alter) {
        printf("%s ist %d Jahre älter als %s\n", person_b->vorname, person_b->alter-person_a->alter, person_a->vorname);
    }
}


int main() {
    struct PERSON *person_a =malloc(sizeof(struct PERSON));
    struct PERSON *person_b =malloc(sizeof(struct PERSON)); 
    person_einlesen(person_a);
    person_einlesen(person_b);

    person_ausgeben(person_a);
    person_validieren(person_a);

    person_vergleichen(person_a, person_b);
    person_a=person_loeschen(person_a);
    return 0;
}