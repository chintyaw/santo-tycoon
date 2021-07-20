#include "ADT/shop.h"

int main()
{
    char buff[1024];
    char line[RSIZ][LSIZ];
    int row_count = 0;
    int field_count = 0;
    int i = 0;
    int beli, jumlah, total;
    dict shop[38];
    FILE *fp = fopen("shop.csv", "r");
    
    while (fgets(buff, 1024, fp))
    {
        field_count = 0;
        row_count++;
        if (row_count == 1)
            continue;
        char *field = strtok(buff, ",");
        
        while (field){
            if (field_count == 0)
                strcpy(shop[i].no, field);
            if (field_count == 1)
                strcpy(shop[i].nama, field);
            if (field_count == 2)
                strcpy(shop[i].harga, field);

            field = strtok(NULL, ",");
            field_count++;
        }
        i++;
    }

    printf("Komponen yang tersedia:\n");
    for (int i = 0; i < 38; i++)
    {
        printf("%s. %s - $%s\n", shop[i].no, shop[i].nama, shop[i].harga);
    }

    printf("Komponen yang ingin dibeli: ");
    scanf("%d", &beli);
    printf("Masukkan jumlah yang ingin dibeli: ");
    scanf("%d", &jumlah);
    fclose(fp);
   
    //Dari sini pake .txt aja :
    // printf("\n\n Read the file and store the lines into an array :\n");
	// printf("------------------------------------------------------\n"); 
    // harga(beli, jumlah);
    // nama(beli);
    // printf("%d", harga(beli, jumlah) * jumlah);    
    
    return 0;
}

