#include <stdio.h>

void einlesen(int *zahl)
{
    int i;
    int temp;
    for (i = 0; i < 10; i++)
    {
        printf("Bitte geben Sie %d. Zahl ein: \n", i + 1);
        scanf("%d", &temp);
        zahl[i] = temp;
    }
}
void ausgabe(int zahl[10], int max, int min, int avr)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Die %d. Zahl ist %d.\n", i + 1, zahl[i]);
    }
    printf("The max is : %d\n", max);
    printf("The min is : %d\n", min);
    printf("The average is : %d\n", avr);
}
int max(int zahl[10])
{
    int max = zahl[0];
    int i;
    for (i = 0; i < 10; i++)
    {
        if (max < zahl[i])
        {
            max = zahl[i];
        }
    }
    return max;
}

int min(int zahl[10])
{
    int min = zahl[0];
    int i;
    for (i = 0; i < 10; i++)
    {
        if (min > zahl[i])
        {
            min = zahl[i];
        }
    }
    return min;
}

int average(int zahl[10])
{
    int summe;
    int i;
    for (i = 0; i < 10; i++)
    {
        summe = summe + zahl[i];
    }
    return summe / i;
}

int main()
{
    int zahl[10];
    int max_result;
    int min_result;
    int avr_result;
    einlesen(zahl);

    max_result = max(zahl);
    min_result = min(zahl);
    avr_result = average(zahl);
    ausgabe(zahl, max_result, min_result, avr_result);
    return 0;
}