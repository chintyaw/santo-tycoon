#include <stdio.h>
#include "stackI.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElS */
{
    TOPS(*S) = 0;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyS(Stack S)
/* Mengirim true jika Stack kosong*/
{
    return TOPS(S) == 0;
}

boolean IsFullS(Stack S)
/* Mengirim true jika stack S penuh */
{
    return TOPS(S) == MaxElS;
}



/* ********** Operator Dasar Stack ********* */
void PushS(Stack *S, const char* X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
{
    if (!IsEmptyS(*S)){
        TOPS(*S)++;
    }
    else{
        TOPS(*S) = 1;
    }
    InfoTOPS(*S) = X;
}

void PopS(Stack *S, const char* *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTOPS(*S);
    TOPS(*S)--;
}

void PrintStack (Stack S){
	int i;
    if (IsEmptyS(S)){
        printf("Belum ada komponen yang terpasang!\n");
    } else {
        for (i=1;i<=TOPS(S);i++){
		    printf("%d. %s\n", i, S.T[i]);
	    }
    }
}
