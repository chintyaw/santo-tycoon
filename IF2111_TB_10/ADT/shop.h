#ifndef SHOP_H
#define SHOP_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LSIZ 1000
#define RSIZ 1000

typedef struct SHOP
{
    char no[38];
    char nama[38];
    char harga[38];
    char jenis[38];
} dict;

int harga(int beli, int jumlah);
// Return harga total dari yg dibeli player

const char* nama(int i); 
// Print Nama dari yang mau dibeli player

#endif



