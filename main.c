/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include "types.h"
#include <string.h>

#define CODE_LENGTH 2

#ifdef STATIC_LIST
#include "static_list.h"
#endif
#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef TEST_LIST
#include "list/list.h"
#endif


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

float devolverParam(char param[NAME_LENGTH_LIMIT+1]) {
    const char * str = param;
    float x;
    sscanf(param, "%f", &x);
    return x;
}

void print_list_STATS(tList list, tPartyName param, int *votosTotales, int *votosNulos) {
    tPosL pos;
    tItemL item;

    if (!isEmptyList(list)) {
        pos = first(list);
        while (pos != LNULL) {
            item = getItem(pos, list);
            if (votosTotales == 0) {
                printf("Party %s numVotes %d (0.00%%)\n", item.partyName, item.numVotes);
            }
            else if (votosTotales > 0) {
                printf("Party %s numVotes %d (%.2f%%)\n", item.partyName, item.numVotes, ((float)item.numVotes/(float)votosTotales)*100);
            }
            pos = next(pos, list);
        }
    }
    else {
        printf("(Empty list)\n");
    }
    printf("Null votes %d\n", votosNulos);
    printf("Participation: %d votes from %s voters (%.2f%%)\n", votosTotales + votosNulos, param, (((float)votosTotales+(float)votosNulos)/devolverParam(param)*100));
}

void crearPartido(tPartyName name, tList *lista) {
    struct tItemL newItem;
    newItem.numVotes = 0;
    strcpy(newItem.partyName, name);

    bool check;
    tPosL p;

    if (findItem(name, *lista) == LNULL) {
        check = insertItem(newItem, LNULL, lista);
        p = findItem(name, *lista);
        if (check == true) {
            printf("* New: %s\n", getItem(p, *lista).partyName);
        }
        else {
            printf("+ Error: New not possible\n");
        }
    }
    else {
        printf("+ Error: New not possible\n");
    }

}

void votarPartido(tPartyName name, tList *lista, int *votosTotales, int *votosNulos) {
    tPosL p;
    int N = 0; // Variable que incrementa los votos del partido
    if (findItem(name, *lista) == LNULL) {
        printf("+ Error: Vote not possible. %s not found. NULLVOTE\n", name);
        votosNulos++;
    }
    else {
        p = findItem(name, *lista);
        N = getItem(p, *lista).numVotes;
        N++;
        updateVotes(N, p, lista);
        printf("* Vote: %s numvotes %d\n", name, getItem(p, *lista).numVotes);
        votosTotales++;
    }
}


void processCommand(char command_number[CODE_LENGTH+1], char command, char param[NAME_LENGTH_LIMIT+1], tList *L, int * votosTotales, int * votosNulos) {

    switch(command) {
        case 'N': {
            // Creación del partido en la lista
            printf("********************\n");
            printf("%s %c: party %s\n", command_number, command, param);
            crearPartido(param, L);
            break;
        }
        case 'V': {
            // Votar al partido
            printf("********************\n");
            printf("%s %c: party %s\n", command_number, command, param);
            votarPartido(param, L, votosTotales, votosNulos);
            //printf("Nulos = %d\n", votosNulos);
            //print_list(*L);
            break;
        }
        case 'S': {
            // Estadística de la lista
            printf("********************\n");
            printf("%s %c: totalvoters %s\n", command_number, command, param);
            print_list_STATS(*L, param, votosTotales, votosNulos);
            break;
        }
        case 'I': {
            // Ilegalizar partido de la lista
            printf("********************\n");
            printf("%s %c: party %s\n", command_number, command, param);
            if (findItem(param, *L) == LNULL) {
                printf("+ Error: Illegalize not_possible\n");
            }
            else {
                deleteAtPosition(findItem(param, *L), L);
                printf("* Illegalize: %s\n", param);
            }
            break;
        }
        // Para otros casos
        default: {
            printf("+ Fatal error: %c not avalaible as command\n", command);
            break;
        }
    }
}

void readTasks(char *filename, tList *L) {
    int votosTotales = 0;
    int votosNulos = 0;
    FILE *df;
    char command_number[CODE_LENGTH+1], command, param[NAME_LENGTH_LIMIT+1];

    df = fopen(filename, "r");
    if (df != NULL) {
        while (!feof(df)) {
            char format[16];
            sprintf(format, "%%%is %%c %%%is", CODE_LENGTH, NAME_LENGTH_LIMIT);
            fscanf(df,format, command_number, &command, param);
            processCommand(command_number, command, param, L, &votosTotales, &votosNulos);
        }
        fclose(df);
    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    tList *L;
    createEmptyList(L);

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name, L);

    return 0;
}