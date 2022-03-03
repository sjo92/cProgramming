#include <stdio.h>
#include <stdlib.h>
#include "readtext_1.c"

/*
Für Aufgabe 1
Rückgabewert: Anzahl Zeichen der Zeichenkette im Parameter
*/
int anzahl_kette(char *text) {
    int i =0;
    while(text[i]!='\0') {
        i++;
    }
    return i;
}

int anzahl_kette_rek(char* text, int index) {
    if(text[index]=='\0') {
        return index;
    } else {
        index = index+1;
        return anzahl_kette_rek(text, index);
    }
}

void aufgabe_1() {
    int anzahl=0;
    printf("Bitte geben Sie etwas ein: ");
    char *text = readtext();
    //anzahl = anzahl_kette(text);
    anzahl=anzahl_kette_rek(text, 0);
    printf("Die Anzahl ist %d", anzahl);
    free(text);
}

/*
Für Aufgabe2
Parameter: Zeichenkette, Zeichen 
Rückgabewert: Anzahl des bestimmten Zeichen in der gegebenen Zeichenkette
*/
int anzahl_zeichen(char *text, char target) {
    int anzahl = 0;
    int i=0;
    while(text[i]!='\0') {
        if (text[i]==target) anzahl++;
        i++;
    }
    return anzahl;
}

int anzahl_zeichen_rek(char *text, char target, int anzahl, int index) {
    if(text[index]=='\0') {
        return anzahl;
    } else {
        if (text[index]==target) anzahl++;
        index = index+1;
        return anzahl_zeichen_rek(text, target, anzahl, index);
    }
}

void aufgabe_2() {
    int anzahl=0;
    printf("Bitte geben Sie etwas ein: ");
    char *text = readtext();
    printf("Welches Zeichen soll gezählt werden?");
    char c = getchar();
    //anzahl = anzahl_zeichen(text,c);
    anzahl=anzahl_zeichen_rek(text, c, 0, 0);
    printf("Die Anzahl ist %d\n", anzahl);
    free(text);
}

/*
Für Aufgabe3
eine Zeichenkette wird in einem neuen Speicherbereich kopiert.
Parameter: Zeichenkette
Rückgabewert: Kopie von der Zeichenkette vom Parameter
*/

char* copy_text(char*text){
    int i =0;
    int length = anzahl_kette(text)+1; //Die Größe prüfen +1 Terminator
    char *copy = malloc(sizeof(char)*length);
    while(text[i]!='\0') {
        copy[i]=text[i];
        i++;
    }
    copy[i]='\0'; // Am Ende Terminator
    return copy;
}

char* copy_text_rek(char*text, char*copy, int index) {
    if(text[index]=='\0') {
        return copy;
    } else{
        copy[index]=text[index];
        index = index+1;
        return copy_text_rek(text, copy, index);
    } 
}

void aufgabe_3() { 
    printf("Bitte geben Sie etwas ein: ");
    char *text = readtext();
    //char *copy = copy_text(text);
    char *copy_2= malloc(anzahl_kette(text));
    char *test=copy_text_rek(text, copy_2, 0);
    printf("original: (%p: %s)\n", text, text);
    printf("copy : (%p: %s)\n", test, test);
    free(text);
    free(copy_2);

}

/*
Für Aufgabe4
eine Zeichenkette wird gespiegelt in einem neuen Speicherbereich kopiert.
Parameter: Zeichenkette
Rückgabewert: Eine gespiegelte kopie von der Zeichenkette vom Parameter
Beispiel: (Banane) -> (enanaB)
*/

char* copy_text_reverse(char*text){
    int i =0;
    int length = anzahl_kette(text); //Ohne Terminator
    char *copy = malloc(sizeof(char)*(length+1)); // Größe trotzdem mit Terminator
    while(text[i]!='\0') {
        copy[i]=text[length-i-1]; // text[length] ist '\0'. Wir brauchen ab length-1 bis 0 (absteigend)
        i++;
    }
    copy[i]='\0';
    return copy;
}

char* copy_text_reverse_rek(char*text, int low, int high) {
    if(low<high) {
        char temp = text[low];
        text[low]=text[high];
        text[high]= temp;
        copy_text_reverse_rek(text, low+1, high-1);
    } return text;
}

