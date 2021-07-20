#include <stdio.h>
#include <stdlib.h>
#include "ListDynCAD.h"
#include "string.h"

void MakeEmpty(List *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
    //kamus
    //algoritma
    MaxElL(*T)=maxel;
    (*T).A = (inventory *) malloc((MaxElL(*T)+1) * sizeof(inventory));
    Neff(*T)=0;
    IdxType i;
    for (i=GetFirstIdx(*T);i<=maxel;i++){
    	ElmtL(*T, i) = "";
    	Jlh(*T, i) = 0;
	}
}

void Dealokasi(List *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    //kamus
    //algoritma
    free((*T).A);
    MaxElL(*T)=0;
    Neff(*T)=0;
}

int NbElmtL(List T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    //algoritma
    return Neff(T);
}

boolean IsEmptyL(List T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
    //algoritma
    return NbElmtL(T)==0;
}

boolean IsFullL(List T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    //algoritma
    return NbElmtL(T)==MaxElL(T);
}

IdxType GetFirstIdx(List T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    //algoritma
    return IdxMin;
}
IdxType GetLastIdx(List T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    //algoritma
    return NbElmtL(T);
}

void TulisIsiTab(List T)
{
    //kamus
    IdxType i;
    if(!IsEmptyL(T)){
        for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
        	// if (Jlh(T,i) > 0)
            printf("%d. %s (%d)\n", i, ElmtL(T,i), Jlh(T,i));
        }
    }
    else {
    	printf("Inventory kamu kosong!\n");
	}
}

void TulisIsiKomponen(List T)
{
    //kamus
    IdxType i;
    if(!IsEmptyL(T)){
        for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
        	if (strcmp((T).A[i].jenis,"Build") != 0 && Jlh(T,i) > 0);
            printf("%d. %s\n", i, ElmtL(T,i));
        }
    }
    else {
    	printf("Inventory kamu kosong!\n");
	}
}

IdxType SearchI(List T, const char* X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    //kamus
    IdxType i;
    //algoritma
    if(IsEmptyL(T)){
        return IdxUndef;
    } else {
        i=GetFirstIdx(T);
        while(strcmp(ElmtL(T,i),X) != 0 && i!=GetLastIdx(T)){
            i++;
        }
        if(strcmp(ElmtL(T,i),X) == 0){
            return i;
        } else{
            return IdxUndef;
        }
    }
}

boolean SearchB(List T, const char* X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
    //kamus
    IdxType i;
    boolean Found=false;
    //algoritma
    if(IsEmptyL(T)){
        return Found;
    } else {
        i=GetFirstIdx(T);
        while(i<=GetLastIdx(T)&&!Found){
            if( strcmp(ElmtL(T,i),X) == 0){
                Found=true;
            } else{
                 i++;
            }
        }
        return Found;
    }
}

void AddAsLastEl(List *T, const char* X, char* jenis, int jumlah)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    //algortima
    if (SearchB(*T, X)){
    	IdxType indeks = SearchI(*T, X);
    	Jlh(*T, indeks) += jumlah;
    	
	}
	else if (!IsFullL(*T)){
		ElmtL(*T,GetLastIdx(*T)+1) = X;
		Jlh(*T, GetLastIdx(*T)+1) += jumlah;
		(*T).A[GetLastIdx(*T)+1].jenis = jenis;
		Neff(*T)+=1;
	}
	else {
		GrowTab(T, 1);
		ElmtL(*T,GetLastIdx(*T)+1) = X;
		Jlh(*T, GetLastIdx(*T)+1) += jumlah;
		(*T).A[GetLastIdx(*T)+1].jenis = jenis;
		Neff(*T)+=1;
	}
}

void DelEl(List *T, const char* X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	IdxType indeks = SearchI(*T, X), i;
    if (indeks != -999){
        for(i=indeks;i<=GetLastIdx(*T)-1;i++){
            (*T).A[(i)]=(*T).A[(i+1)];
        }
        Jlh(*T ,GetLastIdx(*T)) = 0;
        Neff(*T)-=1;
    }
}

void GrowTab(List *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
    //algoritma
    MaxElL(*T)+=num;
    (*T).A = (inventory *) realloc((*T).A,MaxElL(*T)*sizeof(inventory));
}