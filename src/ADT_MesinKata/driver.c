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
    while (!cek)
    {
        printf("Masukkan Command = ");
        STARTCOMMAND();
        STARTWORD();
        // if (isLineCorrect(currentLine))
        // {
            cek = true;
            // STARTLINE("ConfigMakanan.txt");
            isLineCorrect(&arr[5]);

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