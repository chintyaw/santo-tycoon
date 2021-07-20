#ifndef _LISTI__
#define _LISTI__
#include "../boolean.h"
//#include "Inventory.h"

#define InitialSize 100
#define IdxUndef -999
#define ElmtL(L, i) (L).A[(i)].Nama
#define Jlh(L, i) (L).A[(i)].Jumlah
#define Neff(T) (T).Neff
//#define TI(T) (T).TI
#define MaxElL(T) (T).MaxElL

#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/
typedef struct {
    //int Nomor;
    const char *jenis; // kalo ini gabisa pake [100] nanTN delet aja.
    const char *Nama;
    int Jumlah;
    //int Harga;
} inventory;

typedef int IdxType;
// typedef int inventory;
typedef struct {
	inventory *A; /* memori tempat penyimpan elemen (container) */
	int Neff;   /* >=0, banyaknya elemen efektif */
	int MaxElL;
} List;

/**** PROPERTI Inventory ****/


/**** PROPERTI Build ****/
// typedef struct {
//     char component;
// } build;

/**** ARRAY Inventory ****/
typedef struct {
    inventory TN[50];
} TInventory;

/**** ARRAY Inventory ****/
/* typedef struct {
    build Tb[10];
} Tbuild;
*/

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(List *T, int maxel);
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */

void Dealokasi(List *T);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

IdxType GetFirstIdx(List T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(List T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
int NbElmtL(List T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Test tabel kosong *** */
boolean IsEmptyL(List T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
boolean IsFullL(List T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

void TulisIsiTab(List T);
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
void TulisIsiKomponen(List T);

IdxType Search1(List T, const char* X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB(List T, const char* X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

void AddAsLastEl(List *T, const char* X, char* jenis, int jumlah);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

void DelEl(List *T, const char *X);
/* Proses : Menghapus elemen  tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

void GrowTab(List *T, int num);
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

#endif
