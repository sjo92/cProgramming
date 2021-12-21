#include <stdio.h>

int solution(int number)
{
    if (number < 0)
    {
        return 0;
    }
    number = number - 1;
    int teiler3 = number / 3;

    int teiler5 = number / 5;
    int index;
    int index2;
    int summe = 0;

    printf("teiler 3: %d\n", teiler3);
    printf("teiler 5: %d\n", teiler5);
    for (index = 0; index < teiler3; index++)
    {
        summe = summe + 3 * (index + 1);

        printf("3 Summe ist: %d\n", summe);
    }

    for (index2 = 0; index2 < teiler5; index2++)
    {
        summe = summe + 5 * (index2 + 1);

        printf("5 Summe ist: %d\n", summe);
    }

    if (number / 15 > 1)
    {
        for (index = 0; index < number / 15; index++)
        {
            summe = summe - 15 * (index + 1);

            printf("15 Summe ist: %d\n", summe);
        }
    }
    printf("Summe ist: %d\n", summe);
    // code here
    return summe;
}

int solution2(int number)
{
    if (number < 0)
    {
        return 0;
    }
    int i;
    int summe;
    for (i = 0; i < number; i++)
    {
        if (i % 3 == 0 && i % 5 != 0)
        {
            summe = summe + i;
            printf("3 Teiler: %d\n", summe);
        }
        else if (i % 5 == 0)
        {
            summe = summe + i;
            printf("5 Teiler: %d\n", summe);
        }
    }
    return summe;
}
int main()
{
    int result = 10;
    int summe = solution2(20);
    return 0;
}