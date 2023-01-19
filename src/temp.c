#include <stdio.h>
#include <string.h>

int main()
{
    char menu[2];
    // scanf("%c", &menu[0]);
    if (1)
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