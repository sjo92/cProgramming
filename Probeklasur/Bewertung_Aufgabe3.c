/*
Guten Tag Frau Czermin,

nach Ihrem Vorschlag konnte ich die 2. Aufgabe von der Probeklasur schaffen. Vielen Dank dafür.
Können Sie mir bitte ein Feedback zu der Aufgabe 2 geben? Gibt es eine bessere Lösung?

Bei der 3. Aufgabe habe ich folgende 2 Probleme.
(1) Bei der Eingabe Leerzeichen
Wenn ich Leerzeichen eingebe, wird der Rest von dem Satz nicht ausgegeben.
z.B, Eingabe: "Hallo Welt!" / Ausgabe: "Hallo"

(2) Bei der Verfünffachung der Ausrufezeichen
Ich bekomme ab 2. Ausrufezeichen immer 6 anstatt 5 Ausrufezeichen.
Eingabe: "Hallo!Hallowelt!HalloWelt!"
Ausgabe: hallo!!!!!Hallowelt!!!!!!hallowelt!!!!!!" (5 / 6 / 6 )

Können Sie mir bitte sagen, wie ich den Fehler beheben kann?

Vielen Dank für Ihre Zeit.

Mit freundlichen Grüßen
Seulgi Jo
*/

#include <stdio.h>
#include "../Woche8/readtext.c"


int main()
{
//    char text[200];
    printf("Bitte geben Sie etwas ein: \n");
// scanf() liest nur bis zum 1. Leerzeichen ein, ausserdem verhindert scanf() nicht, dass mehr Zeichen eingelesen werden, als Speicherplatz reserviert wurde.
// Deshalb wollen wir zukünftig scanf() nicht mehr zum Einlesen von Zeichenketten verwenden. 
//    scanf("%s", text);
// Der Text wird mit readtext() eingelesen, der benötigte Speicherplatz wird dynamisch zur Laufzeit reserviert.  

    char *text=readtext();
// Wir benötigen keine Kopie, weil die veraenderte Zeichenkette nur ausgegeben, nicht gespeichert, werden muss.    

    
    int index;
/*    for (index = 0; index < 200; index++)
    {
        kopie[index] = text[index];
        if (text[index] == '\0')
        {
            break;
        }
    }*/
     for (index = 0; text[index]!='\0'; index++){
     }
     
    int length = index;
    int i;
    int index2;
    int ausrufezeichen = 0;

    for (i = 0; i < length; i++)
    {
        //Umwandeln Großbuchstaben in Kleinbuchstaben
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = text[i] + 32;
            printf("%c",text[i]);
        }

        //Ausrufezeichen verfünffachen
        else if (text[i] == '!'){
        
            for (index2=0;index2<5;index2++){
                printf("%c",'!');
            
            }
        }
/*        {
         index2 = i;
            length = length + 5;
            text[i + 1] = '!';
            text[i + 2] = '!';
            text[i + 3] = '!';
            text[i + 4] = '!';
            for (int j = index2; j < length; j++)
            {
                if (ausrufezeichen >= 1) //Wenn Ausrufezeichen bereits vorgekommen sind, wird die Index von der originalen Zeichenkette entsprechend abgezogen.
                {
                    text[j + 5] = kopie[index2 - (5 * ausrufezeichen) + 1];
                }
                else
                {
                    text[j + 5] = kopie[index2 + 1];
                }
                index2++;
            }
            i = i + 5;
            ausrufezeichen++;
        }*/

        //Satzzeichen entfernen
      else  if (!(text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == ':' || text[i] == ';' ||text[i] == '"'  ))
        {
            printf("%c",text[i]);
        }
 /*       {
            for (int k = i; k < length; k++)
            {

                text[k] = text[k + 1];
            }
            i--;
        }*/
    }
    printf("\n");
//    printf("%s\n", text);
 //mit malloc() und realloc() reservierten Speicher freigeben
    free(text);
}
