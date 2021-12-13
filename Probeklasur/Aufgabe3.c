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
    char text[200];
    printf("Bitte geben Sie etwas ein: \n");
    scanf("%s", text);

    char kopie[200];
    int index;
    for (index = 0; index < 200; index++)
    {
        kopie[index] = text[index];
        if (text[index] == '\0')
        {
            break;
        }
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
        }

        //Ausrufezeichen verfünffachen
        if (text[i] == '!')
        {
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
        }

        //Satzzeichen entfernen
        if (text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == ':' || text[i] == ';')
        {
            for (int k = i; k < length; k++)
            {

                text[k] = text[k + 1];
            }
            i--;
        }
    }
    printf("%s\n", text);
}