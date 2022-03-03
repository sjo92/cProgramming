#include <stdio.h>

int main() {
    char num[100];
    int zahl;
    int i;
    printf("Bitte geben Sie eine Zahl ein:");
    scanf("%s", num);

    for(i=0; num[i]!='\0'; i++) {
        zahl=(zahl*10)+(num[i]-'0');
    }
    printf("Die zahl ist %d\n", zahl);
    printf("Die Zahl ist %s\n", num);
}