#include <stdio.h>

int main()
{
    int x;
    x = -12;
    unsigned int anzahl;
    anzahl = 5;

    float kontostand;
    kontostand = 543.21;

    printf("Der Inhalt der Variable x ist %d\n", x);
    printf("Der Inhalt der Variable Anzahl ist %d\n", anzahl);
    printf("Der Inhalt der Variable Kontostand ist %.2f\n", kontostand);

    /*aufgabe a
    a) Addieren Sie nun innerhalb des Programms die beiden Variablen x und anzahl und geben Sie das Ergebnis ebenfalls mit einem geeigneten Kommentar auf dem Bildschirm aus.

    */
    printf("x+anzahl ist: %d\n", x + anzahl);

    /*aufgabe b
    b) Addieren Sie anschließend zu diesem Ergebnis noch den Inhalt der Variablen konto- stand hinzu und geben Sie dies als Fließkommazahl auf dem Bildschirm aus.
    */
    printf("x+anzahl+kontostand ist: %.2f\n", (float)x + anzahl + kontostand);

    /*
    c) Geben Sie die Adressen im Arbeitsspeicher für die Variablen x, anzahl und kontostand in zwei verschiedenen Formaten aus:
    1. VerwendenSiebeiderFormatangabeeinmaleinUmwandlungszeichenfürganze Zahlen und
    2. einmal das Umwandlungszeichen für Pointer.

    */
    printf("Die Adresse im Arbeitsspeicher für x lautet: %p\n", &x);
    printf("Die Adresse im Arbeitsspeicher für x lautet: %p\n", &anzahl);
    printf("Die Adresse im Arbeitsspeicher für x lautet: %p\n", &kontostand);
}