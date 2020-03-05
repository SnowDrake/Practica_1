#include <stdio.h>
#include <string.h>

#ifdef STATIC_LIST
#include "static_list.h"
#endif
#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef TEST_LIST
#include "list/list.h"
#endif

int countElements(tList L) {
    tPosL pos;
    int elements = 0;
    if (isEmptyList(L) == true) {
        elements = 0;
    }
    else {
        pos = first(L);
        while (pos != LNULL) {
            elements++;
            pos = next(pos, L);
        }
    }
    return elements;
}


void printElementsReverse(tList L) {
    tPosL pos;
    tItemL item;

    if (!isEmptyList(L)) {
        pos = last(L);
        while (pos != LNULL) {
            item = getItem(pos, L);
            printf("%s numvotes %d\n", item.partyName, item.numVotes);
            pos = previous(pos, L);
        }
    }
}
void print_list(tList list) {
    tPosL pos;
    tItemL item;

    printf("(");
    if (!isEmptyList(list)) {
        pos = first(list);
        while (pos != LNULL) {
            item = getItem(pos, list);
            printf(" %s numVotes %d", item.partyName, item.numVotes);
            pos = next(pos, list);
        }
    }
    printf(")\n");
}

int main() {
    tList list;
    tPosL pos;
    tItemL item1, item2;

    /* init */
    item1.numVotes = 0;


    /* create */
    createEmptyList(&list);
    print_list(list);


    /* insert */
    strcpy(item1.partyName, "party3");
    insertItem(item1, LNULL, &list);
    print_list(list);

    strcpy(item1.partyName, "party1");
    insertItem(item1, first(list), &list);
    print_list(list);

    strcpy(item1.partyName, "party5");
    insertItem(item1, LNULL, &list);
    print_list(list);

    strcpy(item1.partyName, "party2");
    insertItem(item1, next(first(list),list), &list);
    print_list(list);

    strcpy(item1.partyName, "party4");
    insertItem(item1, last(list), &list);
    print_list(list);

    printf("Elements = %d\n", countElements(list));
    printElementsReverse(list);


    printf("\n");
    /* find */
    pos = findItem("party33", list);
    if (pos == LNULL) {
        printf("party33 Not found\n");
    }

    pos = findItem("party3", list);
    item2 = getItem(pos, list);
    printf("%s\n", item2.partyName);


    /* update */
    updateVotes(1, pos, &list);
    item2 = getItem(pos, list);
    printf("%s\n", item2.partyName);
    print_list(list);


    /* remove */
    deleteAtPosition(next(first(list),list), &list);
    print_list(list);

    deleteAtPosition(previous(last(list),list), &list);
    print_list(list);

    deleteAtPosition(first(list),&list);
    print_list(list);

    deleteAtPosition(last(list),&list);
    print_list(list);

    deleteAtPosition(first(list),&list);
    print_list(list);

    insertItem(item1, LNULL, &list);
    print_list(list);
}
