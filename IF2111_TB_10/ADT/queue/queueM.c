#include <stdlib.h>
#include <stdio.h>
#include "queueM.h"


boolean IsEmpty (Queue Q) {
    return (Head(Q)==Nil && Tail(Q)==Nil);
}

boolean IsFull (Queue Q) {
    return (NBElmt(Q)==MaxEl(Q));
}

int NBElmt (Queue Q) {
    if (IsEmpty(Q)) {
        return 0;
    } else if (Tail(Q)>Head(Q)) {
        return (Tail(Q)-Head(Q)+1);
    } else if (Tail(Q)<Head(Q)) {
        return (MaxEl(Q) - (Tail(Q)-Head(Q)-1));
    } else {
        return 1;
    }
}

void CreateEmpty (Queue *Q, int Max) {
    (*Q).T = (pesanan *) malloc ((Max+1) * sizeof(pesanan));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        MaxEl(*Q) = 0;
    }
}

void DeAlokasi (Queue *Q) {
    MaxEl(*Q) = 0;
    free((*Q).T);
}

void Enqueue (Queue *Q, pesanan X) {
    if (IsEmpty(*Q)) {
        Head(*Q) = 1;
        Tail(*Q) = 1;
    } else {
        Tail(*Q)++;
        if (Tail(*Q)>MaxEl(*Q)) {
            Tail(*Q) = Tail(*Q) % MaxEl(*Q);
        }
    }
    InfoTail(*Q) = X;
}

void Dequeue (Queue *Q, pesanan *X) {
    (*X) = InfoHead(*Q);
    if (Head(*Q)==Tail(*Q)) { /* Kasus 1 elemen, jadi queue kosong */
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q)++;
        if (Head(*Q)>MaxEl(*Q)) {
            Head(*Q) = Head(*Q) % MaxEl(*Q);
        }
    }
}

pesanan Front (Queue Q) {
    return InfoHead(Q);
}

/*void CekOrder(Queue Q){
    printf("Nomor Order : %d\n", Order(Head(Q)));
    printf("Pemesan : Pelanggan %d\n", Pelanggan(Head(Q)));
    printf("Invoice : %d\n", Invoice(Head(Q)));
    printf("Komonen : \n");
    for (int i=0; i<8; i++){
        printf("%d. ", i+1);
        printf("%s\n", Head(Q)->T[i]);
    }*/

