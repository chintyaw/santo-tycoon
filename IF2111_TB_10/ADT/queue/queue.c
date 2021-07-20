#include <stdlib.h>
#include <stdio.h>
#include "ADT/queue/queue.h"

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
    (*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));
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

void Enqueue (Queue *Q, infotype X) {
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

void Dequeue (Queue *Q, infotype *X) {
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

infotype Front (Queue Q) {
    return InfoHead(Q);
}