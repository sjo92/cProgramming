#include <stdio.h>

int primtest(int z) {
    int i=0;
    if(z<=1) return 0;
    else {
        for(i=2; i<z; i++) {
            if(z%i==0) {
                return 1;
            }
        }
    
    }
    return 0;
}

void zahl_ausgeben(int * zahlen, int index, int ref){
    int i =0;
    if(ref==0) {
        printf("Nicht-");
    }
    printf("Primzahlen: ");
    for(i=0; i<index; i++) {
        printf("%d ", zahlen[i]);
    }
    printf("\n");
} 
void summe(int *prim, int *noprim, int index_p, int index_np) {
    int i=0;
    int sum_prim=0;
    int sum_noprim=0;

    for(i=0; i<index_p; i++) {
        sum_prim=sum_prim+prim[i];
    }
    for(i=0; i<index_np; i++) {
        sum_noprim=sum_noprim+noprim[i];
    }
    if(sum_prim>sum_noprim) {
        printf("Die Summe der Primahlen ist größer als Non-Primzahlen (%d >%d)", sum_prim, sum_noprim);
    } else if (sum_prim <sum_noprim){
        printf("Die Summe der NON-Primahlen ist größer als Primzahlen (%d >%d)", sum_noprim, sum_prim);
    }

}

int main() {
    int prims[6];
    int noprims[6];
    int zahl;
    int test;
    int i=0;
    int j=0;
    int k=0;
    for(i=0; i<6; i++) {
    do {
        
        printf("Bitte geben Sie die %d. Zahl ein: ", i+1);
        scanf("%d", &zahl);
        if(zahl>1) {
            test = primtest(zahl);
            if (test==0) {
                noprims[j]=zahl;
                j++;
                printf("j= %d\n", j);
            } else if (test==1) {
                prims[k]=zahl;
                k++;
                printf("k= %d\n", k);
            }
        } else{
            printf("Die Zahl ist ungültig!\n");
        }
        }
        while(zahl<=1);
    }
    zahl_ausgeben(prims, k, 1);
    zahl_ausgeben(noprims, j, 0);
    summe(prims, noprims, k, j);
    
    
}