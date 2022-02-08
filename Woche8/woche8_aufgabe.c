#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"

int get_Length(char *test)
{
    int i = 0;
    while (test[i] != '\0')
    {
        i++;
    }
    return i;
}

void nr_1()
{
    char *test;
    int length = 0;
    printf("Bitte geben Sie etwas ein: ");
    test = readtext();
    length = get_Length(test);
    printf("Länge: %d\n", length);
    free(test);
}

int get_Character(char *test, char c)
{
    int i = 0;
    int b = 0;
    for (i = 0; test[i] != '\0'; i++)
    {
        if (test[i] == c)
        {
            b++;
        }
    }
    return b;
}

void nr_2()
{
    char *test;
    char zeichen;
    int character = 0;
    printf("Bitte geben Sie etwas ein: ");
    test = readtext();
    printf("Nun geben Sie ein Zeichen ein: ");
    scanf("%c", &zeichen);
    character = get_Character(test, zeichen);
    printf("Das Zeichen %c ist %d mal in dem Text enthalten\n", zeichen, character);
    free(test);
}

char *get_Copy(char *org)
{
    char *copy;
    int length = 0;
    length = get_Length(org) + 1;
    copy = malloc(length);
    int i = 0;
    while (org[i] != '\0')
    {
        copy[i] = org[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}
void nr_3()
{
    char *test;
    char *copy;
    printf("Bitte geben Sie etwas ein: ");
    test = readtext();
    copy = get_Copy(test);
    printf("Original: (%s, %p) \n", test, &test);
    printf("Copy: (%s, %p) \n", copy, &copy);
    free(test);
    free(copy);
}

char *get_Mirrored(char *org)
{
    char *copy;
    int length = 0;
    length = get_Length(org) + 1; //mit Terminator
    printf("length: %d\n", length);
    copy = malloc(length);
    length = length - 1;

    int i = 0;
    for (i = 0; i < length; i++)
    {
        //copy[0]= org[5-0 = 5], copy[1]= org[5-1= 4] ... copy[5]=org[5-5=0]
        copy[i] = org[length - 1 - i];
    }
    copy[i] = '\0';
    return copy;
}
void nr_4()
{
    char *test;
    char *copy;
    printf("Bitte geben Sie etwas ein: ");
    test = readtext();
    copy = get_Mirrored(test);
    printf("Original: (%s, %p) \n", test, &test);
    printf("Copy: (%s, %p) \n", copy, &copy);
    free(test);
    free(copy);
}

char *ascii_mod(char *org, int index)
{
    char *copy;
    int length = 0;
    length = get_Length(org) + 1;
    copy = malloc(length);
    int i = 0;
    while (org[i] != '\0')
    {
        copy[i] = org[i] + index;
        i++;
    }

    copy[i] = '\0';
    return copy;
}

void nr_5()
{
    char *test;
    char *copy;
    int index;
    printf("Bitte geben Sie etwas ein: ");
    test = readtext();
    printf("Nun geben Sie eine Zahl ein:");
    scanf("%d", &index);
    copy = ascii_mod(test, index);
    printf("Original: (%s, %p) \n", test, &test);
    printf("Copy in %d Erhöhung in Ascii-Wert: (%s, %p) \n", index, copy, &copy);
    free(test);
    free(copy);
}

char *get_Palindrom(char *org)
{
    char *copy;
    int length = 0;
    int i = 0;
    int j = 0;

    length = (2 * get_Length(org)) + 1;
    copy = malloc(length);

    while (org[i] != '\0')
    {
        copy[i] = org[i];
        i++;
    }

    for (j = 0; j < org[j] != '\0'; j++)
    {
        //copy[0]= org[5-0 = 5], copy[1]= org[5-1= 4] ... copy[5]=org[5-5=0]
        copy[i + j] = org[i - 1 - j];
    }
    copy[i + j] = '\0';
    return copy;
}

void nr_6()
{
    char *test;
    char *copy;
    printf("Bitte geben Sie etwas ein: ");
    test = readtext();
    copy = get_Palindrom(test);
    printf("Original: (%s, %p) \n", test, &test);
    printf("Copy: (%s, %p) \n", copy, &copy);
    free(test);
    free(copy);
}
char *get_Consonant(char *org)
{
    char *copy;
    int length = 0;
    int i = 0;
    int j = 0;

    length = get_Length(org) + 1;
    copy = malloc(length);

    while (org[i] != '\0')
    {
        if (!(org[i] == 'A' || org[i] == 'a' || org[i] == 'E' || org[i] == 'e' || org[i] == 'I' || org[i] == 'i' || org[i] == 'O' || org[i] == 'o' || org[i] == 'U' || org[i] == 'u'))
        {
            copy[j] = org[i];
            j++;
        }
        i++;
    }

    copy[i] = '\0';
    return copy;
}
void nr_7()
{
    char *test;
    char *copy;
    printf("Bitte geben Sie etwas ein: ");
    test = readtext();
    copy = get_Consonant(test);
    printf("Original: (%s, %p) \n", test, &test);
    printf("Copy: (%s, %p) \n", copy, &copy);
    free(test);
    free(copy);
}
char *get_Capital(char *org)
{
    char *copy;
    int length = 0;
    int i = 0;

    length = get_Length(org) + 1;
    copy = malloc(length);

    while (org[i] != '\0')
    {
        if (org[i] >= 'a' && org[i] <= 'z')
        {
            copy[i] = org[i] - 32;
        }
        else
        {
            copy[i] = org[i];
        }
        i++;
    }

    copy[i] = '\0';
    return copy;
}

void nr_8()
{
    char *test;
    char *copy;
    printf("Bitte geben Sie etwas ein: ");
    test = readtext();
    copy = get_Capital(test);
    printf("Original: (%s, %p) \n", test, &test);
    printf("Copy: (%s, %p) \n", copy, &copy);
    free(test);
    free(copy);
}

char *get_Lower(char *org)
{
    char *copy;
    int length = 0;
    int i = 0;

    length = get_Length(org) + 1;
    copy = malloc(length);

    while (org[i] != '\0')
    {
        if (org[i] >= 'A' && org[i] <= 'Z')
        {
            copy[i] = org[i] + 32;
        }
        else
        {
            copy[i] = org[i];
        }
        i++;
    }

    copy[i] = '\0';
    return copy;
}

void nr_9()
{
    char *test;
    char *copy;
    printf("Bitte geben Sie etwas ein: ");
    test = readtext();
    copy = get_Lower(test);
    printf("Original: (%s, %p) \n", test, &test);
    printf("Copy: (%s, %p) \n", copy, &copy);
    free(test);
    free(copy);
}

char *get_rot13(char *org)
{
    char *copy;
    int length = 0;
    int i = 0;

    length = get_Length(org) + 1;
    copy = malloc(length);

    while (org[i] != '\0')
    {
        if (org[i] >= 'A' && org[i] < 'A' + 13 || org[i] >= 'a' && org[i] < 'a' + 13)
        {
            copy[i] = org[i] + 13;
        }
        else
        {
            copy[i] = org[i] - 13;
        }
        i++;
    }

    copy[i] = '\0';
    return copy;
}

void nr_10()
{
    char *test;
    char *copy;
    printf("Bitte geben Sie etwas ein: ");
    test = readtext();
    copy = get_rot13(test);
    printf("Original: (%s, %p) \n", test, &test);
    printf("Copy: (%s, %p) \n", copy, &copy);
    free(test);
    free(copy);
}
char *get_Caesar(char *org, int index)
{
    char *copy;
    int length = 0;
    int i = 0;

    index = index % 26; //Falls Index größer 26 ist
    length = get_Length(org) + 1;
    copy = malloc(length);

    while (org[i] != '\0')
    {
        if (org[i] >= 'A' && org[i] <= 'Z')
        {
            copy[i] = (org[i] - 65 + index) % 26 + 65;
        }
        else if (org[i] >= 'a' && org[i] <= 'z')
        {
            copy[i] = (org[i] - 97 + index) % 26 + 97;
        }
        i++;
    }

    copy[i] = '\0';
    return copy;
}
void nr_11()
{
    char *test;
    char *copy;
    int index;
    printf("Bitte geben Sie etwas ein: ");
    test = readtext();
    printf("Nun geben Sie eine Zahl ein: ");
    scanf("%d", &index);
    copy = get_Caesar(test, index);
    printf("Original: (%s, %p) \n", test, &test);
    printf("Copy: (%s, %p) \n", copy, &copy);
    free(test);
    free(copy);
}

int cmp_Strings(char *test1, char *test2)
{
    char *copy;
    int length = 0;
    int i = 0;

    //test1 > test2 : 1
    //test1 = test2 : 0
    //test1 < test2 : -1

    while (test1[i] != '\0' || test2[i] != '\0')
    {
        if (test1[i] != test2[i])
        {
            if (test1[i] > test2[i])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        i++;
    }
    // test1 zu Ende, test2 ist länger als test1
    if (test1[i] == '\0' && test2[i] != '\0')
    {
        return -1;
    }
    // test2 zu Ende, test1 ist länger als test1
    else if (test1[i] != '\0' && test2[i] == '\0')
    {
        return 1;
    }
    return 0;
}
void nr_12()
{
    char *test1;
    char *test2;
    int index;
    printf("Bitte geben Sie den 1. Text ein: ");
    test1 = readtext();
    printf("Bitte geben Sie den 2. Text ein: ");
    test2 = readtext();
    index = cmp_Strings(test1, test2);
    if (index == 1)
    {
        printf("Der 1. Text ist alphabetisch größer.\n");
    }
    else if (index == -1)
    {
        printf("Der 2. Text ist alphabetisch größer. \n");
    }
    else
    {
        printf("Die zwei Texte sind gleich! \n");
    }

    free(test1);
    free(test2);
}

char *concat_String(char *test1, char *test2)
{
    char *copy;
    int length1 = 0;
    int length2 = 0;
    int i = 0;
    int j = 0;
    int newLength = 0;
    length1 = get_Length(test1);
    length2 = get_Length(test2);
    newLength = length1 + length2 + 1;

    copy = malloc(newLength);

    for (i = 0; i < length1; i++)
    {
        copy[i] = test1[i];
    }
    for (j = 0; j < length2; j++)
    {
        copy[length1 + j] = test2[j];
    }

    copy[i + j] = '\0';

    return copy;
}
void nr_13()
{
    char *test1;
    char *test2;
    char *copy;
    int index;
    printf("Bitte geben Sie den 1. Text ein: ");
    test1 = readtext();
    printf("Bitte geben Sie den 2. Text ein: ");
    test2 = readtext();
    copy = concat_String(test1, test2);
    printf("Copy: (%s, %p) \n", copy, &copy);

    free(test1);
    free(test2);
    free(copy);
}

char *mix_String(char *test1, char *test2)
{
    char *copy;
    int i = 0;
    int j = 0;
    int k = 0;
    int length1, length2 = 0;
    int newLength = 0;
    length1 = get_Length(test1);
    length2 = get_Length(test2);
    newLength = length1 + length2 + 1;

    copy = malloc(newLength);

    while (test1[i] != '\0' || test2[j] != '\0')
    {
        if (test1[i] != '\0')
        {
            copy[k] = test1[i];
            k++;
            i++;
        }
        if (test2[j] != '\0')
        {
            copy[k] = test2[j];
            k++;
            j++;
        }
    }

    return copy;
}
void nr_14()
{
    char *test1;
    char *test2;
    char *copy;
    printf("Bitte geben Sie den 1. Text ein: ");
    test1 = readtext();
    printf("Bitte geben Sie den 2. Text ein: ");
    test2 = readtext();
    copy = mix_String(test1, test2);
    printf("Copy: (%s, %p) \n", copy, &copy);

    free(test1);
    free(test2);
    free(copy);
}
int find_String(char *text, char *word)
{
    int i = 0;
    int j = 0;

    while (text[i] != '\0')
    {
        if (text[i] == word[j])
        {
            i++;
            j++;
            if (word[j] == '\0')
            {
                return i - j;
            }
        }
        else
        {
            i++;
            j = 0;
        }
    }

    return -1;
}
void nr_15()
{
    char *test1;
    char *test2;
    int index;
    printf("Bitte geben Sie den 1. Text ein: ");
    test1 = readtext();
    printf("Bitte geben Sie den 2. Text ein: ");
    test2 = readtext();
    index = find_String(test1, test2);
    if (index == -1)
    {
        printf("Das Wort (%s) ist nicht im gegebenen Satz auffindbar\n", test2);
    }
    else
    {
        printf("Das Wort (%s) ist in %d. Position im gegebenen Satz.\n", test2, index);
    }

    free(test1);
    free(test2);
}

char *get_Part(char *test1, int index, int length)
{
    char *copy;
    copy = malloc(length + 1);
    int i = 0;
    for (i = 0; i < length; i++)
    {
        copy[i] = test1[index + i];
    }
    return copy;
}
void nr_16()
{
    char *test;
    char *copy;
    int index;
    int length;
    printf("Bitte geben Sie etwas ein: ");
    test = readtext();
    printf("Nun geben Sie die Anfangsposition ein: ");
    scanf("%d", &index);
    printf("Nun geben Sie die gewünschte Laenge ein: ");
    scanf("%d", &length);
    copy = get_Part(test, index, length);

    printf("Original: (%s, %p) \n", test, &test);
    printf("Copy: (%s, %p) \n", copy, &copy);
    free(test);
    free(copy);
}

int main()
{

    nr_16();

    return 0;
}