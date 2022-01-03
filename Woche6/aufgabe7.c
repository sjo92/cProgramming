#include <stdio.h>

int main()
{
    char num[10];
    int zahl = 0;
    int i;

    printf("Bitte geben Sie etwas ein: ");
    scanf("%s", num);

    for (i = 0; num[i] != '\0'; i++)
    {

        zahl = 10 * zahl + num[i] - '0';

        printf("Die num ist: %c\n", num[i]);
        printf("Die num ist: %d\n", num[i]);
    }
    printf("Die Zahl ist: %d\n", zahl);
}