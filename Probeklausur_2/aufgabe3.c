#include <stdio.h>
#include <stdlib.h>

void bildschirm_ausgeben(char *text, int ref) {
    int i=0;
    if(ref==0) printf("Error!\n");
    if(ref==1) {
        while(text[i]!='\0') {
            if(text[i]>='A'&&text[i]<='Z' || text[i]>='a'&&text[i]<='z'){
            printf("%c", text[i]);
            i++;
            }
        }
    } else if (ref==2) {
        while(text[i]!='\0') {
            if(text[i]>='0'&&text[i]<='9'){
            printf("%c", text[i]);
            i++;
            }
        }
    }
} 

int main() {
    int i=0;
    int max = 200;
    int buchstabe=0;
    int zahl=0;
    int ref=0;
    char c='0';
    char *text=malloc(sizeof(char)*max);
    FILE *fp=fopen("aufgabe3.txt", "r");

    if(fp==NULL) {
        printf("File does not exist!\n");
    } 
    do {
        c= fgetc(fp);
        text[i]=(char)c;
        i++;
        if(i==max) {
            max = max+200;
            text=realloc(text, sizeof(char)*max);
        }
        
    } while(c!=EOF);


    fclose(fp);

    text[i]='\0';
    text=realloc(text, i-1);
    for(i=0;text[i]!='\0';i++) {
        if(text[i]>='0'&&text[i]<='9'){
            zahl++;}
        
        if(text[i]>='A'&&text[i]<='Z' || text[i]>='a'&&text[i]<='z') {
            buchstabe++;
        }
        
    }

    printf("zahl %d buchstabe %d", zahl, buchstabe);
    if(buchstabe >zahl) ref = 1;
    if(buchstabe < zahl) ref = 2;
    bildschirm_ausgeben(text, ref);

    
    return 0;
}