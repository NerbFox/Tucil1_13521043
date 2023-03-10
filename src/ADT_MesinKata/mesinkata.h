/* File: mesinkata.h */
/* Definisi Mesin Kata */


#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkarakter.h"


typedef struct line
{
   str Tabword;
   int Length;
} Line;

typedef struct word
{
   str String; 
   int Length; 
} Word;


extern boolean endWord;
extern Word currentWord;
extern Line currentLine;
extern int currentLength;


void STARTLINE(char fileName[]);
    /* I.S. : currentChar sembarang, input nama file valid
       F.S. : currentChar = kata pertama dari baris berikutnya dan currentLine berisikan baris pertama yang telah diakuisisi */

void ADVLINE();
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentChar = kata pertama dari baris berikutnya dan currentLine berisikan baris yang telah diakuisi.
       Proses : Akuisisi baris menggunakan procedure CopyLine */

void CopyLine();
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentChar = kata pertama dari baris berikutnya dan currentLine berisikan baris yang telah diakuisi */

void STARTWORD();
    /* I.S. : CurrentLine terdefinisi
       F.S. : currentWord adalah kata pertama yang telah diakusisi */
void ignoreBlank();
void ADVWORD();
    /* I.S. : CurrentLine terdefinisi
       F.S. : currentWord adalah kata yang telah diakusisi dari currentLength sampai akhir kata (sebelum spasi atau akhir baris) */

void CopyWord();
    /* I.S. : CurrentLine terdefinisi
       F.S. : currentWord berisi word mulai dari currentLine.Tabword[currentLength] sampai endWord */

void STARTCOMMAND();
    /* I.S. : Sembarang
       F.S. : currentLine berisi masukan command dari user sampai sebelum new line (currentChar = '\n') */

void ADVCOMMAND();
    /* I.S. : Sembarang
       F.S  : karakter pada input command telah dimajukan satu karakter */

void CopyCommand();
    /* I.S. : Sembarang
       F.S. : Satu line/baris input command telah diakuisisi dan disimpan pada currentLine, currentChar == '\n' */

#endif