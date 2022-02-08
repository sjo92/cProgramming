#include <stdio.h>
unsigned add(unsigned x, unsigned y)
{

    unsigned sum = 0;
    int digit = 0;
    int ten = 1;
    int first = 0;
    while (x - ((x / 10) * 10) > 0 || y - ((y / 10) * 10) > 0|| x / 10>0||y / 10>0 )
    {
        unsigned tempx = 0;
        unsigned tempy = 0;
        if (x - ((x / 10) * 10) >= 0)
        {
            tempx = x - ((x / 10) * 10);
            x = x / 10;
        }
        else
            tempx = 0;
        if (y - ((y / 10) * 10) >= 0)
        {
            tempy = y - ((y / 10) * 10);
            y = y / 10;
        }
        else
            tempy = 0;
        if (first == 0)
        {
            sum = tempx + tempy;
            first++;
            if (tempx + tempy >= 10)
            {
                digit = digit + 2;
            }
            else
            {
                digit = digit + 1;
            }
        }
        else
        {
            ten = 1;
            for (int i = 0; i < digit; i++)
            {
                ten = ten * 10;
            }
            sum = sum + (tempx + tempy) * ten;

            if (tempx + tempy >= 10)
            {
                digit = digit + 2;
            }
            else
            {
                digit = digit + 1;
            }
        }
    }
    return sum;
}

unsigned add_2(unsigned x, unsigned y)
{
    unsigned sum = 0;
    int two = -1;
    while (x - ((x / 10) * 10) > 0 || y - ((y / 10) * 10) > 0)
    {
        unsigned tempx = 0;
        unsigned tempy = 0;
        if (x - ((x / 10) * 10) > 0)
        {
            tempx = x - ((x / 10) * 10);
            x = x / 10;
        }
        if (y - ((y / 10) * 10) > 0)
        {
            tempy = y - ((y / 10) * 10);
            y = y / 10;
        }
        if (two == -1)
        {
            sum = tempx + tempy;
        }
        if (tempx + tempy >= 10)
        {
            if (two == 0)
            {
                sum = sum + (tempx + tempy) * 100;
                printf("temp sum is: %u\n", sum);
            }
            else if (two == 1)
            {
                sum = sum + (tempx + tempy) * 10;
                printf("temp sum is: %u\n", sum);
            }
            two = 0;
            printf("two ist: %d", two);
        }
        else
        {
            if (two == 0)
            {
                sum = sum + (tempx + tempy) * 100;
                printf("temp sum is: %u\n", sum);
            }
            else if (two == 1)
            {
                sum = sum + (tempx + tempy) * 10;
                printf("temp sum is: %u\n", sum);
            }
            two = 1;
            printf("two ist: %d", two);
        }
    }
    return sum;
}

int main()
{
    unsigned x;
    unsigned y;
    unsigned sum;
    printf("Bitte geben Sie eine Zahl ein: ");
    scanf("%u", &x);
    printf("Bitte geben Sie eine andere Zahl ein: ");
    scanf("%u", &y);
    sum = add(x, y);

    printf("Sum is: %u\n", sum);
    return 0;
}