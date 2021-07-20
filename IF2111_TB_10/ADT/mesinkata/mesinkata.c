#include "mesinkata.h"
#include "../mesinkar/mesinkar.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;
char CC;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
    while ((CC == BLANK || CC == '\n')) {
        ADV();
    } /* CC != BLANK or CC = MARK */
}


void STARTKATA(){
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlank();
    EndKata = (CC == MARK);
    if (!EndKata) SalinKata();
}


void ADVKATA(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
    IgnoreBlank();
    EndKata = (CC == MARK);
    if (!EndKata) /* CC != MARK */ {
        SalinKata();
        IgnoreBlank();
    }
}

void SalinKata(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    CKata.Length = 0;
    while ((CC != MARK) && (CC != BLANK) && (CC != '\n')&& CKata.Length<NMax) {
        CKata.TabKata[CKata.Length] = CC;
        CKata.Length++;
        ADV();
    } /* CC = MARK or CC = BLANK */
}

void InputUser(Kata *k)
/* I.S Sembarang */
/* F.S Menginput masukan kata dari user dan menyimpannya di k */
{
    char c;
    int i=0;
    scanf("%c", &c);
    while(c != '\n'){
        (*k).TabKata[i] = c;
        ++i;
        scanf("%c", &c);
    }
    (*k).Length = i;
}

boolean IsKataSama(Kata k1, Kata k2)
/* Mengembalikan true jika k1 =  k2 */
{
    int i=1;
    if (k1.Length == k2.Length){
        while((i < k1.Length) && (k1.TabKata[i] == k2.TabKata[i])){
            i++;
        }
        return (k1.TabKata[i] == k2.TabKata[i]);
    } else{
        return (k1.Length == k2.Length);
    }
}

void CreateKata(char c[], Kata *k)
/* I.S string c[] terdefinisi, k sembarang */
/* F.S Mengkonversi bentuk string ke Kata K */
{
    int i = 0;
    while(c[i] != '\0'){
        (*k).TabKata[i] = c[i];
        ++i;
    }
    (*k).Length = 1;
}