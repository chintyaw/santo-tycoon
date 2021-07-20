#include <stdio.h>
#include "matriks.h"
#include <stdlib.h>
#include <math.h>

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M)=NB;
    NKolEff(*M)=NK;
    int i,j;
    for (i=1;i<=NB;i++){
    	for (j=1;j<=NK;j++){
    		Elmt(*M,i,j) = ' ';
		}
	}
}

/* ********** Assignment  MATRIKS ********** */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
    //kamus
    indeks i,j;
    //algoritma
    MakeMATRIKS(NB,NK,M);
    for (i=0;i<NB;i++){
        for(j=0;j<NK;j++){
            scanf("%c",&Elmt(*M,i,j));
        }
    }
}
void TulisMATRIKS (MATRIKS M, int NB, int NK, int absis, int kolom)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    //kamus
    indeks i,j;
    //algoritma
    for (i=1;i<=NK+2;i++) printf("*");
    printf("\n");
    for (i=1;i<=NB;i++){
    	printf("*");
        for(j=1;j<=NK;j++){
        	if (i == absis && j == kolom){
        		printf("P");
			}
			else {
				printf("%c",Elmt(M,i,j));
			}
        }
        printf("*\n");
    }
    for (i=1;i<=NK+2;i++) printf("*");
    printf("\n");
}