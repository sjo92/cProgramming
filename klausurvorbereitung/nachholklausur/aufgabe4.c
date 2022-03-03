#include <stdio.h>
#include <stdlib.h>

enum TYPE {Sonne=1, Planet, Mond, Kleinplanet, Asteroid, Komet};

struct Solarsystem {
    char Name[12];
    enum TYPE type;
    float Entfernung;
    float Umflaufzeit;
    float Rotation;
};

int main(int argc, char **argv) {
    int i=0;
    struct Solarsystem solarsystem[argc];

    for(i=0; i<argc; i++) {
        printf("Bitte geben Sie den Name ein ");
        scanf("%s", solarsystem[i].Name);
        printf("Bitte geben Sie den Typ ein: (1: Sonne, 2:Planet, 3:Mond, 4: Kleinplanet, 5:Asteroid, 6:Komet) ");
        scanf("%d", &solarsystem[i].type);
        printf("Bitte geben Sie die Entfernung ein ");
        scanf("%f", &solarsystem[i].Entfernung);
    }

    for(i=0; i<argc; i++) {
        printf("%s: \t", solarsystem[i].Name);
        printf("Type: %d", solarsystem[i].type);
        printf("Entfernung: %f\n", solarsystem[i].Entfernung);
    }
}