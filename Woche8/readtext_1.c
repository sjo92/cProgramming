#include <stdio.h>
#include <stdlib.h>

char* readtext() {
    int i=0;
    int max = 10;
    char *text=malloc(sizeof(char)*max);
    char c;

    do {
        c=getchar();
        if(c!='\n') {
            text[i]=c;
            i++;
            if(i==max) {
                max = max +10;
                text = realloc(text, sizeof(char)*max);
            }
            
        } 
    } while(c!='\n');
    text[i]='\0';
    text = realloc(text, i+1);
    return text;
}