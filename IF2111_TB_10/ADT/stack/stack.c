#include <stdio.h>
#include "stack.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
{
    Top(*S) = 0;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Stack S)
/* Mengirim true jika Stack kosong*/
{
    return Top(S) == 0;
}

boolean IsFull(Stack S)
/* Mengirim true jika stack S penuh */
{
    return Top(S) == MaxEl;
}

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
{
    if (!IsEmpty(*S)){
        Top(*S)++;
    }
    else{
        Top(*S) = 1;
    }
    InfoTop(*S) = X;
}

void Pop(Stack *S, infotype *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S)--;
}
