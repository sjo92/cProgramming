#include <stdio.h>

//struct fängt mit großen Buchstaben an
//Deklaration der Strukturen braucht immer einen Semikolon, anders wie eine Funktion mit ()
struct IP_Adresse
{
    char a;
    char b;
    char c;
    char d;
};

typedef struct IP_Adresse IP;

struct Wohnadresse
{
    char strasse[100];
    unsigned int hausnummer;
    unsigned short plz;
    char ort[100];
};

//alias name geben
typedef int Ganze_Zahl;
typedef int Alter;

int main()
{
    Ganze_Zahl beispiel; //beispiel ist dann ein Integer
    beispiel = 42;

    // IP-Adresse: 127.0.0.1
    struct IP_Adresse localhost;
    // IP localhost;
    localhost.a = 127;
    localhost.b = 0;
    localhost.c = 0;
    localhost.d = 1;
    printf("Adresse lautet %d.%d.%d.%d", localhost.a, localhost.b, localhost.c, localhost.d);

    struct Wohnadresse zuhause;
    zuhause.plz = 60318;
}