//------------------------------------------------------------------------------
// output.c - единица компиляции, вбирающая в себя все функции вывода данных
//------------------------------------------------------------------------------

#include <stdio.h>

#include "extdata.h"

// Вычисление частного афоризма
double ChastnoeAforizm(void *r);

// Вывод параметров афоризма в файл
void OutAforizm(void *r, FILE *ofst) {    
    fprintf(ofst, "%d) It is Aforizm: input = %s CHASTNOE = %lf OTVET = %s \n",
            *((int*)r), *((char*)r), ChastnoeAforizm(r), r);
}

// Вычисление частного пословицы
double ChastnoePoslovica(void *t);

// Вывод параметров пословицы в файл
void OutPoslovica(void *t, FILE *ofst) {
    fprintf(ofst, "%d) It is Poslovica: input = %s CHASTNOE = %lf OTVET = %s \n",
        *((int*)t), *((char*)t), ChastnoeAforizm(t), t);
}

// Вычисление частного загадки
double ChastnoeZagadka(void *t);

// Вывод параметров загадки в файл
void OutZagadka(void *z, FILE *ofst) {
    fprintf(ofst, "%d) It is Poslovica: input = %s CHASTNOE = %lf OTVET = %s \n",
        *((int*)z), *((char*)z), ChastnoeAforizm(z), z);
}

// Вывод параметров текущей мудрости в файл
void OutWisdom(void *s, FILE *ofst) {
    int k = *((int*)s);
    char* h = *(char*)s * charSize;
    if(k == AFORIZM) {
        OutAforizm(h, ofst);
    }
    else if(k == POSLOVICA) {
        OutPoslovica(h, ofst);
    }
    else if (k == ZAGADKA) {
        OutZagadka(h, ofst);
    }
    else {
        fprintf(ofst, "Incorrect figure!\n");
    }
}

// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst) {
    void *tmp = c;
    fprintf(ofst, "Container contains %d elements.\n", len);
    for(int i = 0; i < len; i++) {
        fprintf(ofst, "%d: ", i);
        OutWisdom(tmp, ofst);
        tmp = tmp + wisdomSize;
    }
}
