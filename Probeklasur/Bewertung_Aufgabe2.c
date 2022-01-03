#include <stdio.h>

int aufgabe2_a()
{
//    char kette[99];
    char kette[100]; // 99 Zeichen + Terminator-Zeichen
    printf("Bitte geben Sie eine Zeichenkette ein: \n");
    scanf("%s", kette);
    int length = 0;
    int i; // Länge der Kette
//Schleifen nicht mit break verlassen
    /*    for (i = 0; i < 99; i++)
    {
        if (kette[i] == '\0')
        {
            break;
        }
        length++;
    }*/
    for(i=0;kette[i] != '\0';i++){
    }
    length=i;
    //23451

    printf("Die Länge ist: %d \n", length);
    int index1;
    int index2;
    for (index1 = 0; index1 < length; index1++)
    {
        char first = kette[0];
        for (index2 = 0; index2 < length; index2++)
        {

            if (index2 == length - 1)
            {
                kette[index2] = first;
            }
            else
            {
                kette[index2] = kette[index2 + 1];
            }
        }
        printf("Die Kette ist:%s \n", kette);
    }
    return 0;
}

void aufgabe2()
{
    char kette[100];
 //   char kette[99];
    printf("Bitte geben Sie eine Zeichenkette ein: \n");
    scanf("%s", kette);
    int length = 0;
    int i; // Länge der Kette
    //SChleife nicht mit break verlassen
/*    for (i = 0; i < 99; i++)
    {
        if (kette[i] == '\0')
        {
            break;
        }
        length++;
    }*/
    for(i=0;kette[i] != '\0';i++){
    }
    length=i;

    printf("Die Länge ist: %d \n", length);
    int index1;
    int index2;
//(    for (index1 = 0; index1 < length; index1++)
    for (index1 = 1; index1 < length-1; index1++)
    {
        char second = kette[1];
//        for (index2 = 0; index2 < length; index2++)
         for (index2 = 1; index2 < length-1; index2++)
        {
 //           if (index2 == 0 || index2 == length - 1)
//           {
//            }
//            else if (index2 == length - 2)
             if (index2 == length - 2)
            {
                kette[index2] = second;
            }
            else
            {
                kette[index2] = kette[index2 + 1];
            }
        }
        printf("Die Kette ist:%s \n", kette);
    }
}

int main()
{
    int result;
    aufgabe2();
    
    return 0;
}
