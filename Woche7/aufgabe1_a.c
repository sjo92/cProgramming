#include <stdio.h>

void eingabeaufforderung_info()
{
    printf("Es ist nun eine Benutzereingabe erforderlich. \n");
}

void eingabeaufforderung_zk()
{
    eingabeaufforderung_info();
    printf("Bitte geben Sie eine Zeichenkette ein: ");
}
void eingabeaufforderung_int()
{
    eingabeaufforderung_info();
    printf("Bitte geben Sie eine ganze Zahl ein: ");
}
void ausgabe_int(int input)
{
    printf("Die Zahl lautet: %d\n", input);
}

void ausgabe_zk(char *input)
{
    printf("Die Zeichenkette lautet: \"%s\"\n", input);
}


int main()
{
    int zahl;
    char kette[255];
    char c;
    int i = 0;

    /* Zahleingabe aufgefordert. Bis eine positive Zahl eingegeben wird, wird die Aufforderung wiederholt */
    do
    {
        eingabeaufforderung_int();
        scanf("%d", &zahl);
    } while (zahl < 0);
    getchar();

    /* Zeichenketteeingabe aufgefordert. Leere Zeichenkette werden nicht akzeptiert und weitere Eingabe werden gefragt, bis der Benutzer etwas eingegeben hat */
    do{
        eingabeaufforderung_zk();
        c=getchar();
        kette[0]=c;
    } while(kette[0]=='\n'); //Das erste Zeichen von der Zeichenkette wurde bereits gespeichert und wird weiter verwendet, solange dies kein leeres Zeichen ist.
    
    /*Schleife für die restliche Eingabe von der Zeichenkette*/
    do {
        i++;
        c=getchar();
        kette[i]=c;
    }while(kette[i]!='\n');
    kette[i]='\0';

    ausgabe_int(zahl);
    ausgabe_zk(kette);
    return 0;
}