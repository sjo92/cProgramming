#include <stdio.h>

int main()
{
    char zahl[100];
    int i;
    int index;
    int first;
    int length;
    //Benutzer auffordern eine Zahl einzugeben
    printf("Bitte geben Sie eine Zahl ein: ");
    //Eine Zahl einlesen
    scanf("%s", zahl);
    for (i = 0; zahl[i] != '\0'; i++)
    {
    }
    length = i;
    i = 0;
    while (i < length - 2)
    {
        for (index = 1; index < length - 1; index++)
        {
            if (index == 1)
            {
                first = zahl[index];
                zahl[index] = zahl[index + 1];
            }
            else if (index == length - 2)
            {
                zahl[index] = first;
            }
            else
            {
                zahl[index] = zahl[index + 1];
            }
        }
        printf("Zahl ist %s\n", zahl);
        i++;
    }
}