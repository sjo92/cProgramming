#include <stdio.h>

int main() {
    long ISBN;
    int summe=0;
    int i=0;
    int gueltigkeit=-1;
    printf("Bitte geben Sie eine ISBN ein:");
    scanf("%ld", &ISBN);
    //ISBN ist eine 13 Zähllige Nummer
    //gültigkeit prüfen: z1+z3+z5+z7+z9+z11+z13 + 3*(z2+z4+z6+z8+z10+z12) mod 10 soll 0 ausgeben

    for(i=1; i<14; i++) {
        //Ziffern in ungerade Stelle  einfach addieren
        if(i%2==1) {
            summe= summe + (ISBN%10);
        }
        //Ziffern in gerade Stelle 3fach multiplizieren
        if(i%2==0) {
            summe = summe + 3*(ISBN%10);
        }
        ISBN=ISBN/10;
    } 

    if (summe%10==0) {
        gueltigkeit=1;
        printf("ISBN ist gütig");
    } else {
        gueltigkeit=0;
        printf("ISBN ist ungütig");
        }

    

}