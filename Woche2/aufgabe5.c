#include <stdio.h>

int main()
{
    printf("%d\n", (8 / 5) / 2);    // 0
    printf("%f\n", (8 / 5) / 2);    // 0.00000
    printf("%i\n", 8 / (5 / 2));    // 4
    printf("%f\n", (float)5 / 2);   // 2.50000
    printf("%f\n", (float)(5 / 2)); // 2.0000
    printf("%d\n", (8 / 5.) / 2);   // 73896
    printf("%lf\n", (8 / 5) / 2.);  // 0.50000
    printf("%d\n", (50 / 4) % 2);   // 0
    printf("%d\n", (50 % 4) / 2);   // 1
    printf("%d\n", 50 % (4 / 2));   // 0
}