#include <stdio.h>
#include "ADT_MesinKata/boolean.h"
#include "ADT_MesinKata/mesinkarakter.c"
#include "ADT_MesinKata/mesinkata.c"
#include "ADT_MesinKata/string.c"

void menu()
{
    printf("\n\nMain Menu\n");
    printf("1. Input 4 numbers \n");
    printf("2. Generate 4 random numbers \n");
    printf("3. Exit \n");
    printf("Menu:  ");
    STARTCOMMAND();
    STARTWORD();
}

int main()
{
    // KAMUS
    // int a,b,c,d;
    int arr[5], n = 0;
    boolean cek = false;
    arr[4] = 0;

    printf("\n\n -------------------- Make It  24 -------------------- \n");

    // Menu
    menu();

    while (!(isWordSame(currentWord, "1") || isWordSame(currentWord, "2") || isWordSame(currentWord, "3")))
    {
        printf("\n---Masukan tidak sesuai---\n");
        menu();
    }

    if (isWordSame(currentWord, "1"))
    {
        printf("\nMenu 1\n");
        printf("Input = ");
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

        // menu 1
    }

    else if (isWordSame(currentWord, "2"))
    {
        printf("\nMenu 2\n");
        printf("Generate 4 numbers\n");
    }

    else
    {
        printf("\n ------------------- terima kasih ------------------- \n\n");
    }

    return 0;
}