//------------------------------------------------------------------------------
// input.c - единица компиляции, вбирающая в себя все функции ввода данных
//------------------------------------------------------------------------------

#include <stdio.h>

#include "extdata.h"

// Ввод параметров афоризма из файла
void InAforizm(void *r, FILE *ifst) {
    fscanf(ifst, "%d%s", (int*)r, (char*)(r*charSize));
}

// Ввод параметров пословицы из файла
void InPoslovica(void* r, FILE* ifst) {
    fscanf(ifst, "%d%s", (int*)r, (char*)(r * charSize));
}

// Ввод параметров загадки из файла
void InZagadka(void* r, FILE* ifst) {
    fscanf(ifst, "%d%s", (int*)r, (char*)(r * charSize));
}

// Ввод параметров обобщенной фигуры из файла
int InWisdom(void *s, FILE *ifst) {
    int k;
    fscanf(ifst, "%d", &k);
    switch(k) {
        case 1:
            *((int*)s) = AFORIZM;
            InAforizm(s + charSize, ifst);
            return 1;
        case 2:
            *((int*)s) = POSLOVICA;
            InPoslovica(s + charSize, ifst);
            return 1;
        case 3:
            *((int*)s) = ZAGADKA;
            InZagadka(s + charSize, ifst);
            return 1;
        default:
            return 0;
    }
}

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst) {
    void *tmp = c;
    while(!feof(ifst)) {
        if(InWisdom(tmp, ifst)) {
            tmp = tmp + wisdomSize;
            (*len)++;
        }
    }
}
