#include <stdio.h>

int main() {
    double zahl_1=0.0;
    double zahl_2=0.0;
    double summe;
    int vergleich;

    printf("Bitte geben Sie eine Zahl ein: \n");
    scanf("%lf", &zahl_1);
    printf("Bitte geben Sie noch eine Zahl ein: \n");
    scanf("%lf", &zahl_2);  

    summe = zahl_1 + zahl_2;

    if ((int)summe == summe) {
        printf("Die Summe ist %.0lf\n", summe);
    } else{
       printf("Die Summe ist %.4lf\n", summe);
    } 
    return 0;
}