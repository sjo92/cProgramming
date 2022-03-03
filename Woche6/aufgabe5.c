#include <stdio.h>

int main()
{
    char eingabe[100];
    int i;
    int j;
    int k;
    printf("Bitte geben Sie etwas ein: ");
    scanf("%s", eingabe); //Benutzer Eingabe
    printf("Sie gaben %s ein.\n", eingabe); //Eingabe ausgeben

    /*
    1. Änderung: Buchstaben von der Zeichenkette werden in ASCII Wert um 1 erhöht. 
    */
    for (i = 0; eingabe[i] != '\0'; i++)
    {
        if (eingabe[i] >= 'A' && eingabe[i] <= 'Z'|| eingabe[i] >= 'a' && eingabe[i] <= 'z')
            eingabe[i] = eingabe[i] + 1;
    }
    printf("1. Änderung: \"%s\"\n", eingabe);


    /*
    2. Änderung: Alle Großbuchstaben werden in klein umgewandelt. Alle Kleinbuchstaben werden in groß umgewandelt. 
    */
    for (i = 0; eingabe[i] != '\0'; i++)
    {
        if (eingabe[i] >= 'A' && eingabe[i] <= 'Z'){    
                eingabe[i] = eingabe[i] +32;
        }else if(eingabe[i] >= 'a' && eingabe[i] <= 'z') {eingabe[i] = eingabe[i] -32;}
    }
    printf("2. Änderung: \"%s\"\n", eingabe);

    /*
    Nur Buchstaben werden ausgegeben
    */
    printf("Buchstaben: \"");
    for (i = 0; eingabe[i] != '\0'; i++)
    {
        if (eingabe[i] >= 'A' && eingabe[i] <= 'Z'|| eingabe[i] >= 'a' && eingabe[i] <= 'z') printf("%c", eingabe[i]);
    }
    printf("\"\n");

    return 0;
}