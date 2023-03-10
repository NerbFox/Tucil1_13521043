#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ADT_MesinKata/boolean.h"
#include "ADT_MesinKata/mesinkarakter.h"
#include "ADT_MesinKata/mesinkata.h"
#include "ADT_MesinKata/string.h"

#define maxHasil 700
#define maxStr 15
#define MILYAR 1000000000.0

void menu()
{
    printf("\n\n -------------------- Make It  24 -------------------- \n");
    printf("\nMain Menu\n");
    printf("1. Input 4 Cards\n");
    printf("2. Generate 4 Random Numbers\n");
    printf("3. Exit\n");
    printf("Menu:  ");
    STARTCOMMAND();
    STARTWORD();
}

boolean IsIn(int arr[4], int (*arrPermut)[maxHasil][4], int np)
{
    boolean found = false;
    int i = 0;
    while (!found && i < np + 1)
    {
        if ((*arrPermut)[i][0] == arr[0] && (*arrPermut)[i][1] == arr[1] && (*arrPermut)[i][2] == arr[2] && (*arrPermut)[i][3] == arr[3])
        {
            found = true;
        }
        i++;
    }
    return found;
}

boolean IsIn3(float arr[3], float(hasil3)[maxHasil][3], int np)
{
    boolean found = false;
    int i = 0;
    while (!found && i < np + 1)
    {
        if ((hasil3)[i][0] == arr[0] && (hasil3)[i][1] == arr[1])
        {
            found = true;
        }
        i++;
    }
    return found;
}

void save()
{
    printf("\nApakah Jawaban yang akan dihasilkan ingin disimpan dalam txt file? (y/n)\n");
    printf("Input: ");
    STARTCOMMAND();
    STARTWORD();
}

void fileName()
{
    printf("Nama File: ");
    STARTCOMMAND();
    STARTWORD();
    printf("\n");
}

float calculate(int a, char op, int b)
{
    float af = (float)a;
    if (op == '+')
    {
        return af + b;
    }
    else if (op == '-')
    {
        return af - b;
    }
    else if (op == '*')
    {
        return af * b;
    }
    else
    { // if (op=='/'){
        return af / b;
    }
}

