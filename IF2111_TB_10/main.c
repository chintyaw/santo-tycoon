#include <stdio.h>
#include <stdlib.h>
//#include "graf.c"
#include "ADT/graf/graf.h"
#include "ADT/mesinkar/mesinkar.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/matriks/matriks.h"
//#include "mesinkar.c"
//#include "mesinkata.c"
//#include "matriks.c"
#include "ADT/point/point.h"
//#include "point.c"
#include "ADT/boolean.h"
#include <string.h>
#include "ADT/queue/queueM.h"
// #include "startbuild.h"
#include "ADT/shop.h"
#include "ADT/stack/stackI.h"
// #include "Inventory.h"
#include "ADT/array/ListDynCAD.h"

void Help(){
    printf ("Command List :\n");
    printf ("1. MOVE\n");
    printf ("2. STATUS\n");
    printf ("3. CHECKORDER\n");
    printf ("4. STARTBUILD\n");
    printf ("5. FINISHBUILD\n");
    printf ("6. ADDCOMPONENT\n");
    printf ("7. REMOVECOMPONENT\n");
    printf ("8. SHOP\n");
    printf ("9. DELIVER\n");
    printf ("10.END_DAY\n");
    printf ("11.MAP\n");
    printf ("12.EXIT\n");
}

int MainMenu(int *masukan){
    int var;
	printf("                      SELAMAT DATANG DI PERMAINAN\n");
	printf("                             SANTO TYCOON\n\n");
	printf("                            1. Start Game\n");
	printf("                            2. Load Game\n");
	printf("                            >> ");
    scanf("%d", &var);
	masukan = &var;
	while(*masukan != 1 && *masukan != 2){
		printf("                        Pilihan tidak tersedia.\n");
		printf("                            >> ");
		scanf("%d", &var);
		masukan = &var;
	}

}

int toInt (Kata a){
	char s[] = "";
	int i=0;
	while (i < a.Length){
		strncat(s, &a.TabKata[i], 1);
		i += 1;
	}
		
	int val = atoi(s);
	return val;
}

void Rand(pesanan *A, int *nomorpesanan, int cust, Queue *Q){
    
    int i = 0;
    for (i=0; i< 10; i++){
        float invoice = 0;
        int random = rand();
        (*A).NoPesanan = *nomorpesanan+1;
        (*A).Pelanggan = random % cust + 1 ;
        //Motherboard
        int a = (random % 4 + 1);
        (*A).Motherboard = nama(a);
        // invoice = harga(random % 4 + 1, 1);
        //CPU
        int b = random % 5 + 5;
        (*A).CPU = nama(b);
        // invoice += harga(random % 5 + 5, 1);
        //Memory
        int c = random % 5 + 10;
        (*A).Memory = nama(c);
        // invoice += harga(random % 5 + 10, 1);
        //CPUCooler
        int d = random % 4 + 15;
        (*A).CPUCooler = nama(d);
        // invoice += harga(random % 4 + 15, 1);
        // Case
        int e = random % 5 + 19;
        (*A).Case = nama(e);
        // invoice += harga(random % 5 + 19, 1);
        // GPU
        int f = random % 5 + 24;
        (*A).GPU = nama(f);
        // invoice += harga(random % 5 + 24, 1);
        // Storage
        int g = random % 5 + 29;
        (*A).Storage = nama(g);
        // invoice += harga(random % 5 + 29, 1);
        // PSU
        int h =random % 4 + 34; 
        (*A).PSU = nama(h);
        // invoice += harga(random % 4 + 34, 1);

        invoice = harga(a, 1) + harga(b,1) + harga(c,1) +harga(d,1) +
                  harga(e,1) +harga(f,1) +harga(g,1) +harga(h,1) * 1.1  ;
        (*A).Invoice = invoice;
        const char* j = nama(a);
        // printf("%s\n", A.Motherboard);
        Enqueue(Q, *A);
        *nomorpesanan += 1;
    }
}

