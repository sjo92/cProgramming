#include <stdio.h>

/*
Das Programm zeigt alle Buchstaben des Alphabets sowohl in klein als auch Großbuchstaben auf Bildschirm
*/
int main() {
    int buchstabe = 'A'; //Der ASCII Wert von 'A' wird in den Variable Buchstabe zugeordnet
    int differenz = 'A' - 'a'; // Die Differenz in ASCII Wert zwischen 'A' und 'a' wird zugeordnet
    if (differenz <0) differenz = differenz * (-1); // Falls die Differenz minus ist, wird der Wert umgedreht

    for (buchstabe='A'; buchstabe<'Z'; buchstabe++) {
        printf("(%c, %c) ", buchstabe, buchstabe+differenz);
    }

    return 0;
}