#include<stdio.h>
#include<stdlib.h>
#include "graf.h"

void CreateGraph (int X, Graph *G)
// I.S. Sembarang; 
// F.S. Terbentuk Graph dengan satu simpul dengan Id=X
{
	adrNode P = AlokNode(X);
	First(*G) = P;
}

adrNode AlokNode (int X)
// Mengembalikan address hasil alokasi Simpul X.
//Jika alokasi berhasil, maka address tidak NULL, misalnya menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=NULL,
// dan Next(P)=NULL. Jika alokasi gagal, mengembalikan NULL.
{
	adrNode P = (adrNode) malloc (sizeof(Node));
	if (P!=NULL){
		Id(P) = X;
		Trail(P) = NULL;
		Next(P) = NULL;
	}
	else P = NULL;
	return P;
}

void DealokNode (adrNode P)
// I.S. P terdefinisi; F.S. P dikembalikan ke sistem
{
	free(P);
}
//*** Manajemen Memory List Successor (Trailer) *** 
adrSuccNode AlokSuccNode (int Pn)
// Mengembalikan address hasil alokasi.
// Jika alokasi berhasil, maka address tidak NULL, misalnya menghasilkan Pt, maka Succ(Pt)=Pn dan Next(Pt)=NULL. 
// Jika alokasi gagal, mengembalikan NULL. 
{
	adrSuccNode Pt = (adrSuccNode) malloc (sizeof(Node));
	if (Pt!=NULL){
		Succ(Pt) = Pn;
		Next(Pt) = NULL;
	}
	else Pt = NULL;
	return Pt;
}

void DealokSuccNode (adrSuccNode P)
// I.S. P terdefinisi; F.S. P dikembalikan ke sistem
{
	free(P);
}

void InsertNode (Graph *G, int X)
// Menambahkan simpul X ke dalam graph, jika alokasi X berhasil.
// I.S. G terdefinisi, X terdefinisi dan belum ada pada G.
// F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi
// address simpul X. Jika alokasi gagal, G tetap, Pn berisi NULL }
{
	adrNode P = AlokNode(X);
	adrNode Pt = First(*G);
	
	if (P!=NULL){
		while (Next(Pt) != NULL) Pt = Next(Pt);
		Next(Pt) = P;
		Next(P) = NULL;
	}
}

void InsertSuccNode (Graph *G, int X, int Y)
// memasukkan int Y ke Node ber-Id X
{
	adrSuccNode P = AlokSuccNode(Y);
	adrNode Pt = First(*G);
	
	if (P!=NULL){
		while (Id(Pt) != X) Pt = Next(Pt);
		adrSuccNode PSucc = Trail(Pt);
		
		if (PSucc == NULL){
			Trail(Pt) = P;
		}
		else {
			while (Next(PSucc) != NULL) PSucc = Next(PSucc);
		
			Next(PSucc) = P;
			Next(P) = NULL;
		}
	}
}

void PrintGraph (Graph G) {
	adrNode P = First(G);
	while (P != NULL){
		printf("%d -> ", Id(P));
		adrSuccNode PSucc = Trail(P);
		while (PSucc != NULL){
			printf("%d ", Succ(PSucc));
			PSucc = Next(PSucc);
		}
		printf("\n");
		P = Next(P);
	}
}

void PrintAdj (adrNode P) {
	printf("Daftar lokasi yang dapat dicapai:\n");
	int i=1;
	adrSuccNode PSucc = Trail(P);
	while (PSucc != NULL){
			if (Succ(PSucc) == 1){
				printf("%d. Base\n", i);
				i+=1;
			}
			else if (Succ(PSucc) == 2){
				printf("%d. Shop\n", i);
				i+=1;
			}
			else {
				printf("%d. Pelanggan %d", i, Succ(PSucc)-2);
				i+=1;
			}
			
			PSucc = Next(PSucc);
		}
	printf("\n");
}
