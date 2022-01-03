#include <stdio.h>
#define SPEICHER 12

int main()
{
    char eingabe[SPEICHER];
    int i;
    int j;
    for (i = 0; i < SPEICHER; i++)
    {
        int a;
        printf("Bitte geben Sie etwas ein: ");
        scanf("%d", &a);
        eingabe[i] = a;
    }

    for (j = 0; j < SPEICHER; j++)
    {
        printf("Der %d. ASCII-Wert lautet %d und ist das Zeichen %c\n", j + 1, eingabe[j], eingabe[j]);
    }
    j = 0;
    /*
    for (j = 0; j < SPEICHER; j++)
    {
        printf("%c", eingabe[j]);
    }
    */

    printf("%s", eingabe);
    printf("\n");
    return 0;
}