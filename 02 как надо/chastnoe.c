//------------------------------------------------------------------------------
// perimeter.c - единица компиляции, вбирающая функции вычисления периметра
//------------------------------------------------------------------------------
#include <stdio.h>
#include "extdata.h"
#include "output.c"

// Вычисление частного афоризма
double ChastnoeAforizm(void *r) {
    char* a = r;
    double X;
    double count = 0.0, x = 0.0;
    int xx = 0;
    int i = 0;

    do {
        if (a[i] == '?') {
            xx++;
        }
        i++;
    } while (xx == 0 && i < sizeof(a));
    x = i;
    for (int i = 0; i < sizeof(a); i++) {
        if (a[i] == '.') {
            a[i + 1] = '\0';
            break;
        }
    }
    for (int j = 0; j < strlen(a); j++) {
        if (a[j] == '.' || a[j] == ',' || a[j] == ';' || a[j] == ':' || a[j] == '-' ||
            a[j] == '?' || a[j] == '!' || a[j] == '(' || a[j] == ')' || a[j] == '"' ||
            a[j] == '<' || a[j] == '>' || a[j] == '{' || a[j] == '}') {
            count++;
        }
    }
    X = strlen(a) / count;
    r = a;
    return X;
}
// Вычисление частного пословицы
double ChastnoePoslovica(void* r) {
    char* a = r;
    double X;
    double count = 0.0, x = 0.0;
    int xx = 0;
    int i = 0;

    do {
        if (a[i] == '|') {
            xx++;
        }
        i++;
    } while (xx == 0 && i < sizeof(a));
    x = i;
    for (int i = 0; i < sizeof(a); i++) {
        if (a[i] == '.') {
            a[i + 1] = '\0';
            break;
        }
    }
    for (int j = 0; j < strlen(a); j++) {
        if (a[j] == '.' || a[j] == ',' || a[j] == ';' || a[j] == ':' || a[j] == '-' ||
            a[j] == '?' || a[j] == '!' || a[j] == '(' || a[j] == ')' || a[j] == '"' ||
            a[j] == '<' || a[j] == '>' || a[j] == '{' || a[j] == '}') {
            count++;
        }
    }
    X = strlen(a) / count;
    r = a;
    return X;
}
// Вычисление частного загадки
double ChastnoeZagadka(void* r) {
    char* a = r;
    double X;
    double count = 0.0, x = 0.0;
    int xx = 0;
    int i = 0;

    do {
        if (a[i] == '?') {
            xx++;
        }
        i++;
    } while (xx == 0 && i < sizeof(a));
    x = i;
    for (int i = 0; i < sizeof(a); i++) {
        if (a[i] == '.') {
            a[i + 1] = '\0';
            break;
        }
    }
    for (int j = 0; j < strlen(a); j++) {
        if (a[j] == '.' || a[j] == ',' || a[j] == ';' || a[j] == ':' || a[j] == '-' ||
            a[j] == '?' || a[j] == '!' || a[j] == '(' || a[j] == ')' || a[j] == '"' ||
            a[j] == '<' || a[j] == '>' || a[j] == '{' || a[j] == '}') {
            count++;
        }
    }
    X = strlen(a) / count;
    r = a;
    return X;
}

// Вычисление частного мудрости
double ChastnoeWisdom(void *s) {
    int k = *((int*)s);
    if(k == AFORIZM) {
        return ChastnoeAforizm(s);
    }
    else if(k == POSLOVICA) {
        return ChastnoePoslovica(s);
    }
    else if (k == ZAGADKA) {
        return ChastnoeZagadka(s);
    }
    else {
        return 0.0;
    }
}

//------------------------------------------------------------------------------
// Функция сортировки прямым выбором
// container* c, FILE* ofst
void Selection(void* c, int len, FILE* ofst) {
    void* max = c;
    void* tmp = c;
    int Max;

    for (int i = 0; i < len - 1; i++) {
        max = max + wisdomSize;     // индекс текущего элемента
        // ищем максимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < len; j++)  // для остальных элементов после i-ого
        {
            if (ChastnoeWisdom(tmp) > ChastnoeWisdom(max)) {// если элемент больше максимального,
                max = c;
                for (int k = 0; k < j; k++) {
                    max = max + wisdomSize;     // запоминаем его индекс в max
                }
            }
        }
        void* x = tmp;      // меняем местами i-ый и максимальный элементы
        tmp = max;
        max = x;
    } 

    OutContainer(c, len, ofst);
}


