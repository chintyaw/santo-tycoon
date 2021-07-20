#ifndef GRAF_H
#define GRAF_H

// #define Nil NULL

#include "../boolean.h"
#include "../matriks/matriks.h"

typedef struct tNode *adrNode;
typedef struct tSuccNode *adrSuccNode;
typedef struct tNode {
	int Id;
	adrSuccNode Trail;
	adrNode Next;
} Node;

typedef struct tSuccNode{
	int Succ;
	adrSuccNode Next;
} SuccNode;

typedef struct {
	adrNode First;
} Graph;

/* Selektor */
#define First(G) (G).First
#define Id(Pn) (Pn)->Id
#define Trail(Pn) (Pn)->Trail
#define Next(Pn) (Pn)->Next
#define Succ(Pt) (Pt)->Succ


void CreateGraph (int X, Graph *G);
// I.S. Sembarang; 
// F.S. Terbentuk Graph dengan satu simpul dengan Id=X

adrNode AlokNode (int X);
// Mengembalikan address hasil alokasi Simpul X.
//Jika alokasi berhasil, maka address tidak Nil, misalnya menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=Nil,
// dan Next(P)=Nil. Jika alokasi gagal, mengembalikan Nil.

void DealokNode (adrNode P);
// I.S. P terdefinisi; F.S. P dikembalikan ke sistem

//*** Manajemen Memory List Successor (Trailer) *** 
adrSuccNode AlokSuccNode (int Pn);
// Mengembalikan address hasil alokasi.
// Jika alokasi berhasil, maka address tidak Nil, misalnya menghasilkan Pt, maka Succ(Pt)=Pn dan Next(Pt)=Nil. 
// Jika alokasi gagal, mengembalikan Nil. 

void DealokSuccNode (adrSuccNode P);
// I.S. P terdefinisi; F.S. P dikembalikan ke sistem

void InsertNode (Graph *G, int X);
// Menambahkan simpul X ke dalam graph, jika alokasi X berhasil.
// I.S. G terdefinisi, X terdefinisi dan belum ada pada G.
// F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi
// address simpul X. Jika alokasi gagal, G tetap, Pn berisi Nil }

void InsertSuccNode (Graph *G, int X, int Y);
// memasukkan int Y ke Node ber-Id X

#endif
