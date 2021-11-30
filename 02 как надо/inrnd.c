//------------------------------------------------------------------------------
// inrnd.c - единица компиляции, вбирающая функции генерации случайных данных
//------------------------------------------------------------------------------
#define N 16
#define SET "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm123456789,<>""'';:!(){}"

#include <stdlib.h>
#include "extdata.h"
#include <string.h>

// rnd.c - содержит генератор случайных строк длинной в 15
const char* Random() {
    char s[N];
    int i, set_len;
    set_len = strlen(SET);
    for (i = 0; i < N - 1; i++)
    {
        s[i] = SET[rand() % set_len];
    }
    s[14] = '.';
    s[15] = '\0';
    return s;
}

// Случайный ввод параметров афоризма
void InRndAforizm(void *r) {
    char* x = Random();
    x[8] = ' ';
    x[9] = '|';
    x[10] = ' ';
    (char*)(r + 15 * charSize) = x;
}

// Случайный ввод параметров пословицы
void InRndPoslovica(void* r) {
    char* x = Random();
    x[8] = ' ';
    x[9] = '-';
    x[10] = ' ';
    (char*)(r + 15 * charSize) = x;
}

// Случайный ввод параметров загадки
void InRndZagadka(void* r) {
    char* x = Random();
    x[8] = ' ';
    x[9] = '?';
    x[10] = ' ';
    (char*)(r + 15 * charSize) = x;
}

// Случайный ввод обобщенной мудрости
int InRndWisdom(void *s) {
    int k = rand() % 3 + 1;
    switch(k) {
        case 1:
            *((int*)s) = AFORIZM;
            InRndAforizm(s + charSize);
            return 1;
        case 2:
            *((int*)s) = POSLOVICA;
            InRndPoslovica(s + charSize);
            return 1;
        case 3:
            *((int*)s) = ZAGADKA;
            InRndZagadka(s + charSize);
            return 1;
        default:
            return 0;
    }
}

// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size) {
    void *tmp = c;
    while(*len < size) {
        if(InRndWisdom(tmp)) {
            tmp = tmp + wisdomSize;
            (*len)++;
        }
    }
}
