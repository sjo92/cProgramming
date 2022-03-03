#include <stdio.h>
#include <stdlib.h>

struct Element {
    int inhalt;
    struct Element *nachfolger;
};

struct Element *liste_einfuegen(struct Element *anfang, int wert) {
    struct Element *temp = malloc(sizeof(struct Element));
    if(anfang ==NULL) {
        temp->nachfolger = NULL;
    }
    temp->inhalt = wert;
    temp->nachfolger = anfang; // Der aktueller Anfang wird jetzt nachfolger von dem anfang

    return temp;
}

void liste_ausgeben(struct Element *anfang) {
    while(anfang!=NULL) {
        printf("%d\n", anfang->inhalt);
        anfang = anfang->nachfolger;
    }
}

struct Element *erhalten_in_index(struct Element *anfang, int index) {
    int i=0;
    while(anfang!=NULL) {
        if(i==index) {
            printf("(%d, %d)\n", index, anfang->inhalt);
            return anfang;}
        anfang = anfang->nachfolger;
        i++;
    }
    printf("Index zu groß! %d. Element nicht zu finden\n", index);
    return NULL;
}

struct Element *liste_loeschen_per_index(struct Element *anfang, int index) {
    struct Element *head=anfang;
    int i=0;
    if(anfang==NULL) return NULL;
    if(index==0) {
        struct Element *temp;
        temp = anfang;
        anfang = anfang->nachfolger;
        free(temp);
        temp = NULL;
        return anfang;
    }
    while(anfang!=NULL) {
        if(i==index-1 && anfang->nachfolger !=NULL) {
            struct Element *temp;
            printf("(%d, %d) wird nun gelöscht\n", index, anfang->nachfolger->inhalt);
            temp = anfang->nachfolger;
            anfang->nachfolger= anfang->nachfolger->nachfolger;
            free(temp);
            temp=NULL;
            return head;
            } 
            else if (i==index-1 && anfang->nachfolger->nachfolger==NULL) {
            struct Element *temp;
            temp = anfang->nachfolger;
            anfang->nachfolger = NULL;
            free(temp);
            temp=NULL;
            return head;
            }
        anfang = anfang->nachfolger;
        i++;
    }
    printf("Index zu groß! %d. Element nicht zu finden\n", index);
    return NULL;
}
struct Element *liste_loeschen_per_target(struct Element *anfang, int target) {
    struct Element* head = anfang;
    int i=0;
    if(anfang==NULL) return NULL;
    if(anfang->inhalt == target) { //Wenn das erste Element gelöscht werden soll
        struct Element *temp;
        temp = anfang;
        printf("(0, %d) wird nun gelöscht\n", anfang->inhalt);
        i=i+1;
        anfang = anfang->nachfolger;
        free(temp);
        return anfang;
    }
    while(anfang!=NULL) {
        if(anfang->nachfolger->inhalt==target && anfang->nachfolger !=NULL) {
            struct Element *temp;
            printf("(%d, %d) wird nun gelöscht\n", i, anfang->nachfolger->inhalt);
            temp = anfang->nachfolger;
            anfang->nachfolger= anfang->nachfolger->nachfolger;
            free(temp);
            temp=NULL;
            return head;
            } 
            else if (anfang->nachfolger->inhalt==target && anfang->nachfolger->nachfolger==NULL) {
            struct Element *temp;
            printf("(%d, %d) wird nun gelöscht\n", i-1, anfang->nachfolger->inhalt);
            temp = anfang->nachfolger;
            anfang->nachfolger = NULL;
            free(temp);
            temp=NULL;
            return head;
            }
        anfang = anfang->nachfolger;
        i++;
    }
    printf("Element mit Inhalt %d nicht zu finden\n", target);
    return NULL;
}

struct Element *liste_reverse(struct Element*anfang) {
    struct Element *temp=NULL;
    struct Element *vor=NULL;
    while(anfang!=NULL) {
        
        vor = anfang->nachfolger;
        anfang->nachfolger=temp;
        temp = anfang;
        anfang = vor;
        
    }
    
    return temp;
}
struct Element *liste_reverse_rek(struct Element*anfang, struct Element *temp) {
    if (anfang==NULL) return temp; 
    else{
        struct Element *vor = NULL;
        vor = anfang->nachfolger;
        anfang->nachfolger = temp;
        return liste_reverse_rek(vor, anfang);
    }
}

struct Element *einfuegen_an_Index(struct Element* anfang, int inhalt, int index) {
    struct Element* head = anfang;
    struct Element* temp=malloc(sizeof(struct Element));
    temp->inhalt = inhalt;
    int i=0;
    for(i=0; i<index-1; i++) {
        anfang = anfang->nachfolger;
    }
    temp->nachfolger = anfang->nachfolger;
    anfang->nachfolger = temp;
    
    return head;
}


int main() {
    struct Element *anfang = NULL;
    struct Element *temp = NULL;
    anfang = liste_einfuegen(anfang, 3);
    anfang = liste_einfuegen(anfang, 4);
    anfang = liste_einfuegen(anfang, 5);
    anfang = liste_einfuegen(anfang, 6);

    liste_ausgeben(anfang);
    anfang = einfuegen_an_Index(anfang, 30, 2);
    liste_ausgeben(anfang);
    //struct Element *element_a=erhalten_in_index(anfang, 1);
    //anfang = liste_loeschen_per_index(anfang, 2);
    //anfang = liste_loeschen_per_target(anfang, 5);

    //anfang = liste_reverse(anfang);
    //anfang=liste_reverse_rek(anfang, temp);
    //liste_ausgeben(anfang);
    return 0;
}