/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "static_list.h"
#include "list/list.h"
#include <stdbool.h>

/* Write your code here... */

void createEmptyList(tList *L) {
    L->lastPos = LNULL;
}
bool isEmptyList(tList L) {
    return (L.lastPos == LNULL);
}
tPosL first(tList L) {
    return 0;
}
tPosL last(tList L) {
    return L.lastPos;
}
tPosL next(tPosL p, tList L) {
    if (p == LNULL) {
        return LNULL;
    }
    else {
        return ++p;
    }
}
tPosL previous(tPosL p, tList L) {
    return --p;
}
bool insertItem(tItemL d, tPosL p, tList *L) {
    tPosL i;
    if (L->lastPos == MAX - 1) {
        return false;
    }
    else {
        L->lastPos++;
        if (p == LNULL) {
            L->data[L->lastPos] = d;
        }
        else {
            for (i = L->lastPos;i >= p +1; --i) {
                L->data[i] = L->data[i-1];
                L->data[(int)p] = d;
            }
        }
    }
    return true;
}
void deleteAtPosition(tPosL p, tList *L) {
    tPosL i;
    L->lastPos--;
    for (i = p;i <= L->lastPos; ++i) {
        L->data[i] = L->data[i+1];
    }
}
tItemL getItem(tPosL p, tList L) {
    return L.data[p];
}
tPosL findItem(const tPartyName name, tList L) {
    tPosL p = 0;
    for (int i = 0; i < MAX; ++i) {
        if (name != L.data[i].partyName) {
            p = LNULL;
        }
        else {
            p = 0;
        }
    }
    return p;
}
bool copyList(tList L1, tList* L2) {
    tPosL p;
    for (p = 0;p <= L1.lastPos ; ++p) {
        L2->data[p] = L1.data[p];
    }
    L2->lastPos = L1.lastPos;
    return true;
}
void deleteList(tList* L) {
    while (L->lastPos != LNULL) {
        L->lastPos = LNULL; // el array seguirá estando en memoria
    }
}
void updateVotes(tNumVotes a, tPosL p, tList* L) {
    L->data[p].numVotes = a;
}






