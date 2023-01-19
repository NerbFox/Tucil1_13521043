/* File: string.h */
/* Implementasi ADT String */

#include "string.h"

boolean isWordSame(Word str1, char str2[])
{
    /* Mengembalikan true jika kedua kata sama dan false bila tidak */

    /* KAMUS */
    int i = 0;
    boolean same = (str1.Length != 0);

    /* ALGORITMA */
    while ((str1.String[i] != ENDSTRING || str2[i] != ENDSTRING) && same)
    {
        if (str1.String[i] != str2[i])
        {
            same = false;
        }
        else
        {
            i++;
        }
    }
    return same && str2[i] == ENDSTRING;
}

boolean isLineSame(Line l, char str2[])
{
    /* Mengembalikan true jika kedua kalimat sama dan false jika tidak (kalimat di sini berarti satu baris dengan spasi) */

    /* KAMUS */
    int i = 0;
    boolean same = (l.Length != 0);

    /* ALGORITMA */
    while ((l.Tabword[i] != ENDSTRING || str2[i] != ENDSTRING) && same)
    {
        if (l.Tabword[i] != str2[i])
        {
            same = false;
        }
        else
        {
            i++;
        }
    }

    return same;
}
void isLineCorrect(int (*arr)[])
{
    /* Mengembalikan true jika kedua kalimat sesuai dengan ketentuan permainan yakni terdiri dari
    A, J, Q, K, 1-10, dan false jika tidak (kalimat di sini berarti satu baris dengan spasi) */

    /* KAMUS */
    int i = 0, n = 0;
    // boolean sesuai = (l.Length != 0);
    (*arr)[4] = 1;

    /* ALGORITMA */
    while (n < 4)
    {
        // if (! (isWordSame(currentWord, 'A') || isWordSame(currentWord, 'K') || isWordSame(currentWord, 'Q') || isWordSame(currentWord, 'J') ||  ) ) {
        if (isWordSame(currentWord, "A"))
        {
            (*arr)[n] = 1;
            i++;
        }
        else if (isWordSame(currentWord, "J"))
        {
            (*arr)[n] = 11;
            i++;
        }
        else if (isWordSame(currentWord, "Q"))
        {
            (*arr)[n] = 12;
            i++;
        }
        else if (isWordSame(currentWord, "K"))
        {
            (*arr)[n] = 13;
            i++;
        }
        else if (isWordInt(currentWord))
        {
            (*arr)[n] = wordToInt(currentWord);
            i++;
            if (((*arr)[n] == 0))
            {
                (*arr)[4] = 0;
                i--;
            }
            else if (((*arr)[n] == 1))
            {
                (*arr)[4] = 0;
                i--;
            }
            else if (((*arr)[n] > 10))
            {
                (*arr)[4] = 0;
                i--;
            }
            // printf("i :  %d\n", i);
            // printf("arr :  %d\n", (*arr)[n]);
        }
        else
        {
            (*arr)[4] = 0;
        }
        ADVWORD();

        n++;
    }
    if (i != 4)
    {
        (*arr)[4] = 0;
    }
    // ADVWORD();
    // printf("end %d\n", currentWord.Length);
    // if lebih dari 4
    if (currentWord.Length != 0)
    {
        (*arr)[4] = 0;
    }
}

int wordToInt(Word cc)
{
    /* Mengembalikan integer dari suatu word */

    /* KAMUS */
    int i;
    int num = 0;
    int power = cc.Length - 1;

    /* ALGORTIMA */
    for (i = 0; i < cc.Length; i++)
    {
        num += ((int)cc.String[i] - 48) * pow(10, power);
        power--;
    }
    return num;
}

boolean isWordInt(Word cc)
{
    /* Mengembalikan true jika word merupakan integer dan false jika tidak */

    /* ALGORITMA */
    int i = 0;
    boolean isInt = true;
    while (cc.String[i] != '\0')
    {
        if (cc.String[i] < '0' || cc.String[i] > '9')
        {
            isInt = false;
        }
        i++;
    }
    return isInt;
}