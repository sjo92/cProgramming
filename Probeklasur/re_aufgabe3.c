/*
Guten Tag Frau Czermin,
vielen Dank für das Feedback von der letzten Aufgabe.
Ich habe dadurch sehr viel gelernt.
Ich möchte gerne von Ihenn ein Feedback zu der Zusatzaufgabe von der 3. Aufgabe von der Probeklasur bekommen.

Um die Länge eines Wortes zu rechnen, habe ich eine Variable für ein Leerzeichen erstellt.
Die Länge eines Wortes wurde dann mit der Distanz von dem letzten Leerzeichen gerechnet. 

Da das letzte Wort von dem gesamten Text meistens kein Leerzeichen hat, habe ich dafür nochmal ein "else If" statement gemacht.
Dadurch musste ich insgesamt 4 Fallunterscheidungen machen: 
(1) Distanz länger als 6 
(2) Distanz kleiner gleich 6 
(3) Das letzte Wort mit der Distanz länger als 6 
(4) Das letzte Wort mit der Distanz kleiner gleich 6

Das Programm läuft soweit gut aber ich bin nicht damit zufrieden. 
Ich möchte sehr gerne wissen, wie man das Programm noch sauberer/schlauer bauen könnte.

Können Sie bitte den folgenden Code überprüfen und mir ein Feedback geben?
Vielen Dank im Voraus.

Ich wünsche Ihnen wunderschöne Weihnachten und auch einen guten Rutsch ins Jahr 2022!

Beste Grüße
Seulgi Jo

*/

#include <stdio.h>
#include <stdlib.h>

char *readtext()
{
    int puffergroesse = 10;
    char *puffer = malloc(puffergroesse);
    int eingabepos = 0;
    char eingegebenes_zeichen;
    do
    {
        eingegebenes_zeichen = getchar();
        if (eingegebenes_zeichen != '\n')
        {
            puffer[eingabepos] = eingegebenes_zeichen;
            eingabepos++;
            if (eingabepos == puffergroesse)
            {
                puffergroesse = puffergroesse + 10;
                puffer = realloc(puffer, puffergroesse);
            }
        }
    } while (eingegebenes_zeichen != '\n');
    puffer[eingabepos] = '\0';
    puffer = realloc(puffer, eingabepos + 1);
    return puffer;
}

void checkCharacter(char input)
{
    if (input > 64 && input < 91) //Großbuchstaben in Kleinbuchstaben umwandeln
    {
        input = input + 32;
        printf("%c", input);
    }
    else if (input == '!') //Ausrufezeichen verfünffacht
    {
        int k;
        for (k = 0; k < 5; k++)
        {
            printf("%c", input);
        }
    }
    else if (!(input == '.' || input == ',' || input == '?' || input == ':' || input == ';' || input == '"')) //Nur noch wenn keine Satzzeichen ist, dann ausgeben
    {
        printf("%c", input);
    }
}

int main()
{
    char *text;
    int i;

    int length;
    printf("Bitte geben Sie etwas ein: ");
    text = readtext();
    for (i = 0; text[i] != '\0'; i++)
    {
    }
    length = i;
    i = 0;
    int leerzeichen = 0;
    int distanz = 0;

    for (i = 0; i < length; i++)
    {
        //Leerzeichen prüfen
        if (text[i] == ' ')
        {
            distanz = i - leerzeichen;
            // Wörter mehr als 5 Buchstaben
            if (distanz > 6)
            {
                int j;
                for (j = distanz; j > 0; j--)
                { //Wenn das Zeichen kein Vokale ist dann weitere if Fragen
                    if (!(text[i - j] == 'A' || text[i - j] == 'a' || text[i - j] == 'E' || text[i - j] == 'e' || text[i - j] == 'I' || text[i - j] == 'i' || text[i - j] == 'O' || text[i - j] == 'o' || text[i - j] == 'U' || text[i - j] == 'u'))
                    {
                        checkCharacter(text[i - j]);
                    }
                    leerzeichen = i;
                }
            }
            // Wörter kleiner als 5 Buchstaben. Die gleiche If Fragen sind gestellt
            else
            {
                int j;
                for (j = distanz; j > 0; j--)
                {
                    checkCharacter(text[i - j]);
                    leerzeichen = i;
                }
            }
        }
        //Für das letzte Wort noch mal das gleiche Frage, da das letzte Wort kein Leerzeichen am Ende hat.
        else if (i == length - 1)
        {
            distanz = i - leerzeichen;
            if (distanz > 6)
            {
                int j;
                for (j = distanz; j >= 0; j--)
                {
                    if (!(text[i - j] == 'A' || text[i - j] == 'a' || text[i - j] == 'E' || text[i - j] == 'e' || text[i - j] == 'I' || text[i - j] == 'i' || text[i - j] == 'O' || text[i - j] == 'o' || text[i - j] == 'U' || text[i - j] == 'u'))
                    {
                        checkCharacter(text[i - j]);
                    }

                    leerzeichen = i;
                }
            }
            else
            {
                int j;
                for (j = distanz; j >= 0; j--)
                {
                    checkCharacter(text[i - j]);
                    leerzeichen = i;
                }
            }
        }
    }
    printf("\n");
}