void aufgabe_4() { 
    printf("Bitte geben Sie etwas ein: ");
    char *text = readtext();
    int length = anzahl_kette(text);
    char *copy = malloc(length); 
    printf("original: (%p: %s)\n", text, text);
    text=copy_text_reverse_rek(text, 0, length-1);
    printf("copy : (%p: %s)\n", text, text);
    free(text);
}


/*
Für Aufgabe5
eine Zeichenkette wird ASCII wert 1 erhöht in einem neuen Speicherbereich kopiert.
Parameter: Zeichenkette
Rückgabewert: Eine ASCII Wert manipulierte kopie von der Zeichenkette vom Parameter
Beispiel: (Banane) -> (Cbobof)
*/

char* copy_text_ascii_1(char*text){
    int i =0;
    int length = anzahl_kette(text)+1; //Die Größe mit Terminator
    char *copy = malloc(sizeof(char)*(length)); // 
    while(text[i]!='\0') {
        copy[i]=text[i]+1; 
        i++;
    }
    copy[i]='\0';
    return copy;
}

void aufgabe_5() { 
    printf("Bitte geben Sie etwas ein: ");
    char *text = readtext();
    char *copy = copy_text_ascii_1(text);
    printf("original: (%p: %s)\n", text, text);
    printf("copy : (%p: %s)\n", copy, copy);
    free(text);
    free(copy);

}

/*
Für Aufgabe6
eine Palindrom Zeichenkette wird in einem neuen Speicherbereich kopiert.
Parameter: Zeichenkette
Rückgabewert: Eine neue Zeichenkette. Die Zeichenkette vom Parameter + gespiegelte Zeichenkette vom Parameter
Beispiel: (Banane) -> (BananeenanaB)
*/

char* copy_text_palindrom(char*text){
    int i =0;
    int j=0;
    int length = anzahl_kette(text)*2+1; //Die doppelte Größe mit Terminator
    char *copy = malloc(sizeof(char)*(length)); 
    char *spiegel = copy_text_reverse(text);
    while(text[i]!='\0') {
        copy[i]=text[i]; 
        i++;
    }
    while(spiegel[j]!='\0') {
        copy[i]=spiegel[j];
        i++;
        j++;
    }
    copy[i]='\0';
    return copy;
}

void aufgabe_6() { 
    printf("Bitte geben Sie etwas ein: ");
    char *text = readtext();
    char *copy = copy_text_palindrom(text);
    printf("original: (%p: %s)\n", text, text);
    printf("copy : (%p: %s)\n", copy, copy);
    free(text);
    free(copy);

}


/*
Für Aufgabe7
eine Zeichenkette ohne Vokalen wird in einem neuen Speicherbereich kopiert.
Parameter: Zeichenkette
Rückgabewert: Eine neue Zeichenkette. Vokalen von der Zeichenkette wird ausgenommen
Beispiel: (Banane) -> (Bnn)
*/

char* copy_ohne_vokal(char*text){
    int i =0;
    int j=0;
    int length = anzahl_kette(text)+1; //Größe mit Terminator
    char *copy = malloc(sizeof(char)*(length)); 
    while(text[i]!='\0') {
        if(text[i]!='A'&&text[i]!='E'&&text[i]!='I'&&text[i]!='O'&&text[i]!='U'&&
        text[i]!='a'&&text[i]!='e'&&text[i]!='i'&&text[i]!='o'&&text[i]!='u') {
            copy[j]=text[i];
            j++;
        }
        i++;
    }
    copy[j]='\0';
    copy=realloc(copy, sizeof(char)*(j+1));
    return copy;
}

void aufgabe_7() { 
    printf("Bitte geben Sie etwas ein: ");
    char *text = readtext();
    char *copy = copy_ohne_vokal(text);
    printf("original: (%p: %s)\n", text, text);
    printf("copy : (%p: %s)\n", copy, copy);
    free(text);
    free(copy);

}

/*
Für Aufgabe8
eine Zeichenkette wird in einem neuen Speicherbereich kopiert. Alle Kleinbuchstaben von der Zeichenkette wird groß umgewandelt.
Parameter: Zeichenkette
Rückgabewert: Eine neue Zeichenkette. Kleinbuchstaben werden groß umgewandelt
Beispiel: (Banane) -> (BANANE)
*/

