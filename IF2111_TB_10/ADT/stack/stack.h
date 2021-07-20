// File : stack.h 
// stack dengan alokasi statik

#ifndef stackt_H
#define stackt_H

#include "../boolean.h"
#include <stdio.h>

// #define Nil 0
#define MaxEl 100
// Nil yaitu stack dengan elemen kosong 

typedef int infotype;
typedef int address;   /* indeks tabel */


typedef struct 
{
  infotype T[MaxEl+1];
  address TOP;
} Stack;

// stack S kosong : S.TOP = Nil 
// Elemen penyimpaanan nilai Stack T[1]..T[MaxEl] 
// S.T[(S.TOP)] untuk mengakses elemen TOP 

// Definisi akses dengan Selektor : Set dan Get 
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Stack S);
/* Mengirim true jika Stack kosong*/

boolean IsFull(Stack S);
/* Mengirim true jika stack S penuh */


/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */

void Pop(Stack *S, infotype *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif
