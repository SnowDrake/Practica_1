/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define LNULL NULL

/* Write your code here... */
typedef struct tNode * tPosL;
struct tNode {
    tItemL data;
    tPosL next;
};
typedef tPosL tList;

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
