#include <stdio.h>

int main()
{
    /*
    char x[] = "234\0";
    printf("%d\n", x[3]);
    printf("%d\n", 2652 % 128);
    printf("%d\n", 184 % 128);
    x[1] = x[1] * x[2];
    printf("%d\n", x[1]);
    printf("%s\n", x);
    return 0;
*/
    char x[] = "234\012";
    printf("%c\n", x[3]);
    //x[1] = x[1] * x[2] + x[3];
    printf("%s", x);
}