char* copy_capital(char*text){
    int i =0;
    int length = anzahl_kette(text)+1; //Größe mit Terminator
    char *copy = malloc(sizeof(char)*(length)); 
    while(text[i]!='\0') {
        if(text[i]>='a'&&text[i]<='z') {
            copy[i]=text[i]-32;
        } else{
            copy[i]=text[i];
        }
        i++;
    }
    copy[i]='\0';
    return copy;
}

void aufgabe_8() { 
    printf("Bitte geben Sie etwas ein: ");
    char *text = readtext();
    char *copy = copy_capital(text);
    printf("original: (%p: %s)\n", text, text);
    printf("copy : (%p: %s)\n", copy, copy);
    free(text);
    free(copy);

}

/*
Für Aufgabe9
eine Zeichenkette wird in einem neuen Speicherbereich kopiert. Alle Großbuchstaben von der Zeichenkette werden klein umgewandelt.
Parameter: Zeichenkette
Rückgabewert: Eine neue Zeichenkette. Kleinbuchstaben werden groß umgewandelt
Beispiel: (Banane) -> (banane)
*/

char* copy_small(char*text){
    int i =0;
    int length = anzahl_kette(text)+1; //Größe mit Terminator
    char *copy = malloc(sizeof(char)*(length)); 
    while(text[i]!='\0') {
        if(text[i]>='A'&&text[i]<='Z') {
            copy[i]=text[i]+32;
        } else{
            copy[i]=text[i];
        }
        i++;
    }
    copy[i]='\0';
    return copy;
}

void aufgabe_9() { 
    printf("Bitte geben Sie etwas ein: ");
    char *text = readtext();
    char *copy = copy_small(text);
    printf("original: (%p: %s)\n", text, text);
    printf("copy : (%p: %s)\n", copy, copy);
    free(text);
    free(copy);

}
/*
Für Aufgabe10
eine Zeichenkette wird in einem neuen Speicherbereich kopiert. 
Die ersten 13 Buchstaben des Alphabets werden mit den letzten 13 Zeichen vertauscht werden. (ROT13 Verschlüsselung)
Parameter: Zeichenkette
Rückgabewert: Eine verschlüsselte Zeichenkette mit ROT13
Beispiel: (Banane) -> (Onanar)
*/

char* copy_rot13(char*text){
    int i =0;
    int length = anzahl_kette(text)+1; //Größe mit Terminator
    char *copy = malloc(sizeof(char)*(length)); 
    while(text[i]!='\0') {
        if(text[i]>='A'&&text[i]<='A'+12 || text[i]>='a'&&text[i]<='a'+12 ) { //Erste 13 Zeichen werden mit den letzten 13 Zeichen vertauscht
            copy[i]=text[i]+13;
        } else if (text[i]>='A'+13 &&text[i]<='Z' || text[i]>='a'+13 &&text[i]<='z' ){ //Letzte 13 Zeichen werden mit den ersten 13 Zeichen vertauscht
            copy[i]=text[i]-13;
        } else {
            copy[i]=text[i]; // Falls andere Zeichen außer Buchstaben in der Zeichenkette enthalten sind, werden gleich bleiben.
        }
        i++;
    }
    copy[i]='\0';
    return copy;
}

void aufgabe_10() { 
    printf("Bitte geben Sie etwas ein: ");
    char *text = readtext();
    char *copy = copy_rot13(text);
    printf("original: (%p: %s)\n", text, text);
    printf("copy : (%p: %s)\n", copy, copy);
    free(text);
    free(copy);

}

/*
Für Aufgabe11
Eine mit Caesar Verschlüsselung verschlüsselte Zeichenkette wird in einem neuen Speicherbereich kopiert. 
Parameter: Zeichenkette, index
Rückgabewert: Eine verschlüsselte Zeichenkette mit Caesar Verschlüsselung (um die Index vom Parameter verschoben)
Beispiel: (Banane) -> (Edqdqh)
*/

