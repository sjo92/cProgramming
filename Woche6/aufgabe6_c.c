#include <stdio.h>

/*
Nach Benutzereingabe wird ein String umgedreht
*/
void string_rev() {
    char kette[30];
    int length=0;
    int i=0;
    printf("Bitte geben Sie eine Zahl ein:");
    scanf("%s", kette);
    
    while(kette[length]!='\0') length++;
    printf("Umgedreht ist es: ");
    for(i=length; i>=0; i--) {
        printf("%c", kette[i]);
    }
    printf("\n");
}

/*
Nach Benutzereingabe wird eine Zahl umgedreht.
Beispiel: 
1234 = 4+1230 (4: Modulo 10 von 1234)
1230 = 30 + 1200 (3: Modulo 10 von 123=(1234-4)/10)
1200 = 200 + 1000 (2: Modulo 10 von 12=(123-3)/10)
1000 = 1000 (1: Modulo 10 von 1=(12-2)/10)

4321 = (((4)*10+3)*10+2)*10+1
*/
void int_rev() {
    int zahl;
    int rest;
    int rev=0;
    printf("Bitte geben Sie eine Zahl ein :");
    scanf("%i", &zahl);
    
    //floating number of int will be 0 in int. Die Schleife wird so lange durchgeführt, bis die höchste Ziffer erreicht wurde.
    while(zahl>0) {
        rest = zahl%10;
        zahl = zahl/10;
        rev = rev*10+rest;
    }
    printf("Umgedreht ist es: %d\n", rev);

}

int main() {
    string_rev();
    int_rev();

    return 0;
}