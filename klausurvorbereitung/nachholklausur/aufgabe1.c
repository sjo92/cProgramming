#include <stdio.h>

void durchschnitt(int * noten, int index) {
    int i=0;
    int summe=0;
    double durchschnitt=0;
    
    for(i=0; noten[i]!='\0'; i++) {
        summe=summe+noten[i];
    }
    durchschnitt= (double) (summe)/(i);
    if (index ==1) {
        printf("Der gesamte Durchschnitt: %.3lf\n", durchschnitt);
    }else {
        printf("\t -> aktueller Durchschnitt: %.2lf\n", durchschnitt);
    }
    
}

int main() {
    int noten[10];
    int i =0;
    int temp=0;
    printf("Geben Sie Noten (1 bis 6) ein, deren Durchschnitt berechnet werden soll. Sie beenden das Programm durch Eingabe einer negativen Zahl\n");
    do{
        printf("Eingab der %d. Note: ", i+1);
        scanf("%d", &temp);
        if(temp>=1&&temp<=6) {
            noten[i]=temp;
            durchschnitt(noten, 0);
            i++;
        } else if(temp<0) {
            printf("Ende der Eingabe.\n");
            durchschnitt(noten, 1);
        } else {
            printf("Das ist keine gültige Note! (Nur 1,2,3,4,5,6 sind erlaubt!\n");
        }
    }while(i<10);

    durchschnitt(noten, 10);

    return 0;
}