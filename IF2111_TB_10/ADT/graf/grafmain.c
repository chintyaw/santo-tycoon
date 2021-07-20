#include <stdio.h>
#include <stdlib.h>
//#include "graf.c"
#include "ADT/graf/graf.h"
#include "ADT/mesinkar/mesinkar.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/matriks/matriks.h"
//#include "mesinkar.c"
//#include "mesinkata.c"
//#include "matriks.c"
#include "ADT/boolean.h"
#include "ADT/point/point.h"
//#include "point.c"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int toInt (Kata a){
	char s[] = "";
	int i=0;
	while (i < a.Length){
		strncat(s, &a.TabKata[i], 1);
		i += 1;
	}
		
	int val = atoi(s);
	return val;
}

int main(){
	POINT posisi;
	MATRIKS M;
    STARTKATA();
    int NB = toInt(CKata);
    ADVKATA();
    int NK = toInt(CKata);
    //printf("Baris = %d Kolom = %d\n", NB, NK);
    MakeMATRIKS (NB, NK, &M);
    ADVKATA();
    int bangunan = toInt(CKata);
    int cust = 0;
    //printf("Jumlah bangunan = %d\n", bangunan);
    ADVKATA();
    int i;
    for (i=0;i<bangunan;i++){
    	char jenis = CKata.TabKata[0];
    	//printf("%c ", jenis);
    	if (jenis == 'C'){
    		cust += 1;
    		jenis = cust + '0';
		}
    	ADVKATA();
    	int x = toInt (CKata);
    	//printf ("%d ", x);
    	ADVKATA();
    	int y = toInt (CKata);
    	//printf ("%d\n", y);
    	if (jenis == 'B'){
    		posisi = MakePOINT (x,y,'P');
		}
		
    	POINT P = MakePOINT (x,y,jenis);
    	Elmt(M,x,y) = P.jenis;
    	//TulisPOINT (P);
    	//printf("\n");
    	ADVKATA();
	}
    TulisMATRIKS (M, NB, NK, posisi.X, posisi.Y);
	//Graph
	Graph G;
	CreateGraph(1 ,&G);
	int j;
	for (i=2; i<=bangunan; i++)
		InsertNode(&G, i);
		
	for (i=1; i<=bangunan; i++){
		for (j=1; j<=bangunan; j++){
			if (CKata.TabKata[0] == '1') InsertSuccNode (&G, i, j);
			ADVKATA();
		}
	}
	
	/*********************************************************/
	/* MOVE */
	adrNode P = First(G);
	int posbangunan;
	if (Elmt(M,posisi.X,posisi.Y) == 'B'){
		printf("Kamu sedang berada di base.\n");
		posbangunan = 1;
	}
	else if (Elmt(M,posisi.X,posisi.Y) == 'B'){
		printf("Kamu sedang berada di shop.\n");
		posbangunan = 2;
	}
	else {
		posbangunan = (int)(Elmt(M,posisi.X,posisi.Y)) - (int)'0' + 2;
		printf("Kamu sedang berada di pelanggan %d.\n", posbangunan);
	}
	
	while (P != Nil && Id(P) != posbangunan ) {
		P = Next(P);
	}
	
	int adjlist[100];
	printf("Daftar lokasi yang dapat dicapai:\n");
	int l=1;
	adrSuccNode PSucc = Trail(P);
	while (PSucc != Nil){
			if (Succ(PSucc) == 1){
				printf("%d. Base\n", l);
				adjlist[l] = Succ(PSucc);
				l+=1;
			}
			else if (Succ(PSucc) == 2){
				printf("%d. Shop\n", l);
				adjlist[l] = Succ(PSucc);
				i+=1;
			}
			else {
				printf("%d. Pelanggan %d\n", l, Succ(PSucc)-2);
				adjlist[l] = Succ(PSucc); // yang dimasukkan ke array yang integernya (angka 3 berarti pelanggan 1)
				l+=1;
			}
			
			PSucc = Next(PSucc);
		}
	printf("\n");
	
	/* for (j=1;j<l;j++){
		printf("%d %d\n", j, adjlist[j]);
	} */
	int tujuan;
	printf("Nomor tujuan: ");
	scanf("%d", &tujuan);
	
	while (tujuan < 1 || tujuan >= l){
		printf("Tujuan tidak tersedia!\n");
		printf("Nomor tujuan: ");
		scanf("%d", &tujuan);
	}
	
	// tujuan adalah adjlist[tujuan].
	// adjlist[tujuan] = 3 pelanggan 1
	
	if (adjlist[tujuan] == 1) {
		printf("Kamu telah mencapai base!\n");
		for (i=1;i<=NB;i++){
			for (j=1;j<=NK;j++){
				if (Elmt(M,i,j) == 'B'){
					posisi = MakePOINT (i,j,'B');
				}
			}
		}
	}
	else if (adjlist[tujuan] == 2) {
		printf("Kamu telah mencapai shop!\n");
		for (i=1;i<=NB;i++){
			for (j=1;j<=NK;j++){
				if (Elmt(M,i,j) == 'S'){
					posisi = MakePOINT (i,j,'S');
				}
			}
		}
	}
	else {
		printf("Kamu telah mencapai lokasi Pelanggan %d!\n", adjlist[tujuan]-2);
		for (i=1;i<=NB;i++){
			for (j=1;j<=NK;j++){
				if (Elmt(M,i,j) == adjlist[tujuan]-2 + '0'){
					posisi = MakePOINT (i,j,'C');
				}
			}
		}
	}
	
	/*************************************************************/
	/* MAP */
	TulisMATRIKS (M, NB, NK, posisi.X, posisi.Y);
	
	/*************************************************************/
	//printf("Posisi: (%d,%d)\n", posisi.X,posisi.Y);
	//PrintGraph(G);
	return 0;
}
