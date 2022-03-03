#include <stdio.h>

int main()
{
    char x[] = "234\0";

    x[1] = x[1] * x[2]; //x[1]= '3'*'4'
    printf("%d\n", 2652 % 128); //x[1]=='3' = 51 / x[2]=='4' = 52 und 51*52=2652 2652 wird in char als 92 umgerechnet (ASCII 92 = \)
    printf("%s\n", x); //Das Ergebnis: 2\4 (ASCII 92 = \)


    char y[] = "234\012"; //Die Zeichen nach \0 werden nicht ausgegeben. Trotzdem werden die Zeichen \ und 0 wegen die nachfolgenden Zahlen als getrennte zwei Zeichen in der Zeichenkette eingelesen
    y[1] = y[1] * y[2] + y[3];  //x[1]=='3' = 51, x[2]=='4' = 52, x[3]=='\' = 92 und 51*52+92 %128 184 wird in char als 56 umgerechnet (ASCII 56 = f)
    printf("%d\n", (51*52+92) %128);
    printf("%s", y);
    return 0;
}