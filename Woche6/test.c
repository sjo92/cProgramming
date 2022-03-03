#include <stdio.h>

int main(){
    char user_input;
    char letters[100];
    char c=0;

    printf("Please enter something:\n");
    do {
        user_input=getchar();
        if(user_input!='\n') {letters[c]=user_input;}
        c++;
    }
    while(user_input!='\n');

    for(c=0; letters[c]!='\0'; c++){
        printf("The letter %c has the ASCII-value of %d.\n", letters[c], letters[c]);
    }
    
    printf("The string has now ended.\n");

    return 0;
}