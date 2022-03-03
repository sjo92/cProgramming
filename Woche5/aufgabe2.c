#include <stdio.h>
#include <stdlib.h>
#define SPEICHER 10

/*
Nach Benutzereingabe genau 10 ganze Zahlen speichern.
Der Programm wird das Maximum, Minimum, die Summe und den Durchschnitt ausgeben.

*/
int main() {
    int i;
    int max;
    int min;
    int summe=0;
    double durchschnitt=0;
    int zahl[SPEICHER];
    
    /*
    Schleife für Benutzereingabe
    */
    for(i=0; i<SPEICHER; i++){
        int temp;
        printf("Bitte geben Sie %d ganze Zahl ein. \n", SPEICHER);
        printf("%d. Zahl: ", i+1);
        scanf("%d", &temp);
        zahl[i] = temp;
    }
    max = zahl[0]; //Der Max Wert initialisieren mit dem ersten Wert von der Zeichenkette
    min = zahl[0]; //Der Min Wert initialisieren mit dem ersten Wert von der Zeichenkette

    /*
    Schleife für die Werte prüfen (Max, Min, Summe)
    */
    for (i=0; i<SPEICHER; i++) {
        if(zahl[i]>max) max = zahl[i];
        if(zahl[i]<min) min = zahl[i];
        summe = summe + zahl[i];
    } 
    durchschnitt = (double) (summe) / SPEICHER;

    /*
    Schleife für die Werte ausgeben
    */
    for (i=0; i<SPEICHER; i++) {
        printf("Die %d. Zahl war : %d", i+1, zahl[i]);
        if(max == zahl[i]) printf("<-- groesste Zahl");
        if(min == zahl[i]) printf("<-- kleinste Zahl");
        printf("\n");
    } 
    printf("Das macht zusammen %d\n", summe);
    printf("Durchschnitt lautet %.1lf\n", durchschnitt);
}