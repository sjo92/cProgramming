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

int rounding(double betrag)
{
    int round;
    int vergleich;
    //12.345 => 12.35 & 12.333 => 12.33
    vergleich = (int)(betrag * 1000) % 10;
    if (vergleich >= 5)
    {
        round = (int)((betrag + 0.005) * 100);
    }
    else
    {
        round = (int)(betrag * 100);
    }
    return round;
}

void get_coins(int betrag)
{
    int coins[8] = {200, 100, 50, 20, 10, 5, 2, 1};
    int i = 0;
    do
    {
        int coins_num = 0;
        //9.99€ => betrag 999 / coins[0] = 4
        //coins_num = 4
        //restbetrag => 999-800 = 199 = 999-(200*4)= (betrag- coins[0]*coins_num)
        if (betrag / coins[i] >= 1)
        {
            coins_num = betrag / coins[i];
        }
        else
        {
            coins_num = 0;
        }
        betrag = betrag - (coins[i] * coins_num);
        printf("%d X ", coins_num);
        if (i <= 1)
        {
            printf("%d-Euro-Muenze\n", coins[i] / 100);
        }
        else
        {
            printf("%d-Cent-Muenze\n", coins[i]);
        }
        i++;
    } while (coins[i] != '\0');
}

int main()
{
    double org_betrag;
    int rnd_betrag;
    org_betrag = betrag_eingabe();
    rnd_betrag = rounding(org_betrag);

    get_coins(rnd_betrag);

    return 0;
}

/*
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
*/