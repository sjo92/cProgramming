#include <stdio.h>
#include <math.h>

double pi()
{
    return 3.141592;
}
double userinput(void)
{
    double number;
    printf("\tadress of userinput():number = %p\n", &number);
    printf("Please enter a number: \n");
    scanf("%lf", &number);
    return number;
}
/*
double double_of(double x)
{
    double result;
    result = 2 * x;
    return result;
}*/

// Gibt das Doppelte der übergebenen Zahl zurück.
int double_of(int x)
{
    double result;
    result = 2 * x;
    return (int)result;
}

void greeting(void) // kein Parameter an greeting übergeben
{
    printf("Willkommen beim Programm. \n");
}

// Länge eines Vektors x,y
double length_of_vector(double x, double y)
{
    return sqrt(x * x + y * y);
}

// Verschiedene Datentyp in einer Funktion mischen
double irgendwas(int eins, float zwei, char drei)
{
    return 0;
}

int tue_was_mit_x(int x)
{
    printf("Anfang der Funktion \n");
    printf("\tWert von x = %d\n", x);
    x++;
    printf("\tWert von x = %d\n", x);
    printf("Ende der Funktion \n");
    return x;
}

// Vertauscht die Werte von x und y
//Keine Referenzparameter verwendet!!
void swap(int *x, int *y)
{
    // Vertausch durch Dreieckstausch
    int temp = *x; // x zwischenspeichern
    *x = *y;       // x mit y überschreiben
    *y = temp;     // gesichertes x und y schreiben
}

int main()
{
    int a = 42;
    int b = 100;
    printf("a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("a=%d, b=%d\n", a, b);

    return 0;
}

/*
int main()
{
    greeting();
    double number = 0;
    number = userinput();
    printf("the double is %d\n", double_of(number)); //The declaration and implementation should be before main method according to ansi c
    return 0;
}
*/
/*
int main()
{
    double number;
    printf("/tadress of main():number = %p\n", &number);
    printf("Now calling function userinput. \n");
    number = userinput();
    printf("Now calling function userinput. \n");
    printf("back in main. \n");
    printf("The user entered %lf \n", number);
    return 0;
}*/