char* copy_caesar(char*text, int index){
    int i =0;
    int length = anzahl_kette(text)+1; //Größe mit Terminator
    index = index%26; // Falls die Index größer als 26 ist.
    char *copy = malloc(sizeof(char)*(length)); 
    while(text[i]!='\0') {
        if(text[i]>='A'&&text[i]<='Z' ) { 
            copy[i]=(text[i]-'A'+index) %26 +'A'; //text[i]-'A' : Welche Stelle von Großbuchstaben / Nach der Modulorechnung wieder +'A' addiert werden, um den richtigen ASCII Wert auszugeben
        } else if (text[i]>='a'&&text[i]<='z') {
            copy[i]=(text[i]-'a'+index) %26 +'a'; //text[i]-'a' : Welche Stelle von Kleinbuchstaben / Nach der Modulorechnung wieder +'a' addiert werden, um den richtigen ASCII Wert auszugeben
        }else {
            copy[i]=text[i]; // Falls andere Zeichen außer Buchstaben in der Zeichenkette enthalten sind, werden gleich bleiben.
        }
        i++;
    }
    copy[i]='\0';
    return copy;
}

void aufgabe_11() { 
    printf("Bitte geben Sie etwas ein: ");
    char *text = readtext();
    char *copy = copy_caesar(text, 3);
    printf("original: (%p: %s)\n", text, text);
    printf("copy : (%p: %s)\n", copy, copy);
    free(text);
    free(copy);

}
/*
Für Aufgabe12
Zwei Zeichenketten werde miteinander vergleicht.
Parameter: Zwei Zeichenkette zum Vergleich
Rückgabewert: (-1: text_1 ist kleiner) (1: text_2 ist kleiner) (0: beide haben identische größe) 
Beispiel: Banane ist alphabetisch kleiner als Hallo Welt
*/

int str_compare(char*text_1, char * text_2){
    int i =0;
    while(text_1[i]!='\0' && text_2[i]!='\0') {
        if(text_1[i]<text_2[i]) return -1;
        if(text_2[i]<text_1[i]) return 1;
        i++;
    }
    if(text_1[i]!='\0') return 1;
    if(text_2[i]!='\0') return -1;
    return 0;
}

void aufgabe_12() { 
    printf("Bitte geben Sie etwas ein: ");
    char *text_1 = readtext();
    printf("Bitte geben Sie etwas ein: ");
    char *text_2 = readtext();
    int compare = str_compare(text_1, text_2);
    if(compare ==-1) {
        printf("\"%s\" ist alphabetisch kleiner als \"%s\"\n", text_1, text_2);
    } else if(compare ==1) {
        printf("\"%s\" ist alphabetisch kleiner als \"%s\"\n", text_2, text_1);
    } else {
        printf("\"%s\" ist alphabetisch gleich wie \"%s\"\n", text_1, text_2);
    }
    free(text_1);
    free(text_2);

}
/*
Für Aufgabe12
Zwei Zeichenketten werden in einer Zeichenkette aneinander gehängt.
Parameter: Zwei Zeichenkette
Rückgabewert: Neue zusammengehängte Zeichenkette 
Beispiel: Banane + Hallo Welt => BananeHallo Welt
*/

char *kette_concat(char *kette_1, char* kette_2) {
    int length = anzahl_kette(kette_1)+ anzahl_kette(kette_2)+1; //length = Anzahl von der 1. Kette + Anzahl von der 2. Kette + Einen Terminator
    char *copy=malloc(length);
    int i=0;
    int j=0;

    //Hier werden die Zeichen von der ersten Kette in der neuen Kette kopiert.
    while(kette_1[i]!='\0') {
        copy[i]=kette_1[i];
        i++;
    } 
    while(kette_2[j]!='\0'){
        copy[i]=kette_2[j];
        j++;
        i++;
    }
    copy[i]='\0';
    copy=realloc(copy, i+1);
    return copy;
}

void aufgabe_13() {
    printf("Bitte geben Sie einen Text ein :");
    char *text_1=readtext();
    printf("Bitte geben Sie einen anderen Text ein:");
    char *text_2=readtext();

    char *result=kette_concat(text_1, text_2);
    printf("original text 1: (%p: %s)\n", text_1, text_1);
    printf("original text 2: (%p: %s)\n", text_2, text_2);
    printf("copy : (%p: %s)\n", result, result);
    free(text_1);
    free(text_2);
    free(result);
}

/*
Für Aufgabe14
Zwei Zeichenketten werden in einer Zeichenkette vermischt aneinander gehängt.
Parameter: Zwei Zeichenkette
Rückgabewert: Neue zusammengehängte Zeichenkette 
Beispiel: Banane + Hallo Welt => BHaanlalnoe Welt
*/

