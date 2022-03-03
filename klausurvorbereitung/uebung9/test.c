#include "readint.c"
#include <stdio.h>

int main() {
    printf("Int: ");
    int i = readint();
    printf("Eingabe: %d\n",i);
    return 0;
}