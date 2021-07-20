// File : stack.h 
// stack dengan alokasi statik

#ifndef stacktI_H
#define stacktI_H

#include "../boolean.h"
#include <stdio.h>

// #define Nil 0
#define MaxElS 100
// Nil yaitu stack dengan elemen kosong 

// typedef int build;
typedef int addressS;   /* indeks tabel */
typedef struct 
{
  const char* T[MaxElS+1];
  addressS TOPS;
} Stack;

// stack S kosong : S.TOPS = Nil 
// Elemen penyimpaanan nilai Stack T[1]..T[MaxElS] 
// S.T[(S.TOPS)] untuk mengakses elemen TOPS 

// Definisi akses dengan Selektor : Set dan Get 
#define TOPS(S) (S).TOPS
#define InfoTOPS(S) (S).T[(S).TOPS]

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElS */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyS(Stack S);
/* Mengirim true jika Stack kosong*/

boolean IsFullS(Stack S);
/* Mengirim true jika stack S penuh */


/* ********** Operator Dasar Stack ********* */
void PushS(Stack *S, const char* X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOPS yang baru, TOPS bertambah 1 */

void PopS(Stack *S, const char* *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOPS yang lama, TOPS berkurang 1 */

void PrintStack (Stack S);

#endif