char *kette_concat_mix(char *kette_1, char* kette_2) {
    int length = anzahl_kette(kette_1)+ anzahl_kette(kette_2)+1; //length = Anzahl von der 1. Kette + Anzahl von der 2. Kette + Einen Terminator
    char *copy=malloc(length);
    int i=0;
    int j=0;

    //Hier werden die Zeichen von beiden Ketten kopiert.
    while(kette_1[i]!='\0' || kette_2[i]!='\0') {
        if(kette_1[i]!='\0') {
            copy[j]=kette_1[i];
            j++;
        }
        if(kette_2[i]!='\0') {
            copy[j]=kette_2[i];
            j++;
        }
        i++;
    }
    copy[i]='\0';
    copy=realloc(copy, i+1);
    return copy;
}

void aufgabe_14() {
    printf("Bitte geben Sie einen Text ein :");
    char *text_1=readtext();
    printf("Bitte geben Sie einen anderen Text ein:");
    char *text_2=readtext();

    char *result=kette_concat_mix(text_1, text_2);
    printf("original text 1: (%p: %s)\n", text_1, text_1);
    printf("original text 2: (%p: %s)\n", text_2, text_2);
    printf("copy : (%p: %s)\n", result, result);
    free(text_1);
    free(text_2);
    free(result);
}
/*
Für Aufgabe15
In dieser Methode sucht man eine Zeichenkette durch und findet, ob eine Zeichenkette in einer anderen Zeichenkette drinsteht.
Falls ein Teil von der längeren Zeichenkette identisch zu der gegebenen Zeichenkette ist, wird die erste gefundene Anfangsposition ausgegeben.
Parameter: Zwei Zeichenkette (Eine als Ref, eine als Target zum vergleich)
Rückgabewert: Int. Erste gefundene Anfangsposition
Beispiel: Hallo Welt, We => 6
*/

int find_index(char *kette_1, char* target) {
    int index=0;
    int i=0;
    int j=0;
    int goal = anzahl_kette(target);

    for(i=0; kette_1[i]!='\0'; i++) {
        for(j=0; target[j]!='\0';j++) {
            if(kette_1[i+j]==target[j]) {
                index++;
                } else {index =0;}
            if(goal==index) return i;
        }
    }

    return -1;
}

void aufgabe_15() {
    printf("Bitte geben Sie einen Text ein :");
    char *text_1=readtext();
    printf("Bitte geben Sie einen anderen Text ein:");
    char *text_2=readtext();

    int index=find_index(text_1, text_2);
    printf("original text 1: (%p: %s)\n", text_1, text_1);
    printf("original text 2: (%p: %s)\n", text_2, text_2);
    if(index!=-1) {
        printf("Der Text wurde an der %d. Stelle gefunden\n", index);
    } else {
        printf("Der Text wurde nicht gefunden.\n");
    }
    free(text_1);
    free(text_2);
}

/*
Für Aufgabe16
In dieser Methode wird eine Zeichenkette ab den gewünschten Index mit der gegebenen Länge abgeschintten.
Parameter: Zeichenkette, int anfangsposition, int laenge
Rückgabewert: Die abgeschnitte Zeichenkette
Beispiel: (Hallo Welt, 3, 4) => (lo W)
*/

char *kopie_teil(char* text, int anfang, int length) {
    int i=0;
    char* copy=malloc(length+1); //memory allokation für die gegebene Laenge und Terminator
    length = length+anfang; // length shift um besser in der Schleife zu verwendet: Ab 3. Position für 4 Stelle => Ab 3. Position bis 6. Position < (3+4)=7. Position
    while(i+anfang <length) {
        copy[i]=text[i+anfang];
        i++;
    }
    copy[i]='\0';
    copy=realloc(copy, i+1);
    return copy;
}


void aufgabe_16() {
    printf("Bitte geben Sie einen Text ein :");
    char *text_1=readtext();
    char *text_2=kopie_teil(text_1, 3, 4);
    printf("original text 1: (%p: %s)\n", text_1, text_1);
    printf("geschnittener Text (index: %d length: %d): (%p: %s)\n", 3, 4, text_2, text_2);
    free(text_1);
    free(text_2);
}

int main() {
    aufgabe_4();

}