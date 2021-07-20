#include "ADT/mesinkar/mesinkar.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/matriks/matriks.h"
#include "ADT/mesinkar/mesinkar.c"
#include "ADT/mesinkata/mesinkata.c"
#include "ADT/matriks/matriks.c"
#include "ADT/boolean.h"
#include "ADT/point/point.h"
#include "ADT/point/point.c"
#include <stdio.h>
#include <stdlib.h>

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
    	POINT P = MakePOINT (x,y,jenis);
    	M.Mem[x][y] = P.jenis;
    	//TulisPOINT (P);
    	//printf("\n");
    	ADVKATA();
	}
    
    TulisMATRIKS (M, NB, NK);
    return 0;
}

