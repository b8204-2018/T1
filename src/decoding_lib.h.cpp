#include <cstring>
#include <cstdio>
#include <iostream>
#include "decoding_lib.h"

using namespace std;

/*
 * Меняет местами чётные и нечётные строки
 */
void decodeStep1(char **&content) {
    size_t sybolsInLine = ((size_t *) (*content))[0];
    size_t numbString = ((size_t *) (*content))[1];
    char elemSwap;
    for (size_t i = 2; i <= numbString; i += 2)
        for (size_t j = 1; j <= sybolsInLine; j++) {
            elemSwap = content[i][j];
            content[i][j] = content[i - 1][j];
            content[i - 1][j] = elemSwap;
        }
}

/*
 * Меняет местами чётные и нечётные столбцы
 */
void decodeStep2(char **&content) {
    size_t sybolsInLine = ((size_t *) (*content))[0];
    size_t numbString = ((size_t *) (*content))[1];
    char elemSwap;
    for (size_t j = 2; j <= sybolsInLine; j += 2)
        for (size_t i = 1; i <= numbString; i++) {
            elemSwap = content[i][j];
            content[i][j] = content[i][j - 1];
            content[i][j - 1] = elemSwap;
        }
}

/*
 * Заменяет каждый 3ий символ в каждой строке на каждый 7ой с конца
 */
void decodeStep3(char **&content) {
    size_t sybolsInLine = ((size_t *) (*content))[0];
    size_t numbString = ((size_t *) (*content))[1];
    for (int i = 1; i <= numbString; i++) {
        int j = 1, k = sybolsInLine;
        while (((j += 2) < sybolsInLine) && ((k -= 6) >= 0)) {
            swap(content[i][j], content[i][k]);
            j += 2;
            k -= 6;
        }
    }
}

/*
 * Заменяет каждый 2ий символ в каждом столбце на каждый 11ой с конца
 */
void decodeStep4(char **&content) {
    size_t sybolsInLine = ((size_t *) (*content))[0];
    size_t numbString = ((size_t *) (*content))[1];
    for (int i = 1; i <= sybolsInLine; i++) {
        int j = 1, k = numbString;
        while (((j += 1) <= sybolsInLine) && ((k -= 10) >= 0)) {
            swap(content[j][i], content[k][i]);
            j += 1;
            k -= 10;
        }
    }
}

/*
 * Транспонирует массив строк(меняет строки и столбцы местами)
 */
void decodeStep5(char **&content) {
    size_t sybolsInLine = ((size_t *) (*content))[0];
    size_t numbString = ((size_t *) (*content))[1];
    size_t numbString1 = sybolsInLine;
    size_t sybolsInLine1 = numbString;
    char **matrixTrans = new char *[numbString1 + 1];
    size_t Razmernost = sizeof(size_t) * 2;
    matrixTrans[0] = new char[Razmernost];
    ((size_t *) (*matrixTrans))[0] = sybolsInLine1;
    ((size_t *) (*matrixTrans))[1] = numbString1;
    for (size_t j = 1; j <= numbString1; j++) {
        size_t k = 1;
        for (size_t i = 1; i <= sybolsInLine1; i++) {
            matrixTrans[j][k] = content[j][i];
            k++;
        }
    }
    content = matrixTrans;
}

/*
 * Инвертирует порядок символов в чётных строках
 */
void decodeStep6(char **&content) {
    size_t sybolsInLine = ((size_t *) (*content))[0];
    size_t numbString = ((size_t *) (*content))[1];
    for (int i = 2; i <= numbString; i += 2) {
        int j = 1, k = sybolsInLine;
        while (((j) < sybolsInLine)) {
            swap(content[i][j], content[i][k]);
            j++;
            k--;
        }
    }
}

/*
 * Инвертирует порядок символов нечётных столбцов
 */
void decodeStep7(char **&content) {
    size_t sybolsInLine = ((size_t *) (*content))[0];
    size_t numbString = ((size_t *) (*content))[1];
    for (int i = 1; i <= sybolsInLine; i += 2) {
        int j = 1, k = numbString;
        while (((j) <= numbString / 2)) {
            swap(content[j][i], content[k][i]);
            j++;
            k--;
        }
    }
}

/*
 * Смещает символы стоящие на чётных (i+j) вправо на 13 символов в таблице ASCII
 */
void decodeStep8(char **&content) {

}

/*
 * Смещает символы стоящие на нечётных (i+j) влево на 5 символов в таблице ASCII
 */
void decodeStep9(char **&content) {

}