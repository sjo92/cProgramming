#include <stdio.h>

int iplusplus(int *i)
{

    return (*i)++;
}
int main()
{
    int i = 0;
    printf("i=%d\n", iplusplus(&i));
    printf("i=%d\n", iplusplus(&i));
    printf("i=%d\n", iplusplus(&i));
}