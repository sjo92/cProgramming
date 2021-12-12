#include <stdio.h>
#include "readtext.c"

int main()
{
    printf("Bitte geben Sie etwas ein: ");
    char *text = readtext();
    printf("Sie haben eingegeben \"%s\".\n", text);
    free(text);
    return 0;
}