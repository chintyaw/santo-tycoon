#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int NoPesanan;
    int Pelanggan;
    int Invoice;
    const char* Motherboard;
    const char* CPU;
    const char* Memory;
    const char* CPUCooler;
    const char* Case;
    const char* GPU;
    const char* Storage;
    const char* PSU;
}pesanan;

typedef struct {
    pesanan TB[100];   
}tpesanan;

