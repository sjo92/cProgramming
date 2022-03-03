#include <stdio.h>
#include <stdlib.h>

int readint() {
    int i=0;
    int max = 20;
    char c;
    int vorzeichen=1;
    int zahl=0;
    do {
        c =getchar();
        printf("(%d)", c);
        if (c!=10 && (c>='0'&& c<='9') || (c=='-' && zahl ==0)|| (c=='+' && zahl ==0)) {
            if(c=='-' && zahl ==0) {vorzeichen=-1;}
            else if(c=='+' && zahl ==0) {
                vorzeichen=1;
            } else {
                zahl=zahl*10+c-'0';
        }
        }
    }while(c!='\n' &&(c>='0'&& c<='9') || (c=='-' && zahl ==0)|| (c=='+' && zahl ==0));

    zahl = zahl*vorzeichen;
    return zahl;

}