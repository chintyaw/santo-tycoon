/* file : inventory.h */
/* Definisi untuk inventory*/


#ifndef inventory_H_
#define inventory_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ADT/boolean.h"

/**** PROPERTI Inventory ****/
typedef struct {
    int Nomor;
    char *Kategori[100]; // kalo ini gabisa pake [100] nanTN delet aja.
    char *Nama[100];
    int Jumlah;
    int Harga;
} inventory;

/**** PROPERTI Build ****/
typedef struct {
    char component;
} build;

/**** ARRAY Inventory ****/
typedef struct {
    inventory TN[38];
} TInventory;

/**** ARRAY Inventory ****/
typedef struct {
    build Tb[10];
} Tbuild;

/**** SELEKTOR ****/
#define Nomor(I) (I).Nomor 
#define Kategori(I) (I).Kategori
#define Nama(I) (I).Nama 
#define Jumlah(I) (I).Jumlah
#define Harga(I) (I).Harga
#define TabI(T, i) (T).TN[(i)]

#define Top(C) (C).TOP
#define InfoTop(C) (C).T[(C).TOP]

// void BacaFileInventoryT(TNnventory *T);
// /* Baca file inventory.txt dan memasukannya ke array */



void AddInventory(inventory *I);
/*Menambahkan componen ke dalam inventory*/
/*I.S. Inventory tersedia*/
/*F.S. jumlah componen pada inventory bertambah sebanyak 1*/

void DelInventory(inventory *I);
/*Mengurangi component dari dalam inventory*/
/*I.S. componen dalam Inventory tersedia*/
/*F.S. jumlah componen pada inventory berkurang 1*/

boolean IsComponentEmpty(inventory I);
/*I.S. Sembarang*/
/*F.S. Mengirim true apabila jumlah komponen dalam inventory 0*/

void PrinTNnventory(TInventory TabI);
/* nampilin isi inventory dan jumlahnya */

void ADDCOMPONENT(build *C);

void REMOVECOMPONENT(build *C);

#endif
