
#include <stdio.h>
#include <stdlib.h>
#include "crop_newline.c"
#include "readtext.c"

int array_len(char *text)
{
    int i = 0;
    while (text[i] != '\0')
    {
        i++;
    }
    return i;
}

char *encrypt_text(char *text, char *pwd)
{
    int max = array_len(text);
    int i_pwd = array_len(pwd);
    char *copy = malloc(sizeof(char) * max);
    int i = 0;
    while (text[i] != '\0')
    {
        int curr_ind = 0;
        //if i == 6 and i_pwd == 5, der Wert von i_pwd[1] soll zu den ASCII Wert vom originalen Text addiert werden.
        curr_ind = i % i_pwd;
        if (pwd[curr_ind] >= '0' && pwd[curr_ind] <= '9')
        {
            copy[i] = text[i] + pwd[curr_ind] - '0';
        }
        else
        {
            copy[i] = text[i] + pwd[curr_ind];
        }
        i++;
    }
    return copy;
}

char *decrpyt_text(char *text, char *pwd)
{
    int max = array_len(text);
    int i_pwd = array_len(pwd);

    char *copy = malloc(sizeof(char) * max);
    int i = 0;
    while (text[i] != '\0')
    {
        int curr_ind = 0;
        //if i == 6 and i_pwd == 5, der Wert von i_pwd[1] soll von den ASCII Wert vom originalen Text abgezogen werden.
        curr_ind = i % i_pwd;
        if (pwd[curr_ind] >= '0' && pwd[curr_ind] <= '9')
        {
            copy[i] = text[i] - pwd[curr_ind] - '0';
        }
        else
        {
            copy[i] = text[i] - pwd[curr_ind];
        }
        i++;
    }
    return copy;
}

int str_compare(char *text, char *target)
{
    int i = 0;
    int j = 0;
    //"HALLO\0" / "ALP\0"
    while (text[i] != '\0')
    {
        if (text[i] == target[j])
        {
            i++;
            j++;
            if (target[j] == '\0')
            {
                return 1;
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
int pwd_compare(char *pwd_1, char *pwd_2)
{
    int len_pwd_1 = array_len(pwd_1);
    int len_pwd_2 = array_len(pwd_2);
    printf("password: %d\n", len_pwd_1);
    printf("password: %d\n", len_pwd_2);
    if (len_pwd_1 != len_pwd_2)
    {
        return -1;
    }
    int result = 0;
    result = str_compare(pwd_1, pwd_2);
    return result;
}
char *datei_lesen(char *data)
{
    char *new = malloc(sizeof(char *) * 100);
    printf("Data: %s", data);
    FILE *fp = fopen(data, "r");
    char zeichen;

    int anzahl = 0;

    if (fp == NULL)
    {
        fputs("Datei nicht gefunden!\n", stderr);
    }
    else
    {
        do
        {
            zeichen = fgetc(fp);
            new[anzahl] = zeichen;
            anzahl++;
        } while (zeichen != EOF); //End of File
    }

    new = realloc(new, anzahl - 1);
    return new;
}
int main(int argc, char **argv)
{
    int i;
    int err_det = 0; //if the value not found, will be below 1
    int e = 0;
    int d = 0;

    char *enc = "-e";
    char *enc_voll = "--encrypt";

    char *dec = "-d";
    char *dec_voll = "--decrypt";

    char *out = "-o";
    char *out_voll = "--output";

    char *txt = ".txt";
    char *data; //Name der Datei

    char *text_data; //Inhalt von der Datei
    char *encrypted_data;
    char *decrypted_data;
    char *passwort;

    char *temp_pwd_1;
    char *temp_pwd_2;

    for (i = 1; i < argc; i++)
    {

        if (e != 1)
        {
            if (str_compare(argv[i], enc) == 1 || str_compare(argv[i], enc_voll) == 1)
                e = 1;
        }
        if (d != 1)
        {
            if (str_compare(argv[i], dec) == 1 || str_compare(argv[i], dec_voll) == 1)
                d = 1;
        }

        if (err_det != 1)
        {
            if (str_compare(argv[i], out) == 1 || str_compare(argv[i], out_voll) == 1)
                err_det = 1;
        }

        if (str_compare(argv[i], txt) == 1)
        {
            data = argv[i];
        }
    }

    printf("err: %d\n", err_det);
    printf("e: %d\n", e);
    printf("d: %d\n", d);

    if (err_det <= 0 || (e == 1 && d == 1))
    {
        if (err_det <= 0)
            fputs("--output ist eine Pflichtangabe. Bitte starten Sie Ihren Programm neu.\n", stderr);
        if (e == 1 && d == 1)
            fputs("Encrypt und Decrypt können nicht gleichzeitig stattfinden.\n", stderr);
        return EXIT_FAILURE;
    }
    if (data != NULL)
    {

        text_data = datei_lesen(data);

        if (e == 1)
        {
            printf("Bitte geben Sie Ihren Passwort ein: \n");
            passwort = readtext();
            encrypted_data = encrypt_text(text_data, passwort);
            printf("original | pointer: %p | text: %s\n ", &text_data, text_data);
            printf("encrypted | pointer: %p | text: %s\n", &encrypted_data, encrypted_data);
        }

        if (d == 1)
        {
            passwort = "123";
            printf("Bitte geben Sie Ihren Passwort ein: \n");
            temp_pwd_1 = readtext();
            printf("Bitte geben Sie Ihren Passwort erneut ein: \n");
            temp_pwd_2 = readtext();

            if (pwd_compare(temp_pwd_1, temp_pwd_2) != 1)
            {
                fputs("Ihre Passworteingaben sind nicht identisch.\n", stderr);
                return EXIT_FAILURE;
            }
            else if (pwd_compare(temp_pwd_1, passwort) != 1)
            {
                fputs("Das von Ihnen Passwort ist ungültig.\n", stderr);
                return EXIT_FAILURE;
            }
            else
            {
                decrypted_data = decrpyt_text(encrypted_data, passwort);
                printf("original | pointer: %p | text: %s\n ", &text_data, text_data);
                printf("decrypted | pointer: %p | text: %s\n", &decrypted_data, decrypted_data);
            }
        }
    }

    return EXIT_SUCCESS;
}