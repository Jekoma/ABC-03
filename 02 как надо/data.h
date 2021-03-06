#ifndef __data__
#define __data__

//------------------------------------------------------------------------------
// data.h - Описание данных бестиповой программы
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Раздел констант
//------------------------------------------------------------------------------

// Константа, определяющая размер символа
int const charSize = sizeof(char);
// Константа, задающая размер для афоризма
int const aforizmSize = 20 * sizeof(char);
// Константа, задающая размер для пословицы
int const poslovicaSize = 20 * sizeof(char);
// Константа, задающая размер для загадки
int const zagadkaSize = 20 * sizeof(char);
// Константа, задающая размер для мудрости
int const wisdomSize = sizeof(int) + aforizmSize;
// Константа, определяющая размерность массива фигур
int const maxSize = 10000 * wisdomSize;
// Константа, задающая признак афоризма
int const AFORIZM= 1;
// Константа, задающая признак пословицы
int const POSLOVICA = 2;
// Константа, задающая признак загадки
int const ZAGADKA = 3;

//------------------------------------------------------------------------------
// Раздел данных
//------------------------------------------------------------------------------

// Количество элементов в массиве
// int len = 0;

//------------------------------------------------------------------------------
// Раздел выделяемой памяти
//------------------------------------------------------------------------------

// Массив используемый для хранения данных
//int cont[160000];



//------------------------------------------------------------------------------
// Описание используемых функций
//------------------------------------------------------------------------------

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst);
// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size);
// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst);
// Вычисление суммы периметров всех фигур в контейнере
void Selection(void *c, int len, FILE *ofst);

#endif
