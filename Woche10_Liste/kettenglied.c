#include <stdio.h>
#include <stdlib.h>

struct kettenglied
{
    int datum;
    struct kettenglied *nachfolger;
};

struct kettenglied2
{
    int datum;
    struct kettenglied *vorgaenger;
    struct kettenglied *nachfolger;
};

int main()
{
    struct kettenglied a, b, c, d;
    struct kettenglied *anfang;
    a.datum = 10;
    b.datum = 20;
    c.datum = 30;
    d.datum = 40;
    anfang = &a;
    a.nachfolger = &b;
    b.nachfolger = &c;
    c.nachfolger = &d;
    d.nachfolger = NULL; // Zeigt auf Nichts = Ende

    struct kettenglied *iterator;
    iterator = anfang;
    while (iterator != NULL)
    {
        printf("%d ", (*iterator).datum);
        iterator = (*iterator).nachfolger;
    }
    printf("\n");
    return 0;
}