#include <stdio.h>

int main()
{
    double gesamtbetrag;
    printf("Wie groß ist der Euro-Betrag, welche in möglichst wenig Münzen aufgeteilt werden soll?\n ");
    scanf("%lf", &gesamtbetrag);

    int eurobetrag = 0;
    int centbetrag = 0;

    eurobetrag = (int)gesamtbetrag;
    centbetrag = (int)((gesamtbetrag - eurobetrag + 0.0001) * 100);

    int e2 = 0;
    int e1 = 0;
    int c50 = 0;
    int c20 = 0;
    int c10 = 0;
    int c5 = 0;
    int c2 = 0;
    int c1 = 0;

    e2 = eurobetrag / 2;
    e1 = eurobetrag - (e2 * 2);

    printf("%d x 2-Euro-Muenze\n", e2);
    printf("%d x 1-Euro-Muenze\n", e1);

    c50 = centbetrag / 50;
    centbetrag = (centbetrag - (c50 * 50));
    c20 = centbetrag / 20;
    centbetrag = (centbetrag - (c20 * 20));
    c10 = centbetrag / 10;
    centbetrag = (centbetrag - (c10 * 10));
    c5 = centbetrag / 5;
    centbetrag = (centbetrag - (c5 * 5));
    c2 = centbetrag / 2;
    centbetrag = (centbetrag - (c2 * 2));
    c1 = centbetrag / 1;
    centbetrag = (centbetrag - (c1 * 1));

    printf("%d x 50-Cent-Muenze\n", c50);
    printf("%d x 20-Cent-Muenze\n", c20);
    printf("%d x 10-Cent-Muenze\n", c10);
    printf("%d x 5-Cent-Muenze\n", c5);
    printf("%d x 2-Cent-Muenze\n", c2);
    printf("%d x 1-Cent-Muenze\n", c1);
}