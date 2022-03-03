#include <stdio.h>

int main () {
    int a;
    int b;
    int c;
    printf("Bitte geben Sie die Laenge der Seite a ein: \n");
    scanf("%d", &a);

    printf("Bitte geben Sie die Laenge der Seite a ein: \n");
    scanf("%d", &b);

    printf("Bitte geben Sie die Laenge der Seite a ein: \n");
    scanf("%d", &c);

    /*
    Wir vergleichen die Ecken, um zu prüfen welche die längste ist. Dann wird berechnet, ob das Quadrat von der längsten Ecke gleich wie Summe von Quadrat von kleineren zwei Ecken ist.
    (Pythagoras: Sei a längste Eck a^2=b^2+c^2)

    Falls zwei oder drei Seiten gleich groß sind und die größste ist, dann hat das Dreieck keinen rechten winkel. (Beispiel a: 3, b: 5, c: 5)
    */
    if ((a>b && a>c)&&(a*a == b*b + c*c)) {
        printf ("a ist die Hypotenuse.\n");
    } else if ((b>a && b>c)&&(b*b == a*a + c*c)) {
        printf ("b ist die Hypotenuse.\n");
    } else if ((c>a && c>b)&&(c*c == b*b + a*a)) {
        printf ("c ist die Hypotenuse.\n");
    } else {
        printf("Das Dreieck hat keinen rechten Winkel.\n"); // 
    }

    return 0;

}