int main (){
    float uang = 10000;
    int masukan;
    int cust = 0;
	POINT posisi;
	MATRIKS M;
    STARTKATA();
    int NB = toInt(CKata);
    ADVKATA();
    int NK = toInt(CKata);
    //printf("Baris = %d Kolom = %d\n", NB, NK);
    MakeMATRIKS (NB, NK, &M);
    ADVKATA();
    int bangunan = toInt(CKata);
    //printf("Jumlah bangunan = %d\n", bangunan);
    ADVKATA();
    int i;
    for (i=0;i<bangunan;i++){
    	char jenis = CKata.TabKata[0];
    	//printf("%c ", jenis);
    	if (jenis == 'C'){
    		cust += 1;
    		jenis = cust + '0';
		}
    	ADVKATA();
    	int x = toInt (CKata);
    	//printf ("%d ", x);
    	ADVKATA();
    	int y = toInt (CKata);
    	//printf ("%d\n", y);
    	if (jenis == 'B'){
    		posisi = MakePOINT (x,y,'P');
		}
		
    	POINT P = MakePOINT (x,y,jenis);
    	Elmt(M,x,y) = P.jenis;
    	//TulisPOINT (P);
    	//printf("\n");
    	ADVKATA();
	}
    //TulisMATRIKS (M, NB, NK, posisi.X, posisi.Y);
	//Graph
	Graph G;
	CreateGraph(1 ,&G);
	int j;
	for (i=2; i<=bangunan; i++)
		InsertNode(&G, i);
		
	for (i=1; i<=bangunan; i++){
		for (j=1; j<=bangunan; j++){
			if (CKata.TabKata[0] == '1') InsertSuccNode (&G, i, j);
			ADVKATA();
		}
	}
/*********************************RANDOMPESANAN***********************************************/
    Queue Q;
    pesanan A, prec;
    CreateEmpty(&Q,100);
    int nomorpesanan = 0;
    Rand(&A, &nomorpesanan, cust, &Q);


/************************************************SHOP*************************************************************/
    char buff[1024];
    char line[RSIZ][LSIZ];
    int row_count = 0;
    int field_count = 0;
    i = 0;
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
    fclose(fp);
/************************************INVENTORY********************************************************************/
    //inventory I; // ini kayanya gajadi
    List Inv;
    MakeEmpty(&Inv, 100);
    AddAsLastEl(&Inv, "Motherboard ASRock_H81_Pro_BTC", "Komponen", 1);
    AddAsLastEl(&Inv, "CPU Intel_Pentium_G2030", "Komponen", 1);
    AddAsLastEl(&Inv, "Memory V-Gen_8GB", "Komponen", 1);
    AddAsLastEl(&Inv, "CPU_Cooler Deepcool_GAMMAXX", "Komponen", 1);
    AddAsLastEl(&Inv, "Case ARMAGGEDDON", "Komponen", 1);
    AddAsLastEl(&Inv, "GPU Zotac_GTX", "Komponen", 1);
    AddAsLastEl(&Inv, "Storage SEAGATE_SSD_480GB", "Komponen", 1);
    AddAsLastEl(&Inv, "PSU 500W", "Komponen", 1);

/************************************STACK**************************************************/
	Stack rakitan;
	// TOPS(rakitan) =0;
/*******************************************************************************************/	
	boolean SudahBuild = false;
    boolean SudahFinish = false;
    int komponen;
    start:
    switch ((MainMenu(&masukan))){
	case 1:{
            char commando[20];
            printf ("ENTER COMMAND :");
            scanf("%s", &commando);
            while (true) {
                brow:
                    while (strcmp(commando, "MOVE")==0){
                        adrNode P = First(G);
                        int posbangunan;
                        if (Elmt(M,posisi.X,posisi.Y) == 'B'){
                            printf("Kamu sedang berada di base.\n");
                            posbangunan = 1;
                        }
                        else if (Elmt(M,posisi.X,posisi.Y) == 'S'){
                            printf("Kamu sedang berada di shop.\n");
                            posbangunan = 2;
                        }
                        else {
                            posbangunan = (int)(Elmt(M,posisi.X,posisi.Y)) - (int)'0' + 2;
                            printf("Kamu sedang berada di pelanggan %d.\n", posbangunan-2);
                        }
                        
                        while (P != NULL && Id(P) != posbangunan ) {
                            P = Next(P);
                        }
                        
                        int adjlist[100];
                        printf("Daftar lokasi yang dapat dicapai:\n");
                        int l=1;
                        adrSuccNode PSucc = Trail(P);
                        while (PSucc != NULL){
                                if (Succ(PSucc) == 1){
                                    printf("%d. Base\n", l);
                                    adjlist[l] = Succ(PSucc);
                                    l+=1;
                                }
                                else if (Succ(PSucc) == 2){
                                    printf("%d. Shop\n", l);
                                    adjlist[l] = Succ(PSucc);
                                    l+=1;
                                }
                                else {
                                    printf("%d. Pelanggan %d\n", l, Succ(PSucc)-2);
                                    adjlist[l] = Succ(PSucc); // yang dimasukkan ke array yang integernya (angka 3 berarti pelanggan 1)
                                    l+=1;
                                }
                                
                                PSucc = Next(PSucc);
                            }
                        printf("\n");
                        
                        /* for (j=1;j<l;j++){
                            printf("%d %d\n", j, adjlist[j]);
                        } */
                        int tujuan;
                        printf("Nomor tujuan: ");
                        scanf("%d", &tujuan);
                        
                        while (tujuan < 1 || tujuan >= l){
                            printf("Tujuan tidak tersedia!\n");
                            printf("Nomor tujuan: ");
                            scanf("%d", &tujuan);
                        }
                        
                        // tujuan adalah adjlist[tujuan].
                        // adjlist[tujuan] = 3 pelanggan 1
                        
                        if (adjlist[tujuan] == 1) {
                            printf("Kamu telah mencapai base!\n");
                            for (i=1;i<=NB;i++){
                                for (j=1;j<=NK;j++){
                                    if (Elmt(M,i,j) == 'B'){
                                        posisi = MakePOINT (i,j,'B');
                                    }
                                }
                            }
                        }
                        else if (adjlist[tujuan] == 2) {
                            printf("Kamu telah mencapai shop!\n");
                            for (i=1;i<=NB;i++){
                                for (j=1;j<=NK;j++){
                                    if (Elmt(M,i,j) == 'S'){
                                        posisi = MakePOINT (i,j,'S');
                                    }
                                }
                            }
                        }
                        else {
                            printf("Kamu telah mencapai lokasi Pelanggan %d!\n", adjlist[tujuan]-2);
                            for (i=1;i<=NB;i++){
                                for (j=1;j<=NK;j++){
                                    if (Elmt(M,i,j) == adjlist[tujuan]-2 + '0'){
                                        posisi = MakePOINT (i,j,'C');
                                    }
                                }
                            }
                        }
                        printf("\n");
                        printf ("ENTER COMMAND :");
                        scanf("%s", &commando); 
                        goto brow;   
                    }
                    while (strcmp(commando, "STATUS")==0) {
                    	/** UANG **/
                        /*********************************/
                        printf ("Uang tersisa: %.2f\n", uang);

                    	/** BUILD **/
                        /*********************************/
                        if (SudahBuild){
                            printf("Build yang sedang dikerjakan: pesanan %d untuk pelanggan %d.\n", Front(Q).NoPesanan, Front(Q).Pelanggan);
                        }
                        else{
                            printf("Kamu belum STARTBUILD!\n");
                        }
                        
						/** LOKASI **/
						printf("Lokasi: ");
						int posbangunan;
						if (Elmt(M,posisi.X,posisi.Y) == 'B'){
                            printf("Pemain sedang berada di base.\n");
                            posbangunan = 1;
                        }
                        else if (Elmt(M,posisi.X,posisi.Y) == 'S'){
                            printf("Pemain sedang berada di shop.\n");
                            posbangunan = 2;
                        }
                        else {
                            posbangunan = (int)(Elmt(M,posisi.X,posisi.Y)) - (int)'0';;
                            printf("Pemain sedang berada di pelanggan %d.\n", posbangunan);
                        }
                        
                        /** INVENTORY **/
                        /***********************************/
                        printf("Inventory Anda:\n");
                        TulisIsiTab(Inv);
                        /***********************************/
                        printf("\n");   
                        printf ("ENTER COMMAND :");
                        scanf("%s", &commando);
                        goto brow;
                    }
                    while (strcmp(commando, "CHECKORDER")==0) {
                        if (SudahBuild){
                            printf("Nomor Order : %d\n", Front(Q).NoPesanan);
                            printf("Pemesan : Pelanggan %d\n", Front(Q).Pelanggan);
                            printf("Invoice : $%d\n", Front(Q).Invoice);
                            printf("Komponen : \n");
                            printf("1. %s\n", Front(Q).Motherboard);
                            printf("2. %s\n", Front(Q).CPU);
                            printf("3. %s\n", Front(Q).Memory);
                            printf("4. %s\n", Front(Q).CPUCooler);
                            printf("5. %s\n", Front(Q).Case);
                            printf("6. %s\n", Front(Q).GPU);
                            printf("7. %s\n", Front(Q).Storage);
                            printf("8. %s\n", Front(Q).PSU);
                        } else {
                            printf ("Kamu belum STARTBUILD!\n");
                        }
                        printf("\n");   
                        printf ("ENTER COMMAND :");
                        scanf("%s", &commando);
                        goto brow;
                    }
                    while (strcmp(commando, "STARTBUILD")==0) {
                        while (Elmt(M,posisi.X,posisi.Y) !=  'B') {
                            printf("Kamu belum berada di base! Silakan pergi ke base terlebih dahulu.\n");
                            printf("\n");   
                            printf ("ENTER COMMAND :");
                            scanf("%s", &commando);
                            goto brow;
                        }  
                        
                        if (!SudahBuild){
                        	SudahBuild = true;
                        	printf("Kamu telah memulai pesanan %d untuk pelanggan %d.\n", Front(Q).NoPesanan, Front(Q).Pelanggan);
                        	CreateEmptyStack(&rakitan);
                            // TOPS(rakitan) = 0;
						}
						
						else {
							printf("Kamu telah memulai pesanan %d untuk pelanggan %d.\n", Front(Q).NoPesanan, Front(Q).Pelanggan);
						}
						
                        printf("\n");   
                        printf ("ENTER COMMAND :");
                        scanf("%s", &commando);
                        goto brow;
                    }
                    while (strcmp(commando, "FINISHBUILD")==0) {
                        while (Elmt(M,posisi.X,posisi.Y) !=  'B'){
                            printf("Kamu belum berada di base! Silakan pergi ke base terlebih dahulu.\n");
                            printf("\n");
                            printf ("ENTER COMMAND :");
                            scanf("%s", &commando);
                            goto brow;
                        }
                        
                        if(SudahBuild){
                            if(IsEmptyS(rakitan)){
                                printf("Kamu belum memulai memasang komponen!\n");
                            }
                            
                            else {
								if ((strcmp(rakitan.T[1], Front(Q).Motherboard)==0) && (strcmp(rakitan.T[2], Front(Q).CPU) == 0)
                                    && (strcmp(rakitan.T[3] , Front(Q).Memory)==0) && (strcmp(rakitan.T[4] , Front(Q).CPUCooler)==0) 
                                    && (strcmp(rakitan.T[5] , Front(Q).Case)==0) && (strcmp(rakitan.T[6], Front(Q).GPU)==0) && 
                                    (strcmp(rakitan.T[7] , Front(Q).Storage)==0) && (strcmp(rakitan.T[8] , Front(Q).PSU)==0)){
                                    SudahFinish = true;
                                    char nomorbuild[100];
                                    //sprintf(nomorbuild, "%d", Front(Q).NoPesanan);
                                
                                    itoa(Front(Q).NoPesanan,nomorbuild,10);
                                    char namabuild[100] = "Build untuk Pesanan #"; 
                                    strncat (namabuild, nomorbuild, 21);
                                   
                                    //strcpy(nomorbuildf, nomorbuild);
                                    const char* nomorbuildff = namabuild;
                                    //printf("%s\n", namabuild);
                                    //printf("%s\n", nomorbuildff);
                                    AddAsLastEl(&Inv, nomorbuildff, "Build", 1);
                                    
                                    printf("Pesanan %d telah selesai. Silakan antar ke pelanggan %d!\n", Front(Q).NoPesanan, Front(Q).Pelanggan);
                        		    CreateEmptyStack(&rakitan);
                                     // SudahBuild = false;
                                    Dequeue(&Q, &prec);
                                    
                                    printf("\n");

                                     printf ("ENTER COMMAND :");
                                     scanf("%s", &commando);
                                     goto brow;                                
                                 }
                            	else {
                                     printf("Pesanan kamu belum sesuai dengan pesanan pelanggan!\n");
                                     printf("\n");

                                     printf ("ENTER COMMAND :");
                                     scanf("%s", &commando);
                                     goto brow;                                
                                 }
                            } 
                    	}
                        else {
                            printf("Kamu belum STARTBUILD!\n"); 
                            printf("\n");

                            printf ("ENTER COMMAND :");
                            scanf("%s", &commando);
                            goto brow;                        
                        }

                        printf("\n");

                        printf ("ENTER COMMAND :");
                        scanf("%s", &commando);
                        goto brow;
                    }
                    
                    while (strcmp(commando, "ADDCOMPONENT")==0) {
                    	while (Elmt(M,posisi.X,posisi.Y) !=  'B') {
                            printf("Kamu belum berada di base! Silakan pergi ke base terlebih dahulu.\n");
                            printf("\n");   
                            printf ("ENTER COMMAND :");
                            scanf("%s", &commando);
                            goto brow;
                        }  
                        
                        if (SudahBuild){
                        	printf("Komponen yang telah terpasang:\n");
                        	PrintStack(rakitan);
                        
                        	/******INVENTORY*******/
                        	printf("Komponen yang tersedia:\n");
                        	TulisIsiKomponen(Inv);

                        	if(!IsEmptyL(Inv)){
                                printf("Komponen yang ingin dipasang: ");
                            	scanf("%d", &komponen);

                                while(( komponen<1 || komponen > NbElmtL(Inv))){
                                    printf("Komponen tidak tersedia pada inventory kamu.\n");
                                    // printf("Ulangi masukan!\n");
                                    printf("\n");   
                                    printf ("ENTER COMMAND :");
                                    scanf("%s", &commando);
                                    goto brow;
                                }

                                while (TOPS(rakitan) == 0){
                                    if (strncmp(ElmtL(Inv, komponen), "Motherboard",11) == 0){
                                        PushS(&rakitan, ElmtL(Inv, komponen));
                                        printf("Komponen berhasil dipasang!\n");
                                        AddAsLastEl (&Inv, ElmtL(Inv, komponen), "Komponen", -1);
                                            // TOPS(rakitan) += 1;
                                        if (Jlh(Inv, komponen) == 0) {
                                            DelEl (&Inv, ElmtL(Inv, komponen));
                                        }
                                        printf("\n");   
                                        printf ("ENTER COMMAND :");
                                        scanf("%s", &commando);
                                        goto brow;
                                            
                                    }
                                    else {
                                        printf("Masukkan Motherboard terlebih dahulu!\n");
                                    }
                                

                                    printf("\n");   
                                    printf ("ENTER COMMAND :");
                                    scanf("%s", &commando);
                                    goto brow;
                                }
                                while (TOPS(rakitan) == 1){
                                    if (strncmp(ElmtL(Inv, komponen), "CPU ",4) == 0){
                                        PushS(&rakitan, ElmtL(Inv, komponen));
                                        printf("Komponen berhasil dipasang!\n");
                                        AddAsLastEl (&Inv, ElmtL(Inv, komponen), "Komponen", -1);
                                            // TOPS(rakitan) += 1;
                                        if (Jlh(Inv, komponen) == 0) {
                                            DelEl (&Inv, ElmtL(Inv, komponen));
                                        }
                                        printf("\n");   
                                        printf ("ENTER COMMAND :");
                                        scanf("%s", &commando);
                                        goto brow;
                                            
                                    }
                                    else {
                                        printf("Masukkan CPU terlebih dahulu!\n");
                                    }
                                

                                    printf("\n");   
                                    printf ("ENTER COMMAND :");
                                    scanf("%s", &commando);
                                    goto brow;
                                }
                            
                            while (TOPS(rakitan) == 2){
                                if (strncmp(ElmtL(Inv, komponen), "Memory",6) == 0){
                                            PushS(&rakitan, ElmtL(Inv, komponen));
                                            printf("Komponen berhasil dipasang!\n");
                                            AddAsLastEl (&Inv, ElmtL(Inv, komponen), "Komponen", -1);
                                                // TOPS(rakitan) += 1;
                                            if (Jlh(Inv, komponen) == 0) {
                                                DelEl (&Inv, ElmtL(Inv, komponen));
                                            }
                                            printf("\n");   
                                            printf ("ENTER COMMAND :");
                                            scanf("%s", &commando);
                                            goto brow;
                                                
                                        }
                                        else {
                                            printf("Masukkan Memory terlebih dahulu!\n");
                                        }
                                    

                                        printf("\n");   
                                        printf ("ENTER COMMAND :");
                                        scanf("%s", &commando);
                                        goto brow;
                                    }
                            while (TOPS(rakitan) == 3){
                                if (strncmp(ElmtL(Inv, komponen), "CPU_Cooler",10) == 0){
                                            PushS(&rakitan, ElmtL(Inv, komponen));
                                            printf("Komponen berhasil dipasang!\n");
                                            AddAsLastEl (&Inv, ElmtL(Inv, komponen), "Komponen", -1);
                                                // TOPS(rakitan) += 1;
                                            if (Jlh(Inv, komponen) == 0) {
                                                DelEl (&Inv, ElmtL(Inv, komponen));
                                            }
                                            printf("\n");   
                                            printf ("ENTER COMMAND :");
                                            scanf("%s", &commando);
                                            goto brow;
                                                
                                        }
                                        else {
                                            printf("Masukkan CPU Cooler terlebih dahulu!\n");
                                        }
                                    

                                        printf("\n");   
                                        printf ("ENTER COMMAND :");
                                        scanf("%s", &commando);
                                        goto brow;
                                    }
                            while (TOPS(rakitan) == 4){
                                if (strncmp(ElmtL(Inv, komponen), "Case",4) == 0){
                                            PushS(&rakitan, ElmtL(Inv, komponen));
                                            printf("Komponen berhasil dipasang!\n");
                                            AddAsLastEl (&Inv, ElmtL(Inv, komponen), "Komponen", -1);
                                                // TOPS(rakitan) += 1;
                                            if (Jlh(Inv, komponen) == 0) {
                                                DelEl (&Inv, ElmtL(Inv, komponen));
                                            }
                                            printf("\n");   
                                            printf ("ENTER COMMAND :");
                                            scanf("%s", &commando);
                                            goto brow;
                                                
                                        }
                                        else {
                                            printf("Masukkan Case terlebih dahulu!\n");
                                        }
                                    

                                        printf("\n");   
                                        printf ("ENTER COMMAND :");
                                        scanf("%s", &commando);
                                        goto brow;
                                    }
                            while (TOPS(rakitan) == 5){
                                if (strncmp(ElmtL(Inv, komponen), "GPU",3) == 0){
                                            PushS(&rakitan, ElmtL(Inv, komponen));
                                            printf("Komponen berhasil dipasang!\n");
                                            AddAsLastEl (&Inv, ElmtL(Inv, komponen), "Komponen", -1);
                                                // TOPS(rakitan) += 1;
                                            if (Jlh(Inv, komponen) == 0) {
                                                DelEl (&Inv, ElmtL(Inv, komponen));
                                            }
                                            printf("\n");   
                                            printf ("ENTER COMMAND :");
                                            scanf("%s", &commando);
                                            goto brow;
                                                
                                        }
                                        else {
                                            printf("Masukkan GPU terlebih dahulu!\n");
                                        }                                   
                                        printf("\n");   
                                        printf ("ENTER COMMAND :");
                                        scanf("%s", &commando);
                                        goto brow;
                                    }
                            while (TOPS(rakitan) == 6){
                                if (strncmp(ElmtL(Inv, komponen), "Storage",7) == 0){
                                            PushS(&rakitan, ElmtL(Inv, komponen));
                                            printf("Komponen berhasil dipasang!\n");
                                            AddAsLastEl (&Inv, ElmtL(Inv, komponen), "Komponen", -1);
                                                // TOPS(rakitan) += 1;
                                            if (Jlh(Inv, komponen) == 0) {
                                                DelEl (&Inv, ElmtL(Inv, komponen));
                                            }
                                            printf("\n");   
                                            printf ("ENTER COMMAND :");
                                            scanf("%s", &commando);
                                            goto brow;
                                                
                                        }
                                        else {
                                            printf("Masukkan Storage terlebih dahulu!\n");
                                        }
                                        printf("\n");   
                                        printf ("ENTER COMMAND :");
                                        scanf("%s", &commando);
                                        goto brow;
                                    }
                            }
                            while (TOPS(rakitan) == 7){
                                if (strncmp(ElmtL(Inv, komponen), "PSU",3) == 0){
                                            PushS(&rakitan, ElmtL(Inv, komponen));
                                            printf("Komponen berhasil dipasang!\n");
                                            AddAsLastEl (&Inv, ElmtL(Inv, komponen), "Komponen", -1);
                                            if (Jlh(Inv, komponen) == 0) {
                                                DelEl (&Inv, ElmtL(Inv, komponen));
                                            }
                                            printf("\n");   
                                            printf ("ENTER COMMAND :");
                                            scanf("%s", &commando);
                                            goto brow;
                                                
                                        }
                                        else {
                                            printf("Masukkan PSU!\n");
                                        }
                                    

                                        printf("\n");   
                                        printf ("ENTER COMMAND :");
                                        scanf("%s", &commando);
                                        goto brow;
                                    }
						}
						else {
							printf("Kamu belum STARTBUILD!\n");
						}
                        /*******STACK**********/
                        
                        printf("\n");   
                        printf ("ENTER COMMAND :");
                        scanf("%s", &commando);
                        goto brow;
                    }
                    

                    while (strcmp(commando, "REMOVECOMPONENT")==0) {
                        while (Elmt(M,posisi.X,posisi.Y) !=  'B') {
                            printf("Kamu belum berada di base! Silakan pergi ke base terlebih dahulu.\n");
                            printf("\n");   
                            printf ("ENTER COMMAND :");
                            scanf("%s", &commando);
                            goto brow;
                        }
                        if (!IsEmptyS(rakitan)){
                        	const char* removed;
                    		PopS(&rakitan, &removed);
                    		AddAsLastEl (&Inv, removed, "Komponen", 1);
                        
                        	printf("Komponen %s berhasil dicopot\n", removed);
						}
                    	else {
                    		printf("Kamu belum merakit apapun!\n");
						}
                        printf("\n");   
                        printf ("ENTER COMMAND :");
                        scanf("%s", &commando);
                        goto brow;
                    }
                    while (strcmp(commando, "SHOP")==0) {
                        while (Elmt(M,posisi.X,posisi.Y) !=  'S') {
                            printf("Kamu belum berada di shop! Silakan pergi ke shop terlebih dahulu.\n");
                            printf("\n");   
                            printf ("ENTER COMMAND :");
                            scanf("%s", &commando);
                            goto brow;                            
                        }             
                            printf("Komponen yang tersedia:\n");
                            for (i = 0; i < 38; i++)
                            {
                                printf("%s. %s - $%s\n", shop[i].no, shop[i].nama, shop[i].harga);
                            }
                            printf("Komponen yang ingin dibeli: ");
                            int ret = scanf("%d", &beli);
                            
                            if (beli<1 || beli>38){
                                printf("Komponen yang kamu beli tidak tersedia!\n");
                                printf("\n");   
                                printf ("ENTER COMMAND :");
                                scanf("%s", &commando);
                                goto brow;                           
                            }                       

                            printf("Masukkan jumlah yang ingin dibeli: ");
                            scanf("%d", &jumlah);

                            if (uang >= harga(beli,jumlah)){
                                printf("Komponen berhasil dibeli!\n");
                                // Masukin ke Inventory
                                uang -= harga(beli,jumlah);
                                // printf("%.2f\n", uang);
                                AddAsLastEl(&Inv, nama(beli), "Komponen", jumlah);
                                //printf("Yang dibeli: %s\n", nama(beli));
                            }
                            else{
                                printf("Uang tidak cukup!\n");
                            }
                        
                        printf("\n");   
                        printf ("ENTER COMMAND :");
                        scanf("%s", &commando);
                        goto brow;
                                               
                    }
                    while (strcmp(commando, "DELIVER")==0) {
                        if (!SudahBuild){
                            printf("Kamu belum STARTBUILD!\n");
                            printf ("ENTER COMMAND :");
                            scanf("%s", &commando);
                            goto brow;
                        }
                        while (Elmt(M,posisi.X,posisi.Y) !=  prec.Pelanggan + '0'){
                            printf ("Kamu belum berada di rumah pelanggan %d!\n", prec.Pelanggan);
                            printf ("ENTER COMMAND :");
                            scanf("%s", &commando);
                            goto brow;
                        }
                        if (SudahFinish){
                        	SudahFinish = false;
                            printf("Pesanan #%d berhasil diantarkan ke pelanggan %d!\n", prec.NoPesanan, prec.Pelanggan);
                            uang += prec.Invoice;

                            char nomorbuild[100];
                            itoa(prec.NoPesanan,nomorbuild,10);
                            char namabuild[100] = "Build untuk Pesanan #"; 
                            strncat (namabuild, nomorbuild, 21);
                                   
                            //strcpy(nomorbuildf, nomorbuild);
                            const char* nomorbuildff = namabuild;
                            DelEl(&Inv, nomorbuildff);
                        }
                        
                        printf("\n");   

                        printf ("ENTER COMMAND :");
                        scanf("%s", &commando);
                        goto brow;
                    }
                    while (strcmp(commando, "END_DAY")==0) {
                        const char *komponenS;
                        while(!IsEmptyS(rakitan)){
                            PopS(&rakitan, &komponenS); 
                            AddAsLastEl(&Inv, komponenS, "Komponen", 1);
                        }
                        CreateEmpty(&Q, 100);
                        Rand(&A, &nomorpesanan, cust, &Q);
                        printf("Kamu telah memulai hari yang baru!\n");
                        printf("\n");   
                        printf ("ENTER COMMAND :");
                        scanf("%s", &commando);
                        goto brow;
                    }
                    while (strcmp(commando, "MAP")==0) {
	                    TulisMATRIKS (M, NB, NK, posisi.X, posisi.Y);   
						printf("\n");                       
                        printf ("ENTER COMMAND :");
                        scanf("%s", &commando);
                        goto brow;
                    }
                    while (strcmp(commando, "HELP")==0) {
                        Help();
                        printf("\n");   
                        printf ("ENTER COMMAND :");
                        scanf("%s", &commando);
                        goto brow;
                    }
                    while(strcmp(commando,"EXIT")==0){
                        return 0;
                    }
                    
                    if ((strcmp(commando, "MOVE")!=0) || (strcmp(commando, "STATUS")!=0) || (strcmp(commando, "CHECKORDER")!=0) ||
                    (strcmp(commando, "STARTBUILD")!=0) || (strcmp(commando, "FINISHBUILD")!=0) || (strcmp(commando, "ADDCOMPONENT")!=0) ||
                    (strcmp(commando, "REMOVECOMPONENT")!=0) || (strcmp(commando, "SHOP")!=0) || (strcmp(commando, "DELIVER")!=0) ||
                    (strcmp(commando, "END_DAY")!=0) || (strcmp(commando, "MAP")!=0) || (strcmp(commando, "EXIT")!=0) || (strcmp(commando, "HELP")!=0));
                        printf("Command Salah!\n");
                        printf("Masukkan HELP pada command untuk melihat list command!\n");
                        printf ("ENTER COMMAND :");
                        scanf("%s", &commando);
                        goto brow;   
						
					        
                }          
            }
	case 2:{
		printf("Fitur belum tersedia.\n");
        goto start;
	}
	default:
		break;
	}
    return 0;
}
