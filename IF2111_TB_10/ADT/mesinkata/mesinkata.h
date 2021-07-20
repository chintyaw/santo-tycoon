#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "../mesinkar/mesinkar.h"

#define NMax 50
#define BLANK ' '

typedef struct {
  char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA();
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void InputUser(Kata *k);
/* I.S Sembarang */
/* F.S Menginput masukan kata dari user dan menyumpannya di k */

boolean IsKataSama(Kata k1, Kata k2);
/* Mengembalikan true jika k1 =  k2 */

void CreateKata(char c[], Kata *k);
/* I.S string c[] terdefinisi, k sembarang */
/* F.S Mengkonversi bentuk string ke Kata K */
#endif
