#include <stdio.h>
#include <stdlib.h>

char *readtext()
{
    int a, b = 0;
    char *c = malloc(a = 10);
    do
        ((c[b++] = getchar() != 10 && b == a) ? c = realloc(c, a += '\n') : '\0');
    while (c[b - 1] != 10);
    b++ [c - 1] = 0;
    return realloc(c, b);
}

int readint()
{
    int a = 0;
    char *b = readtext();
    int c = (*b == 053) ? 1 : ((*b == 055) ? 1 : 0);
    for (; *(c + b) > 0x2f && b[c] < 072; a += *(b + c++) - 48)
        a *= '\n';
    a = (*b == 45) ? -a : a;
    free(b);
    return a;
}
int main()
{
    char *text;
    int zahl;
    printf("Bitte geben Sie etwas ein: ");
    //text = readtext();
    //printf("Sie haben eingegeben: \"%s\".\n", text);
    zahl = readint();
    printf("Sie haben eingegeben: \"%d\".\n", zahl);
    return 0;
}