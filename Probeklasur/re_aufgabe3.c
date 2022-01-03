
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

void checkLetter(char input)
{

    if (input > 64 && input < 91) //Großbuchstaben in Kleinbuchstaben umwandeln
    {
        input = input + 32;
        printf("%c", input);
    }
    else
    {
        printf("%c", input);
    }
}

void checkCharacter(char input)
{
    if (input == '!') //Ausrufezeichen verfünffacht
    {
        int k;
        for (k = 0; k < 5; k++)
        {
            printf("%c", input);
        }
    }
    else if (!(input == '.' || input == ',' || input == '?' || input == ':' || input == ';' || input == '"' || input == '!')) //Nur noch wenn keine Satzzeichen ist, dann ausgeben
    {
        printf("%c", input);
    }
}

void getSpelling(char *text, int i, int distanz)
{
    //Wörter größer 5 Buchstaben
    if (distanz > 5)
    {
        int j;
        for (j = distanz; j > 0; j--)
        { //Wenn das Zeichen kein Vokale ist dann weitere if Fragen
            if (!(text[i - j] == 'A' || text[i - j] == 'a' || text[i - j] == 'E' || text[i - j] == 'e' || text[i - j] == 'I' || text[i - j] == 'i' || text[i - j] == 'O' || text[i - j] == 'o' || text[i - j] == 'U' || text[i - j] == 'u'))
            {
                checkLetter(text[i - j]);
            }
        }
    }
    // Wörter kleiner als 5 Buchstaben. Die gleiche If Fragen sind gestellt
    else if (distanz >= 1)
    {
        int j;
        for (j = distanz; j > 0; j--)
        {
            checkLetter(text[i - j]);
        }
    }
    // einzelne Eingabe die kein Buchstaben ist
    else
    {
        checkCharacter(text[i]);
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
    int distanz = 0;

    while (text[i] != '\0')
    {
        while ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 125))
        {
            distanz++;
            i++;
        }
        if (distanz != 0)
        {
            getSpelling(text, i, distanz);
            distanz = 0;
            i = i - 1;
        }
        else
        {
            getSpelling(text, i, distanz);
        }
        i++;
    }
    printf("\n");
}