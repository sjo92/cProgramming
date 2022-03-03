#include <stdio.h>
#include <stdlib.h>

/*
Nach Benutzereingabe beliebige Zahlen speichern und die Zahlen im Terminal ausgeben.
*/
int main() {
    int length = 30;
    int i =0;
    int j = 0;
    double summe=0;
    double max;
    double min;
    double *kette = malloc(sizeof (double)*length); //Eine Zeichenkette mit Dynamischer Speichernplatz. 
    do {
        printf("Bitte geben Sie eine Zahl ein: \n");
        double temp;
        scanf("%lf", &temp);
        kette[i] = temp;
        if(i==length) { //Falls der Speicherplatz bereits voll ist, wird der Speicherplatz noch vergrößert.
            length = length +30;
            kette = realloc(kette, length);
            printf("max wurde um %d erhöht", length);
        }
        i++;
    }while(kette[i-1]!=0); //Da i bereits inkrementiert wurde, sollte man den Wert von i-1 anschauen.
    kette =realloc(kette, sizeof (double)*i); //Den Speicherplatz reallkoieren

    max = kette[0]; //Der Max Wert wird mit dem ersten Wert initialisiert
    min = kette[0]; //Der Min Wert wird mit dem ersten Wert initialisiert
    for (j=0; j<i; j++) {
        if(min > kette[j]) {min = kette[j]; }// Wenn aktueller Minimum größer als der j. Wert ist, dann j. Wert der neuste Minimum.
        if(max < kette[j]) {max = kette[j];}  // Wenn aktueller Maximum kleiner als der j. Wert ist, dann j. Wert der neuste Maximum.
        printf("Element [%d]: %.2lf \n", j, kette[j]);
        summe= summe+ kette[j];
    }
    printf("Summe: (%.2lf) \t", summe);
    printf("Min: (%.2lf)  \t", min);
    printf("Max: (%.2lf)  \t", max);
    printf("\n");

    free(kette); //Den Speicherplatz wieder freistellen

    return 0;
}