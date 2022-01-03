#include <stdio.h>

int main()
{
    int zahl;
    int copy = 0;
    int temp = 0;
    printf("Bitte geben Sie eine Zahl ein: ");
    scanf("%i", &zahl);

    do
    {

        temp = zahl / 10; // e,g. 1235 => 123
        temp = temp * 10; // 1230
        int num;
        num = zahl - temp; // 1235-1230 = 5
        copy = copy * 10 + num;
        zahl = temp / 10; // 123

    } while (temp != 0);

    printf("Umgedreht ist es: %i\n", copy);
}