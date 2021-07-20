#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stddef.h>
// #include "startbuild.h"
#include "ADT/shop.h"
#include "ADT/queue/queueM.h"


int main(){
    int i = 0;
    Queue Q;
    CreateEmpty(&Q, 100);
    for (i=0; i< 3; i++){
        int invoice = 0;
        int random = rand();
        pesanan A;
        A.NoPesanan = i+1;
        A.Pelanggan = random % 7 + 1 ;
        //Motherboard
        int a = (random % 4 + 1);
        A.Motherboard = nama(a);
        // invoice = harga(random % 4 + 1, 1);
        //CPU
        int b = random % 5 + 5;
        A.CPU = nama(b);
        // invoice += harga(random % 5 + 5, 1);
        //Memory
        int c = random % 5 + 10;
        A.Memory = nama(c);
        // invoice += harga(random % 5 + 10, 1);
        //CPUCooler
        int d = random % 4 + 15;
        A.CPUCooler = nama(d);
        // invoice += harga(random % 4 + 15, 1);
        // Case
        int e = random % 5 + 19;
        A.Case = nama(e);
        // invoice += harga(random % 5 + 19, 1);
        // GPU
        int f = random % 5 + 24;
        A.GPU = nama(f);
        // invoice += harga(random % 5 + 24, 1);
        // Storage
        int g = random % 5 + 29;
        A.Storage = nama(g);
        // invoice += harga(random % 5 + 29, 1);
        // PSU
        int h =random % 4 + 34; 
        A.PSU = nama(h);
        // invoice += harga(random % 4 + 34, 1);

        invoice = harga(a, 1) + harga(b,1) + harga(c,1) +harga(d,1) +
                  harga(e,1) +harga(f,1) +harga(g,1) +harga(h,1)  ;
        A.Invoice = invoice;
        const char* j = nama(a);
        // printf("%s\n", A.Motherboard);
        Enqueue(&Q, A);
    }
    // printf("%s\n", Front(Q).Motherboard);

    return 0;
}