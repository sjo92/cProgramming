#include <stdio.h>

int main()
{
    char eingabe[100];
    int i;
    int j;
    int k;
    printf("Bitte geben Sie etwas ein: ");
    scanf("%s", eingabe);

    printf("Sie gaben %s ein.\n", eingabe);
    for (i = 0; eingabe[i] != '\0'; i++)
    {
        if (eingabe[i] >= 65 && eingabe[i] <= 91 || eingabe[i] >= 97 && eingabe[i] <= 124)
            eingabe[i] = eingabe[i] + 1;
    }
    eingabe[i] = '\0';
    printf("1. Änderung: \"%s\"\n",
           eingabe);

    for (j = 0; eingabe[j] != '\0'; j++)
    {
        if (eingabe[j] >= 65 && eingabe[j] <= 91)
        {
            eingabe[i] = eingabe[i] + 32;
        }
        else if (eingabe[i] >= 97 && eingabe[i] <= 124)
        {
            eingabe[i] = eingabe[i] - 32;
        }
    }
    eingabe[i] = '\0';
    printf("2. Änderung: \"%s\"\n", eingabe);

    printf("Buchstaben: \"");
    for (k = 0; eingabe[k] != '\0'; k++)
    {
        if (eingabe[k] >= 65 && eingabe[k] <= 91 || eingabe[k] >= 97 && eingabe[k] <= 124)
        {
            printf("%c", eingabe[k]);
        }
    }
    eingabe[k] = '\0';
    printf("\"\n");
    return 0;
}