#include <stdio.h>

struct Tupel
{
    int x;
    int y;
};

struct Rechteck
{
    struct Tupel unten_links;
    struct Tupel oben_rechts;
};

void tupel_ausgeben(struct Tupel tupel)
{
    printf("X: %d, Y: %d", tupel.x, tupel.y);
}

struct Tupel tupel_einlesen()
{
    struct Tupel eingabe;
    printf("Wie lautet der Wert für x? ");
    scanf("%d", &eingabe.x);
    printf("Wie lautet der Wert für y? ");
    scanf("%d", &eingabe.y);

    return eingabe;
}
void rechteck_ausgeben(struct Rechteck kasten)
{
    printf("Die Koordinaten des Rechtecks lauten ");
    tupel_ausgeben(kasten.unten_links);
    printf(" und ");
    tupel_ausgeben(kasten.oben_rechts);
    printf(".\n");
}
struct Rechteck rechteck_einlesen()
{
    struct Rechteck eingabe;
    printf("Es wird nun ein Rechteck eingelesen. \n");
    printf("Bitte die Koordinaten für unten links angeben. \n");
    eingabe.unten_links = tupel_einlesen();

    printf("Bitte die Koordinaten für oben rechts angeben. \n");
    eingabe.oben_rechts = tupel_einlesen();

    return eingabe;
}

int main()
{
    struct Tupel koordinate;
    struct Rechteck viereck;
    viereck = rechteck_einlesen();
    rechteck_ausgeben(viereck);
    koordinate = tupel_einlesen();
    tupel_ausgeben(koordinate);
    return 0;
}