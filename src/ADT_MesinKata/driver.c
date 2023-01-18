#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.c"
#include "mesinkata.c"
#include "string.c"

int main()
{
    int a,b,c,d;
    int arr[5];
    boolean cek = false;
    arr[4]=0;
    while (!(arr[4]))
    {
        printf("Masukkan Command = ");
        STARTCOMMAND();
        STARTWORD();
        // if (isLineCorrect(currentLine))
        // {
            cek = true;
            // STARTLINE("ConfigMakanan.txt");
            isLineCorrect(&arr);
            printf("%d\n",arr[0]);
            printf("%d\n",arr[1]);
            printf("%d\n",arr[2]);
            printf("%d\n",arr[3]);
            printf("%d\n",arr[4]);

            // printf("%d\n", currentLength);
            // printf("%s\n", currentWord.String);
            // ADVWORD();
            // printf("%d\n", currentLength);
            // printf("%s\n", currentWord.String);
            // while (!EOP)
            // {
            //     ADVLINE();
            //     printf("%s\n", currentLine.Tabword);
            // }
        // }
        /* code */
    }

    return 0;
}