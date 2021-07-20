/* File: queue.h */

#ifndef queueM_H
#define queueM_H
// #include "startbuild.h"
#include "../boolean.h"
#include <stdlib.h>
#include <stdio.h>

/* Konstanta */
#define Nil -1

typedef struct {
    int NoPesanan;
    int Pelanggan;
    int Invoice;
    const char* Motherboard;
    const char* CPU;
    const char* Memory;
    const char* CPUCooler;
    const char* Case;
    const char* GPU;
    const char* Storage;
    const char* PSU;
}pesanan;

typedef struct {
    pesanan TB[100];
}tpesanan;

/* Definisi elemen dan addressP */

typedef int addressP; /* indeks tabel */
typedef struct {
    pesanan *T; /* tabel penyimpan elemen */
    addressP HEAD; /* alamat penghapusan */
    addressP TAIL; /* alamat penambahan */
    int MaxEl; /* Max elemen queue */
} Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */

/********** AKSES (Selektor) **********/
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

/********** Prototype **********/
boolean IsEmpty (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */

/*** Kreator ***/
void CreateEmpty (Queue *Q, int MaxEl);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi,Membuat sebuah Q kosong */

/*** Destruktor ***/
void DeAlokasi (Queue *Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/*** Primitif Add/Delete ***/
void Enqueue (Queue *Q, pesanan X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
void Dequeue (Queue *Q, pesanan *X);
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

pesanan Front (Queue Q);
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */

/*void CekOrder (Queue);*/
#endif
