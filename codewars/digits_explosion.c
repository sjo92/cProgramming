#include <stdlib.h>
#include "readtext.c"

char *digits_explode(const char *digits)
{
    int sum = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    while (digits[i] != '\0')
    {
        if (digits[i] != '0')
        {
            sum = (digits[i] - 48) + sum;
        }
        i++;
    }
    //123 => 122333

    char *copy = malloc(sum + 1);
    i = 0;
    while (i < sum)
    {
        for (j = 0; j < (digits[k] - 48); j++)
        {
            copy[i] = digits[k];
            i++;
        }
        if (j == (digits[k] - 48))
        {
            k++;
            j = 0;
        }
    }
    copy[i] = '\0';
    return copy;
}

int main()
{
    printf("Bitte geben Sie etwas ein:");
    char *digit = readtext();
    char *test = digits_explode(digit);
    printf("explode: %s", test);

    return 0;
}