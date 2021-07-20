#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shop.h"

int harga(int beli, int jumlah){
    char line[RSIZ][LSIZ];
    FILE *fptr = fopen("Harga.txt", "r");
    int j = 0;
    int tot = 0;
    while(fgets(line[j], LSIZ, fptr)) 
	{
        line[j][strlen(line[j]) - 1] = '\0';
        j++;
    }
    tot = j;
    int val = (atoi(line[beli-1])*jumlah);  
    return val;  
}

const char *nama(int i) 
{
    char line2[RSIZ][LSIZ];
    FILE *fptr = NULL;
    int j = 0;
    int tot = 0;

    fptr = fopen("NamaKomponen.txt", "r");
    while(fgets(line2[j], LSIZ, fptr)) 
	{
        line2[j][strlen(line2[j]) - 1] = '\0';
        j++;
    }
    tot = j;
    char *isi = line2[i-1];
    return isi;
}

