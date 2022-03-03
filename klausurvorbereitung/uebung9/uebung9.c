#include <stdio.h>

int betrag_umrechnen(double betrag_init) {
    //Achtung: 12.349999999€ wird als 1235 Cents ausgegeben
    int rest = (int) (betrag_init*1000); //12349
    int betrag;
    if(rest%10 >=5) {
        betrag = (int) (betrag_init*100+0.5); //12.349 => 1234.9 + 0.5 = 1235.4 
    } else {
        betrag =(int) (betrag_init*100+0.5);
    }
    return betrag;
} 

void muenzen_ausgeben(anzahl, muenzen) {
    switch (anzahl) {
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
        case 5:
            printf("Fünf ");
            break;
        default:
            printf("%d ", anzahl);
            break;
    }
    if (muenzen >=100) {
        printf("%d-Euro-", muenzen/100);
    } else {
        printf("%d-Cent-", muenzen);
    }
    if(anzahl==1) {
        printf("Muenze\n");
    } else {
        printf("Muenzen\n");
    }
}
/*
Der Programm werden nach Benutzereingabe die verfügbaren Münzen rechnen und ausgeben.
*/
int main() {
    double betrag_init;
    int betrag;
    int muenzen[]= {200, 100, 50, 20, 10, 5, 2, 1};
    int i=0;
    int anzahl=0;
    printf("Der Betrag: ");
    scanf("%lf", &betrag_init);
    //Gesamtbetrag in Cent umrechnen, um den Roudingfehler zu vermeiden.
    betrag = betrag_umrechnen(betrag_init);

    while(betrag>0) {
        if (betrag >= muenzen[i]) {
            anzahl = betrag / muenzen[i]; // 850:200 = 4 
            muenzen_ausgeben(anzahl, muenzen[i]);
            betrag = betrag %muenzen[i]; // 850%200 = 50
        }
        i++;
    }
    
    return 0;
}