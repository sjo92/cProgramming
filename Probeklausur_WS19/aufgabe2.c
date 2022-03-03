#include <stdio.h>
#include <stdlib.h>

int main()
{
    int grenze;
    int *output = malloc(sizeof(int) * grenze);
    int i = 1;
    int j = 0;

    /*Benutzer eine Obergrenze fragen und in der Variable "grenze" sichern*/
    printf("Geben Sie eine Obergrenze an: \n");
    scanf("%d", &grenze);

    /*Alle Zahlen kleiner gleich die gegebene Obergrenze außer die drei oder sieben teilen, in einer Array sichern*/
    for (i = 1; i <= grenze; i++)
    {
        if (i % 3 != 0 && i % 7 != 0)
        {
            output[j] = i;
            j++;
        }
    }

    /*unnötige speicherplatz reduzieren mit realloc */
    output = realloc(output, sizeof(int) * j);

    j = 0; // Index für die Zeichenkette wieder vorne setzen

    /*Die Zeichenkette ausgeben*/
    while (output[j] != '\0')
    {
        printf("%4d", output[j]);                    // Zahl in rechtbündig Format ausgeben
        if (j != 0 && output[j] - output[j - 1] > 2) // einen Zeilumbruch machen, falls die Differenz zwischen letzter zwei Zahlen größer gleich 3 ist
        {
            printf("\n");
        }
        j++; // Array Index hochsetzen
    }
    /*Der Speicherplatz für die bereits verwendete Zeichenkette freischalten*/
    free(output);

    return 0;
}