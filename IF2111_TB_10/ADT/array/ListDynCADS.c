#include <stdio.h>
#include <stdlib.h>
#include "ListDynCAD.h"

void MakeEmpty(List *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
    //kamus
    //algoritma
    MaxElL(*T)=maxel;
    (*T).A = (inventory *) malloc((MaxElL(*T)+1) * sizeof(inventory));
    Neff(*T)=0;
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
        	if ((T).A[i].jenis != "Build");
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
        while(ElmtL(T,i)!= X && i!=GetLastIdx(T)){
            i++;
        }
        if(ElmtL(T,i)== X){
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
            if(ElmtL(T,i)== X){
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

void GrowTab(List *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
    //algoritma
    MaxElL(*T)+=num;
    (*T).A = (inventory *) realloc((*T).A,MaxElL(*T)*sizeof(inventory));
}

int main (){
	List L;
	MakeEmpty(&L, 100);
}
