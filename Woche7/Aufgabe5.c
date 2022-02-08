#include <stdio.h>
#include <math.h>

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

/*Function pay_amount declaration */
void pay_amount(int *betrag_100, int *two_euro, int *one_euro, int *fifty_cent, int *twenty_cent, int *ten_cent, int *five_cent, int *two_cent, int *one_cent)
{
    *two_euro = (*betrag_100 / 200);
    *one_euro = ((*betrag_100 % 200) / 100);
    *fifty_cent = (((*betrag_100 % 200) % 100) / 50);
    *twenty_cent = ((((*betrag_100 % 200) % 100) % 50) / 20);
    *ten_cent = (((((*betrag_100 % 200) % 100) % 50) % 20) / 10);
    *five_cent = ((((((*betrag_100 % 200) % 100) % 50) % 20) % 10) / 5);
    *two_cent = (((((((*betrag_100 % 200) % 100) % 50) % 20) % 10) % 5) / 2);
    *one_cent = ((((((((*betrag_100 % 200) % 100) % 50) % 20) % 10) % 5) % 2) / 1);
}

int main()
{
    /* local variable definition of enter amount*/
    double betrag;
    int betrag_100, two_euro, one_euro, fifty_cent, twenty_cent, ten_cent, five_cent, two_cent, one_cent;
    printf("enter amount: ");
    scanf("%lf", &betrag);
    printf("\nChange for €%lf is:\n", betrag);
    betrag_100 = rounding(betrag);

    pay_amount(&betrag_100, &two_euro, &one_euro, &fifty_cent, &twenty_cent, &ten_cent, &five_cent, &two_cent, &one_cent);
    /* Calling pay_amount function to get smallest bills*/
    printf("%d x 2-Euro Muenze\n", two_euro);
    printf("%d x 1-Euro Muenze\n", one_euro);
    printf("%d x 50-Cent Muenze\n", fifty_cent);
    printf("%d x 20-Cent Muenze\n", twenty_cent);
    printf("%d x 10-Cent Muenze\n", ten_cent);
    printf("%d x 5-Cent Muenze\n", five_cent);
    printf("%d x 2-Cent Muenze\n", two_cent);
    printf("%d x 1-Cent Muenze\n", one_cent);
    return 0;
}
