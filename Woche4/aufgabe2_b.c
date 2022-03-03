#include <stdio.h>

/*
Die Zahl prüfen und eine passende Rückgabe geben.
Ist die Summe ganze Zahl, wird 0 zurückgegeben.
Hat die Summe eine Kommastelle, wird 1 zurückgegeben.
Hat die Summe zwei Kommastellen, wird 2 zurückgegeben.
Hat die Summe mehr als zwei Kommastellen, wird 3 zurückgegeben.
*/
int vergleich (double summe) {
    int zahl;
    if ((int)summe == summe) {return 0;} //Ist die Summe ganze Zahl, wird 0 zurückgegeben.

    // Wir betrachten die Summe * 1000, um zu sehen, ob die Modulorechnung von der Zahl einen Rest hat.
    // Bsp: (1) eine Nacahkommastelle 12.3 => 12300 (Modulo 100 ist null)
    // (2) zwei Nachkommastellen 12.34 => 12340 (Modulo 100 ist 40, aber modulo 10 ist null)
    // (3) Drei Nachkommastellen 12.345 => 12345 (Modullo 100 ist 45, Modulo 10 ist 5: Also bei beiden Modulorechnungen nicht null) 
    zahl = (int) (summe * 1000);

    if (zahl%100 == 0) {
        return 1;
    } else if (zahl%10 == 0) {
        return 2;
    } else {return 3;}

}

int main() {
    double eingabe_1;
    double eingabe_2;
    double summe;
    int index;

    printf("Bitte geben Sie eine Zahl ein: \n");
    scanf("%lf", &eingabe_1);
    printf("Bitte geben Sie noch eine Zahl ein: \n");
    scanf("%lf", &eingabe_2);
    summe = eingabe_1 + eingabe_2;
    index = vergleich(summe); // Rückgabewert 0: 0 Nachkommastelle / 1: 1 Nachkommastelle / 2: 2 Nachkammstelle / 3: mehr als 2 Nachkommastelle
    
    if (index ==0) {
        printf("Die Summe ist :%.0lf\n", summe);
    } else if (index ==1) {
        printf("Die Summe ist : %.1lf\n", summe);
    } else if (index ==2) {
        printf("Die Summe ist : %.2lf\n", summe);
    } else {
        printf("Die Summe ist :%.3lf\n", summe);
    }
    
}