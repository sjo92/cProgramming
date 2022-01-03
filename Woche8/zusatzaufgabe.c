#include <stdio.h>

void firstDigit(long x)
{
    switch (x)
    {
    case 1:
        printf("ein");
        break;
    case 2:
        printf("zwei");
        break;
    case 3:
        printf("drei");
        break;
    case 4:
        printf("vier");
        break;
    case 5:
        printf("fünf");
        break;
    case 6:
        printf("sechs");
        break;
    case 7:
        printf("sieben");
        break;
    case 8:
        printf("acht");
        break;
    case 9:
        printf("neun");
        break;
    }
}

void secondDigit(long x)
{
    switch (x)
    {
    case 20:
        printf("zwanzig");
        break;
    case 30:
        printf("dreißig");
        break;
    case 40:
        printf("vierzig");
        break;
    case 50:
        printf("fünfzig");
        break;
    case 60:
        printf("sechszig");
        break;
    case 70:
        printf("siebenzig");
        break;
    case 80:
        printf("achtzig");
        break;
    case 90:
        printf("neunzig");
        break;
    }
}

void zehn_bis_neunzehn(long x)
{
    long temp;
    if (x < 13)
    {
        switch (x)
        {
        case 10:
            printf("zehn");
            break;
        case 11:
            printf("elf");
            break;
        case 12:
            printf("zwölf");
            break;
        }
    }
    else
    {
        temp = x % 10;
        firstDigit(temp);
        printf("zehn");
    }
}

long getLen(long x)
{
    long len = 1;
    while (x > 9999)
    {
        x /= 10000;
        len += 4;
    }
    while (x > 99)
    {
        x /= 100;
        len += 2;
    }
    if (x > 9)
        len++;
    return len;
}

void getTwoDigits(long x, long length)
{
    long temp;
    if (length == 1)
    {
        if (x == 1)
        {
            printf("eins");
        }
        else
        {
            firstDigit(x);
        }
    }
    if (length == 2)
    {
        if (x >= 20)
        {
            temp = x % 10;
            firstDigit(temp);
            printf("und");
            x = x - temp;
            secondDigit(x);
        }
        else if (x >= 10)
        {
            zehn_bis_neunzehn(x);
        }
        else
        {
            if (x == 1)
            {
                printf("eins");
            }
            else
            {
                firstDigit(x);
            }
        }
    }
}

void getThreeDigits(long x, long length)
{
    long i;
    long mod = 1;
    long temp;
    for (i = 1; i < length; i++)
    {
        mod = mod * 10;
    }

    if (length == 3)
    { //x= 234, mod=100, temp=2
        if (x >= 1 && x <= 99)
        {
            getTwoDigits(x, length - 1);
        }
        else
        {
            temp = x / 100;
            if (temp == 1)
            {
                printf("einhundert");
            }
            else if (temp > 1)
            {
                firstDigit(temp);
                printf("hundert");
            }
            x = x % 100;
            getTwoDigits(x, length - 1);
        }
    }
    else
    {
        getTwoDigits(x, length);
    }
}

void getNineDigits(long x, long length)
{ //1234
    long temp;
    long mod = 1;
    long i;
    for (i = 1; i < length; i++)
    {
        mod = mod * 10;
    }
    printf("mod ist %ld", mod);
    while (length > 0)
    {
        if (length > 9 && length < 13)
        { //temp = 234, x=234567,
            temp = x / 1000000000;
            if (temp == 1)
            {
                printf("einemillionarde");
            }
            else if (temp > 1)
            {
                getThreeDigits(temp, 3);
                printf("milliarden");
            }
            x = x % 1000000000;
            length = 9;
        }
        else if (length > 6 && length < 10)
        { //temp = 234, x=234567,
            temp = x / 1000000;
            if (temp == 1)
            {
                printf("einemillion");
            }
            else if (temp > 1)
            {
                getThreeDigits(temp, 3);
                printf("millionen");
            }
            x = x % 1000000;
            length = 6;
        } //234567: zweihundertvierunddreißigtausend fünfhunderutsiebenundsechzig
        else if (length > 3 && length < 7)
        { //temp = 234, x=234567,
            temp = x / 1000;
            if (temp == 1)
            {
                printf("eintausend");
            }
            else if (temp > 1)
            {
                getThreeDigits(temp, 3);
                printf("tausend");
            }
            x = x % 1000;
            length = 3;
        }
        else
        {
            getThreeDigits(x, length);
            length = 0;
        }
    }
}

int main()
{
    long zahl;
    long length;

    printf("Bitte geben Sie eine Zahl ein: ");
    scanf("%ld", &zahl);

    length = getLen(zahl);
    printf("Die Zahl ist: %ld mit der Länge: %ld\n", zahl, length);
    getNineDigits(zahl, length);
    printf("\n");

    return 0;
}