/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
#include "list/list.h"

#define LNULL -1
#define MAX 25


/* Write your code here... */

typedef int tPosL;

typedef struct {
    tItemL data[MAX];
    tPosL lastPos;
}tList;



void createEmptyList(tList* L);
bool insertItem(tItemL d, tPosL p, tList* L);
bool copyList(tList L1, tList* L2);
void updateVotes(tNumVotes a, tPosL p, tList* L);
void deleteAtPosition(tPosL p, tList* L);
void deleteList(tList* L);
tPosL findItem(const tPartyName name, tList L);
bool isEmptyList(tList L);
tItemL getItem(tPosL p, tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL previous(tPosL p, tList L);
tPosL next(tPosL p, tList L);

#endif
