#include <stdio.h>
#define bool int
#define false 0
#define true 1

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    int rev = 0;
    int copy = x;
    while (copy > 0)
    {
        rev = rev * 10 + copy % 10;
        copy = copy / 10;
    }

    return rev == x;
}

int main()
{
    int zahl;
    printf("Bitte geben Sie eine Zahl ein:");
    scanf("%d", &zahl);

    int result = isPalindrome(zahl);
    printf("Result is: %d", result);
}