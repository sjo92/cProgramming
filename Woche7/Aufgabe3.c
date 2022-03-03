#include <stdio.h>

int iplusplus(int *input)
{
    *input = *input +1;
    return *input;
}
int main()
{
    int i = 0;
    printf("i=%d\n", iplusplus(&i));
    printf("i=%d\n", iplusplus(&i));
    printf("i=%d\n", iplusplus(&i));
}