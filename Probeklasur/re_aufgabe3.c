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

int main()
{
    char *text;
    int i;
    int k;
    int length;
    printf("Bitte geben Sie etwas ein: ");
    text = readtext();
    for (i = 0; text[i] != '\0'; i++)
    {
    }
    length = i;
    i = 0;
    int j;
    int leerzeichen = 0;
    int distanz = 0;
    //Großbuchstaben klein umwandeln
    for (i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            distanz = i - leerzeichen;
            if (distanz > 5)
            {
                for (j = distanz; j > 0; j--)
                {
                    if (!(text[i - j] == 'A' || text[i - j] == 'a' || text[i - j] == 'E' || text[i - j] == 'e' || text[i - j] == 'I' || text[i - j] == 'i' || text[i - j] == 'O' || text[i - j] == 'o' || text[i - j] == 'U' || text[i - j] == 'u'))
                    {
                        printf("%c", text[i - j]);
                    }
                    else if (text[i - j] > 64 && text[i - j] < 91)
                    {
                        text[i - j] = text[i - j] + 32;
                        printf("%c", text[i - j]);
                    }
                    else if (text[i - j] == '!')
                    {
                        for (k = 0; k < 5; k++)
                        {
                            printf("%c", text[i - j]);
                        }
                    }
                    else if (!(text[i - j] == '.' || text[i - j] == ',' || text[i - j] == '?' || text[i - j] == ':' || text[i - j] == ';' || text[i - j] == '"'))
                    {
                        printf("%c", text[i - j]);
                    }
                }
            }

            else if (text[i] > 64 && text[i] < 91)
            {
                text[i] = text[i] + 32;
                printf("%c", text[i]);
            }
            else if (text[i] == '!')
            {
                for (j = 0; j < 5; j++)
                {
                    printf("%c", text[i]);
                }
            }
            else if (!(text[i] == '.' || text[i] == ',' || text[i] == '?' || text[i] == ':' || text[i] == ';' || text[i] == '"'))
            {
                printf("%c", text[i]);
            }
            leerzeichen = i;
        }
    }
    printf("\n");
}