void TwentyFourGSave(int number[4], char op[3], char (*hasil)[maxHasil][maxStr], float (*hasil3)[maxHasil][3], int *neff, FILE *FileCr)
{

    float a, b, c, d, e;
    char temp;
    float hasil3n[3];
    // ((n0+n1)+n2)+n3  (*hasil3)[*neff][0]
    (hasil3n)[0] = calculate(number[0], op[0], number[1]);
    (hasil3n)[1] = calculate((hasil3n)[0], op[1], number[2]);
    (hasil3n)[2] = calculate((hasil3n)[1], op[2], number[3]);
    a = (hasil3n)[2];
    if (a == 24.00)
    {
        fprintf(FileCr, "((%d%c%d)%c%d)%c%d\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*neff)++;
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = a;
    }

    // n0+((n1+n2)+n3)
    (hasil3n)[0] = calculate(number[1], op[1], number[2]);
    (hasil3n)[1] = calculate((hasil3n)[0], op[2], number[3]);
    (hasil3n)[2] = calculate(number[0], op[0], (hasil3n)[1]);
    b = (hasil3n)[2];
    if (b == 24.0)
    {
        fprintf(FileCr, "%d%c((%d%c%d)%c%d)\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*neff)++;
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = b;
    }

    // (n0+(n1+n2))+n3
    (hasil3n)[0] = calculate(number[1], op[1], number[2]);
    (hasil3n)[1] = calculate(number[0], op[0], (hasil3n)[0]);
    (hasil3n)[2] = calculate((hasil3n)[1], op[2], number[3]);
    c = (hasil3n)[2];
    if (c == 24.0)
    {
        fprintf(FileCr, "(%d%c(%d%c%d))%c%d\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*neff)++;
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = c;
    }

    // n0+(n1+(n2+n3))
    (hasil3n)[0] = calculate(number[2], op[2], number[3]);
    (hasil3n)[1] = calculate(number[1], op[1], (hasil3n)[0]);
    (hasil3n)[2] = calculate(number[0], op[0], (hasil3n)[1]);
    d = (hasil3n)[2];
    if (d == 24.00)
    {
        fprintf(FileCr, "%d%c(%d%c(%d%c%d))\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*neff)++;
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = d;
    }

    // (n0+n1)+(n2+n3)
    (hasil3n)[0] = calculate(number[2], op[2], number[3]);
    (hasil3n)[1] = calculate(number[0], op[0], number[1]);
    (hasil3n)[2] = calculate((hasil3n)[1], op[1], (hasil3n)[0]);
    e = (hasil3n)[2];
    if (e == 24.0)
    {
        fprintf(FileCr, "(%d%c%d)%c(%d%c%d)\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*neff)++;
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = e;
    }
}

void TwentyFourG(int number[4], char op[3], char (*hasil)[maxHasil][maxStr], float (*hasil3)[maxHasil][3], int *neff)
{
    float a, b, c, d, e;
    char temp;
    float hasil3n[3];
    // ((n0+n1)+n2)+n3  (*hasil3)[*neff][0]
    (hasil3n)[0] = calculate(number[0], op[0], number[1]);
    (hasil3n)[1] = calculate((hasil3n)[0], op[1], number[2]);
    (hasil3n)[2] = calculate((hasil3n)[1], op[2], number[3]);
    a = (hasil3n)[2];
    if (a == 24.00) // && ! IsIn3(hasil3n, *hasil3, *neff)
    {
        (*neff)++;
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = a;
        printf("((%d%c%d)%c%d)%c%d\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
    }

    // n0+((n1+n2)+n3)
    (hasil3n)[0] = calculate(number[1], op[1], number[2]);
    (hasil3n)[1] = calculate((hasil3n)[0], op[2], number[3]);
    (hasil3n)[2] = calculate(number[0], op[0], (hasil3n)[1]);
    b = (hasil3n)[2];
    if (b == 24.0)
    {
        printf("%d%c((%d%c%d)%c%d)\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*neff)++;
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = b;
    }

    // (n0+(n1+n2))+n3
    (hasil3n)[0] = calculate(number[1], op[1], number[2]);
    (hasil3n)[1] = calculate(number[0], op[0], (hasil3n)[0]);
    (hasil3n)[2] = calculate((hasil3n)[1], op[2], number[3]);
    c = (hasil3n)[2];
    if (c == 24.0)
    {
        printf("(%d%c(%d%c%d))%c%d\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*neff)++;
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = c;
    }

    // n0+(n1+(n2+n3))
    (hasil3n)[0] = calculate(number[2], op[2], number[3]);
    (hasil3n)[1] = calculate(number[1], op[1], (hasil3n)[0]);
    (hasil3n)[2] = calculate(number[0], op[0], (hasil3n)[1]);
    d = (hasil3n)[2];
    if (d == 24.00)
    {
        printf("%d%c(%d%c(%d%c%d))\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*neff)++;
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = d;
    }

    // (n0+n1)+(n2+n3)
    (hasil3n)[0] = calculate(number[2], op[2], number[3]);
    (hasil3n)[1] = calculate(number[0], op[0], number[1]);
    (hasil3n)[2] = calculate((hasil3n)[1], op[1], (hasil3n)[0]);
    e = (hasil3n)[2];
    if (e == 24.0)
    {
        (*neff)++;
        printf("(%d%c%d)%c(%d%c%d)\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = e;
    }
}

void TwentyFourSolutions(int number[4], char op[3], int *neff)
{
    float a, b, c, d, e;
    char temp;
    float hasil3n[3];
    // ((n0+n1)+n2)+n3  (*hasil3)[*neff][0]
    (hasil3n)[0] = calculate(number[0], op[0], number[1]);
    (hasil3n)[1] = calculate((hasil3n)[0], op[1], number[2]);
    (hasil3n)[2] = calculate((hasil3n)[1], op[2], number[3]);
    a = (hasil3n)[2];
    if (a == 24.00)
    {
        (*neff)++;
    }

    // n0+((n1+n2)+n3)
    (hasil3n)[0] = calculate(number[1], op[1], number[2]);
    (hasil3n)[1] = calculate((hasil3n)[0], op[2], number[3]);
    (hasil3n)[2] = calculate(number[0], op[0], (hasil3n)[1]);
    b = (hasil3n)[2];
    if (b == 24.0)
    {
        (*neff)++;
    }

    // (n0+(n1+n2))+n3
    (hasil3n)[0] = calculate(number[1], op[1], number[2]);
    (hasil3n)[1] = calculate(number[0], op[0], (hasil3n)[0]);
    (hasil3n)[2] = calculate((hasil3n)[1], op[2], number[3]);
    c = (hasil3n)[2];
    if (c == 24.0)
    {
        (*neff)++;
    }

    // n0+(n1+(n2+n3))
    (hasil3n)[0] = calculate(number[2], op[2], number[3]);
    (hasil3n)[1] = calculate(number[1], op[1], (hasil3n)[0]);
    (hasil3n)[2] = calculate(number[0], op[0], (hasil3n)[1]);
    d = (hasil3n)[2];
    if (d == 24.00)
    {
        (*neff)++;
    }

    // (n0+n1)+(n2+n3)
    (hasil3n)[0] = calculate(number[2], op[2], number[3]);
    (hasil3n)[1] = calculate(number[0], op[0], number[1]);
    (hasil3n)[2] = calculate((hasil3n)[1], op[1], (hasil3n)[0]);
    e = (hasil3n)[2];
    if (e == 24.0)
    {
        (*neff)++;
    }
}

void TwentyFourData(int number[4], char op[3], char (*hasil)[maxHasil][maxStr], float (*hasil3)[maxHasil][3], int *neff)
{
    float a, b, c, d, e;
    char temp;
    float hasil3n[3];
    // ((n0+n1)+n2)+n3  (*hasil3)[*neff][0]
    (hasil3n)[0] = calculate(number[0], op[0], number[1]);
    (hasil3n)[1] = calculate((hasil3n)[0], op[1], number[2]);
    (hasil3n)[2] = calculate((hasil3n)[1], op[2], number[3]);
    a = (hasil3n)[2];
    if (a == 24.00)
    {
        printf("((%d%c%d)%c%d)%c%d\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*neff)++;
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = a;
        // printf("nef %d\n", *neff);
        temp = '(';
        strncat((*hasil)[*neff], &temp, 1);
        strncat((*hasil)[*neff], &temp, 1);
        if (number[0] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[0] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[0] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        strncat((*hasil)[*neff], &(op[0]), 1);
        if (number[1] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[1] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[1] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        temp = ')';
        strncat((*hasil)[*neff], &temp, 1);
        strncat((*hasil)[*neff], &(op[1]), 1);
        if (number[2] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[2] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[2] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        temp = ')';
        strncat((*hasil)[*neff], &temp, 1);
        strncat((*hasil)[*neff], &(op[2]), 1);
        if (number[3] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[3] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[3] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
    }

    // n0+((n1+n2)+n3)
    (hasil3n)[0] = calculate(number[1], op[1], number[2]);
    (hasil3n)[1] = calculate((hasil3n)[0], op[2], number[3]);
    (hasil3n)[2] = calculate(number[0], op[0], (hasil3n)[1]);
    b = (hasil3n)[2];
    if (b == 24.0)
    {
        printf("%d%c((%d%c%d)%c%d)\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*neff)++;
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = b;
        // printf("nefoo %d\n", *neff);
        if (number[0] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[0] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[0] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        strncat((*hasil)[*neff], &(op[0]), 1);
        temp = '(';
        strncat((*hasil)[*neff], &temp, 1);
        strncat((*hasil)[*neff], &temp, 1);
        if (number[1] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[1] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[1] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        strncat((*hasil)[*neff], &(op[1]), 1);
        if (number[2] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[2] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[2] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        temp = ')';
        strncat((*hasil)[*neff], &temp, 1);
        strncat((*hasil)[*neff], &(op[2]), 1);
        if (number[3] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[3] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[3] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        temp = ')';
        strncat((*hasil)[*neff], &temp, 1);
    }

    // (n0+(n1+n2))+n3
    (hasil3n)[0] = calculate(number[1], op[1], number[2]);
    (hasil3n)[1] = calculate(number[0], op[0], (hasil3n)[0]);
    (hasil3n)[2] = calculate((hasil3n)[1], op[2], number[3]);
    c = (hasil3n)[2];
    if (c == 24.0)
    {
        printf("(%d%c(%d%c%d))%c%d\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*neff)++;
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = c;
        // printf("nefi %d\n", *neff);
        temp = '(';
        strncat(((*hasil))[*neff], &temp, 1);
        if (number[0] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[0] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[0] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        strncat((*hasil)[*neff], &(op[0]), 1);
        temp = '(';
        strncat((*hasil)[*neff], &temp, 1);
        if (number[1] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[1] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[1] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        strncat((*hasil)[*neff], &(op[1]), 1);
        if (number[2] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[2] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[2] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        temp = ')';
        strncat((*hasil)[*neff], &temp, 1);
        strncat((*hasil)[*neff], &temp, 1);
        strncat((*hasil)[*neff], &(op[2]), 1);
        if (number[3] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[3] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[3] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
    }

    // n0+(n1+(n2+n3))
    (hasil3n)[0] = calculate(number[2], op[2], number[3]);
    (hasil3n)[1] = calculate(number[1], op[1], (hasil3n)[0]);
    (hasil3n)[2] = calculate(number[0], op[0], (hasil3n)[1]);
    d = (hasil3n)[2];
    if (d == 24.00)
    {
        printf("%d%c(%d%c(%d%c%d))\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*neff)++;
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = d;
        // printf("nefoo %d\n", *neff);
        if (number[0] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[0] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[0] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        strncat((*hasil)[*neff], &(op[0]), 1);
        temp = '(';
        strncat((*hasil)[*neff], &temp, 1);
        if (number[1] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[1] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[1] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        strncat((*hasil)[*neff], &(op[1]), 1);
        temp = '(';
        strncat((*hasil)[*neff], &temp, 1);
        if (number[2] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[2] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[2] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        strncat((*hasil)[*neff], &(op[2]), 1);
        if (number[3] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[3] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[3] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        temp = ')';
        strncat((*hasil)[*neff], &temp, 1);
        strncat((*hasil)[*neff], &temp, 1);
    }

    // (n0+n1)+(n2+n3)
    (hasil3n)[0] = calculate(number[2], op[2], number[3]);
    (hasil3n)[1] = calculate(number[0], op[0], number[1]);
    (hasil3n)[2] = calculate((hasil3n)[1], op[1], (hasil3n)[0]);
    e = (hasil3n)[2];
    if (e == 24.0)
    {
        (*neff)++;
        printf("(%d%c%d)%c(%d%c%d)\n", number[0], op[0], number[1], op[1], number[2], op[2], number[3]);
        (*hasil3)[*neff][0] = hasil3n[0];
        (*hasil3)[*neff][1] = hasil3n[1];
        (*hasil3)[*neff][2] = e;
        // printf("nefoo %d\n", *neff);
        temp = '(';
        // (*hasil)[*neff][0]='(';
        // (*hasil)[*neff][0]='(';
        strncat((*hasil)[*neff], &temp, 1);
        if (number[0] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[0] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[0] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        strncat((*hasil)[*neff], &(op[0]), 1);
        if (number[1] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[1] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[1] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        temp = ')';
        strncat((*hasil)[*neff], &temp, 1);
        strncat((*hasil)[*neff], &(op[1]), 1);
        temp = '(';
        strncat((*hasil)[*neff], &temp, 1);
        if (number[2] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[2] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[2] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        strncat((*hasil)[*neff], &(op[2]), 1);
        if (number[3] > 9)
        {
            temp = '1';
            strncat((*hasil)[*neff], &temp, 1);
            temp = number[3] % 10 + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        else
        {
            temp = number[3] + 48;
            strncat((*hasil)[*neff], &temp, 1);
        }
        temp = ')';
        strncat((*hasil)[*neff], &temp, 1);
    }
}

int main()
{
    // KAMUS
    int arr[5], n = 0, i, j, k, l, ni, z, i1, i2, i3, np;
    arr[4] = 0;
    int atas = 13, bawah = 1;
    float TwentyFour = 24.0;
    char Hasil[maxHasil][maxStr];
    int neff = -1;
    char Op[4] = {'+', '-', '*', '/'};
    char OpHasil[3];
    int arrHasil[4];
    int arrPermut[maxHasil][4];
    float hasil3[maxHasil][3];
    char endOfStr = '\0';
    boolean cek = false;
    boolean simpan = false;
    struct timespec awal, akhir;
    double waktu;

    // char FiName[100];
    char ResultName[100] = "../doc/Hasil/";
    char typeName[] = ".txt";
    char *FileName;
    FILE *FileCr;

    // Menu
    menu();

    while (!(isWordSame(currentWord, "3")))
    {
        n = 0;
        arr[4] = 0;
        TwentyFour = 24.0;
        neff = -1;
        np = -1;
        endOfStr = '\0';
        cek = false;
        simpan = false;

        while (!(isWordSame(currentWord, "1") || isWordSame(currentWord, "2") || isWordSame(currentWord, "3")))
        {
            printf("\n---Masukan tidak sesuai---\n");
            menu();
        }

        if (isWordSame(currentWord, "1"))
        {
            printf("\nMenu 1\n");
            printf("Make it 24 with Cards : A,2,3,4,5,6,7,8,9,10,J,K,Q\n");
            printf("Input 4 Cards = ");
            STARTCOMMAND();
            STARTWORD();
            isLineCorrect(&arr);

            while (!(arr[4]))
            {
                printf("\n---Masukan tidak sesuai---\n");
                printf("Input = ");
                STARTCOMMAND();
                STARTWORD();
                isLineCorrect(&arr);
                // printf("%d\n",arr[0]);
                // printf("%d\n",arr[1]);
                // printf("%d\n",arr[2]);
                // printf("%d\n",arr[3]);
                // printf("%d\n",arr[4]);
            }
        }
        else
        {
            printf("\nMenu 2\n");
            printf("Generate 4 numbers\n");
            for (i = 0; i < 4; i++)
            {
                arr[i] = (rand() % (atas - bawah + 1)) + bawah;
            }
            printf("4 random numbers: %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
        }

        // Program Utama Brute Force
        // waktu mulai
        clock_gettime(CLOCK_REALTIME, &awal);
        // Permurtasi 4 angka dengan i,j,k,l dan beberapa kondisi
        ni = 1;
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (j != i)
                {
                    for (k = 0; k < 4; k++)
                    {
                        if (k != i && k != j)
                        {
                            for (l = 0; l < 4; l++)
                            {
                                if (l != i && l != j && l != k)
                                {
                                    arrHasil[0] = arr[i];
                                    arrHasil[1] = arr[j];
                                    arrHasil[2] = arr[k];
                                    arrHasil[3] = arr[l];

                                    if (!IsIn(arrHasil, &arrPermut, np))
                                    {
                                        np++;
                                        arrPermut[np][0] = arrHasil[i];
                                        arrPermut[np][1] = arrHasil[j];
                                        arrPermut[np][2] = arrHasil[k];
                                        arrPermut[np][3] = arrHasil[l];

                                        // Kombinasi, 3 dari 4 buah operasi
                                        for (i1 = 0; i1 < 4; i1++)
                                        {
                                            for (i2 = 0; i2 < 4; i2++)
                                            {
                                                for (i3 = 0; i3 < 4; i3++)
                                                {
                                                    OpHasil[0] = Op[i1];
                                                    OpHasil[1] = Op[i2];
                                                    OpHasil[2] = Op[i3];
                                                    TwentyFourSolutions(arrHasil, OpHasil, &neff);
                                                    ni++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        // waktu selesai
        clock_gettime(CLOCK_REALTIME, &akhir);
        if (neff != -1)
        {
            if (neff == 0)
            {
                printf("\n%d solution found\n", neff + 1);
            }
            else
            {
                printf("\n%d solutions found\n", neff + 1);
            }
        }
        else
        {
            printf("\nNo solutions found\n");
        }

        // Program untuk Menampilkan solusi ke layar
        n = 0;
        neff = -1;
        np = -1;
        ni = 1;
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (j != i)
                {
                    for (k = 0; k < 4; k++)
                    {
                        if (k != i && k != j)
                        {
                            for (l = 0; l < 4; l++)
                            {
                                if (l != i && l != j && l != k)
                                {
                                    arrHasil[0] = arr[i];
                                    arrHasil[1] = arr[j];
                                    arrHasil[2] = arr[k];
                                    arrHasil[3] = arr[l];

                                    if (!IsIn(arrHasil, &arrPermut, np))
                                    {
                                        np++;
                                        arrPermut[np][0] = arrHasil[i];
                                        arrPermut[np][1] = arrHasil[j];
                                        arrPermut[np][2] = arrHasil[k];
                                        arrPermut[np][3] = arrHasil[l];

                                        // printf("ni = %d\n", ni);
                                        // printf("%d %d %d %d", arrHasil[0], arrHasil[1],  arrHasil[2],  arrHasil[3]);
                                        // printf("\n");

                                        // for (z=0; z<4 ; z++){
                                        //     printf("%d ", arrHasil[z]);
                                        // }

                                        // Kombinasi, 3 dari 4 buah operasi
                                        for (i1 = 0; i1 < 4; i1++)
                                        {
                                            for (i2 = 0; i2 < 4; i2++)
                                            {
                                                for (i3 = 0; i3 < 4; i3++)
                                                {
                                                    OpHasil[0] = Op[i1];
                                                    OpHasil[1] = Op[i2];
                                                    OpHasil[2] = Op[i3];
                                                    // printf("ni = %d\n", ni);
                                                    // printf("%d %d %d %d", arrHasil[0], arrHasil[1],  arrHasil[2],  arrHasil[3]);
                                                    // printf("\n");
                                                    // printf("Op\n");
                                                    // printf("%c %c %c", OpHasil[0], OpHasil[1],  OpHasil[2]);
                                                    TwentyFourG(arrHasil, OpHasil, &Hasil, &hasil3, &neff);
                                                    ni++;
                                                    // printf("\n\n Total kemungkinan kombinasi dari Op dan permutasi dari numbers : %d\n", ni);`
                                                    // printf("\n\n");
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // Program untuk menyimpan solusi jika diinginkan
        save();
        if (isWordSame(currentWord, "y"))
        {
            simpan = true;
        }
        if (simpan)
        {
            fileName();
            strcat(ResultName, currentWord.String);
            strcat(ResultName, typeName);
            // printf("%s", ResultName);

            FileName = ResultName;
            FileCr = fopen(FileName, "w");
            if (FileCr == NULL)
            {
                printf("Gagal membuat file %s", FileName);
                return -1;
            }

            fprintf(FileCr, "Hasil Semua Solusi\n");
            fprintf(FileCr, "Input numbers: %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);

            n = 0;
            neff = -1;
            np = -1;
            ni = 1;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    if (j != i)
                    {
                        for (k = 0; k < 4; k++)
                        {
                            if (k != i && k != j)
                            {
                                for (l = 0; l < 4; l++)
                                {
                                    if (l != i && l != j && l != k)
                                    {
                                        arrHasil[0] = arr[i];
                                        arrHasil[1] = arr[j];
                                        arrHasil[2] = arr[k];
                                        arrHasil[3] = arr[l];

                                        if (!IsIn(arrHasil, &arrPermut, np))
                                        {
                                            np++;
                                            arrPermut[np][0] = arrHasil[i];
                                            arrPermut[np][1] = arrHasil[j];
                                            arrPermut[np][2] = arrHasil[k];
                                            arrPermut[np][3] = arrHasil[l];

                                            // printf("ni = %d\n", ni);
                                            // printf("%d %d %d %d", arrHasil[0], arrHasil[1],  arrHasil[2],  arrHasil[3]);
                                            // printf("\n");

                                            // for (z=0; z<4 ; z++){
                                            //     printf("%d ", arrHasil[z]);
                                            // }

                                            // Kombinasi, 3 dari 4 buah operasi
                                            for (i1 = 0; i1 < 4; i1++)
                                            {
                                                for (i2 = 0; i2 < 4; i2++)
                                                {
                                                    for (i3 = 0; i3 < 4; i3++)
                                                    {
                                                        OpHasil[0] = Op[i1];
                                                        OpHasil[1] = Op[i2];
                                                        OpHasil[2] = Op[i3];
                                                        // printf("ni = %d\n", ni);
                                                        // printf("%d %d %d %d", arrHasil[0], arrHasil[1],  arrHasil[2],  arrHasil[3]);
                                                        // printf("\n");
                                                        // printf("Op\n");
                                                        // printf("%c %c %c", OpHasil[0], OpHasil[1],  OpHasil[2]);
                                                        TwentyFourGSave(arrHasil, OpHasil, &Hasil, &hasil3, &neff, FileCr);
                                                        ni++;
                                                        // printf("\n\n Total kemungkinan kombinasi dari Op dan permutasi dari numbers : %d\n", ni);`
                                                        // printf("\n\n");
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            // Menutup file
            fclose(FileCr);
            printf("File tersimpan\n");
        }

        waktu = (akhir.tv_sec - awal.tv_sec) + (akhir.tv_nsec - awal.tv_nsec) / MILYAR;
        printf("Waktu Eksekusi: %f seconds\n", (waktu));

        // for (i = 0; i < np + 1; i++)
        // {
        //     printf("%d.", i);
        //     for (j = 0; j < 4; j++)
        //     {
        //         printf(" %d", arrPermut[i][j]);
        //     }
        //     printf("\n");
        // }

        // for (i = 0; i < neff + 1; i++)
        // {
        //     printf("%d.", i);
        //     for (j = 0; j < 3; j++)
        //     {
        //         printf(" %.2f", hasil3[i][j]);
        //     }
        //     printf("\n");
        // }

        // Menu
        // menu();
        printf("type '0' (Main Menu) and '3' (exit) : ");
        STARTCOMMAND();
        STARTWORD();
        if (isWordSame(currentWord, "0"))
        {
            menu();
        }
    }

    printf("\n ------------------- terima kasih ------------------- \n\n");
    return 0;
}