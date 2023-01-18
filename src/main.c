#include <stdio.h>
#include <string.h>

int main()
{
    // kamus
    char menu[3];

    printf("\n\n -------------------- Make It  24 -------------------- \n");

    // Menu
    printf("\n\nMain Menu\n");
    printf("1. Input 4 angka \n");
    printf("2. Generate 4 angka random \n");

    printf("Menu:  ");
    scanf("%c", &menu[0]);
    if (menu[0] == '1')
    {
        printf("\n-------------------- Menu 1 -------------------- \n");
        int i, m1, m2, m3, m4, n = 1;
        char masukan[n];
        for (i = 0; i < n; i++)
        {
            scanf("%c", &masukan[i]);
        }
        for (i = 0; i < n; i++)
        {
            printf("%d. %c\n", i, masukan[i]);
        }
        // while(1<(masukan-48)<=9)

        // penyimpanan file txt
    }
    else if (menu[0] == '2')
    {
        printf("\n-------------------- Menu 2 -------------------- \n");
    }
    else
    {
        printf("Masukan tidak sesuai\n");
    }

    printf("\n");
    printf("\n");

    return 0;
}