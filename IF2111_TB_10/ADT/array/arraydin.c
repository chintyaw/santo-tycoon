/* File : arraydin.c */
/* Body ADT array dinamis */
#include <stdio.h>
#include "ADT/array/arraydin.h"
#include <stdlib.h>
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
    //kamus
    //algoritma
    MaxEl(*T)=maxel;
    TI(*T)= (int *) malloc((MaxEl(*T)+1) * sizeof(int));
    Neff(*T)=0;
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    //kamus
    //algoritma
    free(TI(*T));
    MaxEl(*T)=0;
    Neff(*T)=0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    //algoritma
    return Neff(T);
}
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    //algoritma
    return MaxEl(T);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    //algoritma
    return IdxMin;
}
IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    //algoritma
    return NbElmt(T);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    //algoritma
    return i>=IdxMin&&i<=MaxElement(T);
}
boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    //algoritma
    return i>=GetFirstIdx(T)&&i<=GetLastIdx(T);
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
    //algoritma
    return NbElmt(T)==0;
}
boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    //algoritma
    return NbElmt(T)==MaxElement(T);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    //kamus
    IdxType n,i;
    ElType x;
    //algoritma
    do{
        scanf("%d",&n);
    } while (n<0||n>MaxElement(*T));
    if(n!=0){
        for (i=GetFirstIdx(*T);i<=n;i++){
            scanf("%d",&x);
            Elmt(*T,i)=x;
        }
        Neff(*T)=n;
    }
}
void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    //kamus
    IdxType i;
    //kamus
    printf("[");
    if(!IsEmpty(T)){
        for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
            printf("%d",Elmt(T,i));
            if(i!=GetLastIdx(T)){
                printf(",");
            }
        }
    }
    printf("]");
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    //kamus
    TabInt T3;
    IdxType i;
    //algoritma
    MakeEmpty(&T3,MaxEl(T1));
    if(plus){
        for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++){
            Elmt(T3,i)=Elmt(T1,i)+Elmt(T2,i);
        }
    }else {
        for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++){
            Elmt(T3,i)=Elmt(T1,i)-Elmt(T2,i);
        }
    }
    Neff(T3)=Neff(T2);
    return T3;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
    //kamus
    IdxType i;
    boolean cek=true;
    //algoritma
    if(Neff(T1)!=Neff(T2)){
        return false;
    } else if(IsEmpty(T1)&&IsEmpty(T2)){
        return cek;
    }else {
        i = GetFirstIdx(T1);
        while((Elmt(T1,i) == Elmt(T2,i)) && (i<GetLastIdx(T1))){
            i++;
        }
        if(Elmt(T1,i) != Elmt(T2,i)){
            cek = false;
        }
        return cek;
    }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    //kamus
    IdxType i;
    //algoritma
    if(IsEmpty(T)){
        return IdxUndef;
    } else {
        i=GetFirstIdx(T);
        while(Elmt(T,i)!=X && i!=GetLastIdx(T)){
            i++;
        }
        if(Elmt(T,i)==X){
            return i;
        } else{
            return IdxUndef;
        }
    }
}
boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
    //kamus
    IdxType i;
    boolean Found=false;
    //algoritma
    if(IsEmpty(T)){
        return Found;
    } else {
        i=GetFirstIdx(T);
        while(i<=GetLastIdx(T)&&!Found){
            if(Elmt(T,i)==X){
                Found=true;
            } else{
                 i++;
            }
        }
        return Found;
    }
}
/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    //kamus
    IdxType i;
    //algoritma
    *Max=Elmt(T,GetFirstIdx(T));
    *Min=Elmt(T,GetFirstIdx(T));
    for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
        if(*Max<Elmt(T,i)){
            *Max=Elmt(T,i);
        }
        if(*Min>Elmt(T,i)){
            *Min=Elmt(T,i);
        }
    }
}
/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
    //kamus
    IdxType i;
    //algoritma
    MakeEmpty(Tout,MaxEl(Tin));
    for(i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++){
        Elmt(*Tout,i)=Elmt(Tin,i);
    }
    Neff(*Tout)=Neff(Tin);
}
ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
    //kamus
    ElType hasil=0;
    IdxType i;
    //algoritma
    if(!IsEmpty(T)){
        for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
            hasil+=Elmt(T,i);
        }
    }
    return hasil;
}   
int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
    //kamus
    int count=0;
    IdxType i;
    if(!IsEmpty(T)){
        for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
            if(X==Elmt(T,i)){
                count++;
            }
        }
    }
    return count;
}
boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{
    //kamus
    boolean genap=true;
    IdxType i=GetFirstIdx(T);
    //algoritma
    if(!IsEmpty(T)){
        while(genap && i<=GetLastIdx(T)){
            if(Elmt(T,i)%2==1){
                genap=false;
            }
            i++;
        }
        return genap;
    }
    return !genap;
}
/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
    //kamus
    IdxType i,j,idmax;
    int temp;
    //algoritma
    if(!IsEmpty(*T)){
        if(!asc){
            for (i = GetLastIdx(*T); i >= GetFirstIdx(*T); i--) {
                idmax = GetFirstIdx(*T);            
                for (j = GetFirstIdx(*T); j <= i; j++){
                    if (Elmt(*T,j) < Elmt(*T,idmax)){
                        idmax=j;
                    }
                }
                // Swap Maximum to the left
                temp = Elmt(*T,i);
                Elmt(*T,i) = Elmt(*T,idmax);
                Elmt(*T,idmax) = temp;
            }
        } else {
            for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) { 
                temp = Elmt(*T,i);
                j = i - 1; 
                while (j > 0 && Elmt(*T,j) > temp) { 
                    Elmt(*T,j+1)=Elmt(*T,j); 
                    j -= 1; 
                } 
            Elmt(*T,j+1)=temp; 
            }
        } 
    } 
}
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    //algortima
    Elmt(*T,GetLastIdx(*T)+1)=X;
    Neff(*T)+=1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X=Elmt(*T,GetLastIdx(*T));
    Neff(*T)-=1;
}
/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
    //algoritma
    MaxEl(*T)+=num;
    TI(*T)= (ElType *) realloc(TI(*T),MaxEl(*T)*sizeof(int));
}
void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{
    //algoritma
    MaxEl(*T)-=num;
    TI(*T)= (ElType *) realloc(TI(*T),MaxEl(*T)*sizeof(int));
}
void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{
    //algoritma
    MaxEl(*T)=Neff(*T);
    TI(*T)= (ElType *) realloc(TI(*T),MaxEl(*T)*sizeof(int));
}