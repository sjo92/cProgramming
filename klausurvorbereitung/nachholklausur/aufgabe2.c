#include <stdio.h>
#include <stdlib.h>

int main() {
    int max=10;
    int *intArray=malloc(sizeof(int)*max);
    intArray[0]=317;
    intArray[1]=42;
    intArray[2]=779;
    int i=3;
    for(i=3; i<max; i++) {
        intArray[i]=rand()%1000;
        printf("%d\n", intArray[i]);
    }
    int high = intArray[0];
    for(i=1; i<max; i++) {
        int key=intArray[i];
        int j=i-1;
        while(j>=0&&intArray[j]>key) {
            intArray[j+1]=intArray[j];
            j=j-1;
        }
        intArray[j+1]=key;
    }
    for(i=0; i<max; i++) {
        printf("%d\t", intArray[i]);
    }

    return 0;
}