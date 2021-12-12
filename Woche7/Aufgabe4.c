#include <stdio.h>
#include <math.h>

double betrag_eingabe()
{
    double betrag;
    printf("Wie groß ist der Euro-Betrag, welcher in moeglichst wenig Muenzen aufgeteilt werden soll? \n");
    scanf("%lf", &betrag);
    printf("Betrag ist: %lf\n", betrag);
    return betrag;
}

double rounding(double betrag)
{
    double round;
    double vergleich;
    vergleich = betrag * 100 - (int)(betrag * 100);
    if (vergleich >= 0.5)
    {
        round = betrag + 0.005;
    }
    else
    {
        round = betrag + 0.0001;
    }
    printf("Vergleich ist: %lf\n", vergleich);
    printf("Betrag ist: %lf\n", round);
    /* 
    round = (int)(betrag * 100) + 0.5;
    round = round / 100;
    printf("Betrag ist: %lf\n", round);
    */
    return round;
}

int find_centbetrag(double betrag)
{
    int cent;
    int euro;
    euro = (int)betrag;
    cent = (betrag - euro) * 100;
    printf("cent betrag ist: %d\n", cent);
    return cent;
}
void euro_rechnen(int euro_betrag)
{
    int euro2 = 0;
    int euro1 = 0;
    int quotient;
    printf("euro betrag, %d \n", euro_betrag);
    euro2 = euro_betrag / 2;
    if (euro_betrag - euro2 * 2 == 1)
    {
        euro1++;
    }
    printf("%d x 2-Euro Muenze\n", euro2);
    printf("%d x 1-Euro Muenze\n", euro1);
}
void cent_rechnen(int cent_betrag)
{
    int cent50 = 0;
    int cent20 = 0;
    int cent10 = 0;
    int cent5 = 0;
    int cent2 = 0;
    int cent1 = 0;

    if (cent_betrag >= 50)
    {
        cent_betrag = cent_betrag - 50;
        cent50++;
    }
    if (cent_betrag >= 20)
    {
        cent20 = cent_betrag / 20;
        cent_betrag = cent_betrag - (cent20 * 20);
    }
    if (cent_betrag >= 10)
    {
        cent10 = cent_betrag / 10;
        cent_betrag = cent_betrag - (cent10 * 10);
    }
    if (cent_betrag >= 5)
    {
        cent5 = cent_betrag / 5;
        cent_betrag = cent_betrag - (cent5 * 5);
    }
    if (cent_betrag >= 2)
    {
        cent2 = cent_betrag / 2;
        cent_betrag = cent_betrag - (cent2 * 2);
    }
    if (cent_betrag >= 1)
    {
        cent1 = cent_betrag / 1;
        cent_betrag = cent_betrag - (cent1 * 1);
    }

    printf("%d x 50-Cent Muenze\n", cent50);
    printf("%d x 20-Cent Muenze\n", cent20);
    printf("%d x 10-Cent Muenze\n", cent10);
    printf("%d x 5-Cent Muenze\n", cent5);
    printf("%d x 2-Cent Muenze\n", cent2);
    printf("%d x 1-Cent Muenze\n", cent1);
    printf("%d x Rest Cent Muenze\n", cent_betrag);
}

int main()
{
    double org_betrag;
    double rnd_betrag;
    int euro_betrag;
    int cent_betrag;
    org_betrag = betrag_eingabe();
    rnd_betrag = rounding(org_betrag);
    cent_betrag = find_centbetrag(rnd_betrag);
    euro_betrag = (int)rnd_betrag;

    euro_rechnen(euro_betrag);
    cent_rechnen(cent_betrag);

    return 0;
}