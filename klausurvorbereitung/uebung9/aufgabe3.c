#include <stdio.h>

struct VEKTOR {
    int x;
    int y;
    int z;
};

void vektor_ausgeben(struct VEKTOR a) {
    printf("(X, Y, Z: %d, %d, %d)\n", a.x, a.y, a.z);
}
struct VEKTOR vektor_eingeben() {
    struct VEKTOR temp;
    printf("Bitte geben Sie den Wert X ein: ");
    scanf("%d", &temp.x);

    printf("Bitte geben Sie den Wert Y ein: ");
    scanf("%d", &temp.y);

    printf("Bitte geben Sie den Wert Z ein: ");
    scanf("%d", &temp.z);

    return temp;
}
struct VEKTOR vektor_addieren(struct VEKTOR b, struct VEKTOR c) {
    struct VEKTOR temp;
    temp.x= b.x + c.x;
    temp.y = b.y + c.y;
    temp.z = b.z + c.z;

    return temp;
}

int main() {
    struct VEKTOR a;
    a.x=1;
    a.y=2;
    a.z=3;

    vektor_ausgeben(a);
    struct VEKTOR b = vektor_eingeben();
    struct VEKTOR c = vektor_eingeben();

    struct VEKTOR summe = vektor_addieren(b, c);
    vektor_ausgeben(summe);
    return 0;
}