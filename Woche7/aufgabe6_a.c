#include <stdio.h>
#include <stdlib.h>

void zahl_ausgeben(int* eingabe) {
    int i=0;
    while(eingabe[i]!='\0'){
        printf("%d\t", eingabe[i]);
        i++;
    }
}

int main() {
    int max = 10;
    int i =0;
    int *kette = malloc(sizeof(int)*max);
     char answer;
    do {
        int temp;
        int speicher;
       
        printf("Bitte geben Sie eine Zahl ein: ");
        scanf("%d", &temp);
        kette[i]=temp;
        //Wenn i == max-1, der letzte Speicherplatz wurde erreicht. 
        if(i==max-1) {
            printf("Möchten Sie noch weitere Zahlen eingeben? (Y|N)\n");
            scanf("%c", answer);
            printf("Wie viele Zahlen möchten Sie noch eingeben?\n");
            scanf("%d", &speicher);
            max = max+speicher;
            kette = realloc(kette, sizeof(int)*max);
        }
        i++;
    } while(answer!='N' &&answer!='n');
    kette[i]='\0';
    kette=realloc(kette, sizeof(int)*i);

    zahl_ausgeben(kette);
    free(kette);
    return 0;
}