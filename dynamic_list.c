/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "dynamic_list.h"

/* Write your code here... */

bool createNode(tPosL * p) { // función interna a este archivo, no aparace en el archivo de cabecera
    *p = malloc(sizeof(struct tNode));
    return (*p == LNULL?false:true);
}
void createEmptyList(tList* L) {
    *L = LNULL; // creación de una lista vacía, donde el primer puntero de la lista apunte a ninguna dirección de memoria
}
bool insertItem(tItemL d, tPosL p, tList* L) {
    tPosL q, r;
    if (!createNode(&q)) {
        return false;
    }
    else { // comienzo de las tres formas de inserción
        q->data = d;
        q->next = LNULL;
        if (*L == LNULL) { // lista vacía
            *L = q; // el puntero L apunta a donde lo hace q
        }
        else if (p == LNULL) { // FINAL, recorremos toda la lista
            for (r = *L; r->next != LNULL; r = next(r, *L));
            r -> next = q;
        } // fin del FINAL
        else if (p == *L) { // insertar en CABEZA
            q->next = *L;
            *L = q;
        }
        else { // MEDIO
            q->data = p->data;
            p->data = d;
            q->next = p->next;
            p->next = q;
        }
        return true;
    }
}
bool copyList(tList L1, tList* L2) { // No es imprescindible que L2 sea una lista vacía
    tPosL p, q = NULL, r;
    bool retorno = true;
    createEmptyList(L2);
    if (!isEmptyList(L1)) {
    p = L1;
    while ((p != LNULL) && createNode(&r)) {
        r->data = p->data;
        r->next = LNULL;
        if (p == L1) { // cabeza de la lista
            *L2 = r; // *L2 apunta a donde r
            q = r;
        }
        else { // No en la cabeza de la lista
            q->next = r; // Unimos nodo
            q = r;
        }
        p = p->next;
    }
    if (p != LNULL) {
        retorno = false;
        deleteList(L2); // Fallamos en la creación de la lista
    }
    }
    return retorno;
}
void updateVotes(tNumVotes a, tPosL p, tList* L) {
    p->data.numVotes += a;
}
void deleteAtPosition(tPosL p, tList* L) {
    // Tenemos tres posibles situaciones
    // Que p sea ka cabeza de la lista
    // Que p sea el último de la lista
    // Que p sea otro elemento de la lista
    // Al final tendremos que liberar comunmente a p
    tPosL q;
    if (p == *L) {
        *L = (*L)->next;
    }
    else if (p->next == LNULL) { // Caso de la última posición
        for (q = *L; q->next != p; q = q->next);
        q->next = LNULL;
    }
    else { // Borramos en otra posición
        q = p->next;
        p->data = q->data;
        p->next = q->next;
        p = q; // Luego liberamos
    }
    free(p); // Hacemos ya el free de la lista de la posición de p
}
void deleteList(tList* L) {
    tPosL p;
    while (*L != LNULL) {
        p = *L;
        *L = (*L)->next;
        free(p); // Liberamos p para cada una de las posiciones de la lista
    }
}
tPosL findItem(const tPartyName name, tList L) {
    tPosL p;
    for (p = L; (p != LNULL) && (p->data.partyName != name); p = p->next);
    return p; // Devuelve LNULL si no está en la lista, o una posición válida de la lista
}
bool isEmptyList(tList L) {
    if (L == LNULL) {
        return true;
    }
    else {
        return false;
    }
}
tItemL getItem(tPosL p, tList L) {
    return p->data;
}
tPosL first(tList L) {
    return L;
}
tPosL last(tList L) {
    tPosL p;
    for (p = L; p->next != LNULL; p = p->next);
    return p;
}
tPosL previous(tPosL p, tList L) {
    tPosL q;
    if (p == L) { // En la lista solo hay un elemento
        return LNULL;
    }
    else {
        for (q = L; q->next != p; q = q->next);
        return q;
    }
}
tPosL next(tPosL p, tList L) {
    return p->next;
}