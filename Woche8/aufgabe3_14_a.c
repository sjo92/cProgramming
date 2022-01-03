#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"

int my_strlen(char *kette)
{
    int i;
    for (i = 0; kette[i] != '\0'; i++)
    {
    }
    return i;
}

char *my_concat_weird(char *str1, char *str2)
{
    int i = 0, k = 0, j = 0;
    int pos = 0, incr = 2;
    int length;
    int rest_length;
    char *str_con = malloc(length);

    if (my_strlen(str1) >= my_strlen(str2))
    {
        length = my_strlen(str2);
        rest_length = my_strlen(str1) - my_strlen(str2);
    }
    else if (my_strlen(str1) < my_strlen(str2))
    {
        length = my_strlen(str1);
        rest_length = my_strlen(str2) - my_strlen(str1);
    }
    for (i = 0; i < length * 2; i += incr)
    {
        str_con[i] = str1[k];
        str_con[i + 1] = str2[k];
        k++;
    }
    j = i;
    for (i = j; i < rest_length + j; i++)
    {

        if (my_strlen(str1) >= my_strlen(str2))
        {
            str_con[i] = str1[k];
            k++;
        }
        else if (my_strlen(str1) < my_strlen(str2))
        {
            str_con[i] = str2[k];
            k++;
        }
    }

    //Banane
    //Hallo Welt
    //Exepected Output: ”BHaanlalnoe Welt
    /*
    for(i = 0; i < length; i=i+incr){
        str_con[i] = str1[pos];
        pos++;
    }
    pos = 0;
    for(i = 1; i < length; i=i+incr){
        str_con[i] = str2[pos];
        pos++;
    }
*/
    return str_con;
}

int main()
{
    char *test_1;
    char *test_2;
    char *weird;
    printf("Bitte geben Sie etwas ein:");
    test_1 = readtext();
    printf("Bitte geben Sie etwas ein:");
    test_2 = readtext();

    weird = my_concat_weird(test_1, test_2);

    printf("Text1: %s\n", test_1);
    printf("Text1: %s\n", test_2);

    printf("Result: %s\n", weird);
}