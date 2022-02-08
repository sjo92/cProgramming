#include <stdio.h>
#include <stdlib.h>
#include "crop_newline.c"

int test()
{
    char zeichenkette[100];
    char new[100];
    printf("Bitte geben Sie etwas ein: ");
    //scanf("%s", zeichenkette);
    fgets(zeichenkette, 100, stdin); //An Speicheradresse zeichenkette / Max. 100 Zeichen / nimmt new Line mit
    newline(zeichenkette);
    printf("Sie gaben ein: \"%s\"\n", zeichenkette);

    fputs("Normale Textausgabe\n", stdout);
    fputs("Fehlermeldung", stderr); // Für Fehlermeldung nützlich / Weiterleiten mit 2> abc.txt
    return EXIT_SUCCESS;
}

int test2()
{
    char zeichenkette[100];
    printf("Bitte geben Sie etwas ein: ");
    //scanf("%s", zeichenkette);
    fgets(zeichenkette, 100, stdin); //An Speicheradresse zeichenkette / Max. 100 Zeichen / nimmt new Line mit
    newline(zeichenkette);
    printf("Sie gaben ein: \"%s\"\n", zeichenkette);

    FILE *filehandler;
    /*
    filehandler = fopen("test.txt", "w"); //write a file named test.txt
    fputs(zeichenkette, filehandler); //Jedes Mal wird die Datei überschrieben.
    fclose(filehandler);
    */

    printf("Inhalt der Datei datei.c\n");
    filehandler = fopen("datei.c", "r"); // für lesen eine Datei offen.
    if (filehandler == NULL)
    {
        fputs("Datei datei.c nicht gefunden.\n", stderr);
    }
    else
    {
        while (fgets(zeichenkette, 100, filehandler) != NULL)
        {
            fputs(zeichenkette, stdout); //Eine Zeile mit 100 Zeichen
            /*
            fgets(zeichenkette, 100, filehandler);
            printf("%s", zeichenkette);*/
        }
        fclose(filehandler);
    }

    return EXIT_SUCCESS;
}

int test3()
{
    FILE *fp = fopen("datei.c", "r");
    char zeichen;
    long anzahl = 0;

    if (fp == NULL)
    {
        fputs("Datei datei.c nicht gefunden!\n", stderr);
    }
    else
    {
        do
        {
            zeichen = fgetc(fp);
            anzahl++;
        } while (zeichen != EOF); //End of File
    }
    printf("Die Datei beeinhaltet %ld Zeichen.\n", anzahl - 1);
    return EXIT_SUCCESS;
}

int main()
{
    int daten[100];
    int i;
    for (i = 0; i < 100; i++)
        daten[i] = 42 + i;

    FILE *datei = fopen("data.bin", "wb"); //write binary
    fwrite(daten, sizeof(int), sizeof(daten), datei);
    fclose(datei);
    for (i = 0; i < 100; i++)
        daten[i] = 0; /*
    datei = fopen("data.bin", "rb");
    fread(daten, sizeof(int), 100, datei);
    fclose(datei);*/
    for (i = 0; i < 100; i++)
    {

        printf("%d ", daten[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}