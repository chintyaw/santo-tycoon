
/* file : Inventory.c */
/* Definisi untuk inventory */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ADT/Inventory.h"
#include "ADT/boolean.h"
#include "ADT/array/ListDynI.h"
// #include "stackI.h"
// #include "ArrayDinI.h"

//int main (){
    // inventory I; // ini nanti dimasukin ke main program
    // List Inv;
    // Stack C;
    // char component;
    // MakeList(&Inv);
    // CreateEmpty(&C);
//}

// void BacaFileInventoryT(TInventory *T)
// /* Baca file inventory.txt dan memasukannya ke array */
// {
//     char b[100];
//     char c[100];
//     int a,d,e;
//     FILE *myfile;
//     int count = 37;
//     int i;

//     myfile = fopen("inventory.txt", "r");
//     if (myfile == NULL)
//     {
//         printf("inventory.txt");
//     }
//     else
//     {
//         for (i = 0; i < count; i++) {
//             fscanf(myfile, "%d\n", &Nomor(TabI(*T,i)));
//             fscanf(myfile, "%s\n", Kategori(TabI(*T,i)));
//             fscanf(myfile, "%s\n", Nama(TabI(*T,i)));
//             fscanf(myfile, "%d\n", &Jumlah(TabI(*T,i)));
//             fscanf(myfile, "%d\n", &Harga(TabI(*T,i)));
//             //printf("%d) %s %d\n",i+1,a,b);
//         } 
//     }
//     fclose(myfile);
// }

void AddInventory(inventory *I)
/*Menambahkan componen ke dalam inventory*/
/*I.S. Inventory tersedia*/
/*F.S. jumlah componen pada inventory bertambah sebanyak 1*/
{
    (*I).Jumlah += 1;
}

void DelInventory(inventory *I)
/*Mengurangi component dari dalam inventory*/
/*I.S. componen dalam Inventory tersedia*/
/*F.S. jumlah componen pada inventory berkurang 1*/
{
    if (!IsComponentEmpty(*I)){
        (*I).Jumlah -= 1;
    }
}

boolean IsComponentEmpty(inventory I)
/*I.S. Sembarang*/
/*F.S. Mengirim true apabila jumlah komponen dalam inventory 0*/
{
    
    return ((I).Jumlah==0);
}

void PrinTNnventory(TInventory TabI)
/* nampilin isi inventory dan jumlahnya */
{
    int num = 37; //jumlah komponen total 

    for (int i=0; i<num; i++) {
        //printf("%d. ");
        if (TabI.TN[i].Jumlah != 0){
            printf("%d", TabI.TN[i].Nomor);
            printf("%s", TabI.TN[i].Kategori);
            printf("%s", TabI.TN[i].Nama);
            printf("(");
            printf("%d",TabI.TN[i].Jumlah);
            printf(")");
        }
    }

}

// void ADDCOMPONENT(build *C)
// {
//     Push(&C, component);
// }

// void REMOVECOMPONENT(build *C)
// {
//     Pop(&C, &component);
// }