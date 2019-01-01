#include "src/decoding_lib.h"

/*
 * Меняет местами чётные и нечётные строки
 */

void decodeStep1(char **&content){
    int row = ((int*)(*content))[1];
    char *buf;
    for (int i = 1; i + 1 <= row; i += 2){
        buf = content[i];
        content[i] = content[i + 1];
        content[i + 1] = buf;
    }
}

/*
 * Меняет местами чётные и нечётные столбцы
 */
void decodeStep2(char **&content){
    int column = ((int*)(*content))[0];
    int row = ((int*)(*content))[1];
    char buf;
    for (int i = 1; i <= row; i++){
        for (int j = 0; j + 1 < column; j += 2){
            buf = content[i][j];
            content[i][j] = content[i][j + 1];
            content[i][j + 1] = buf;
        }
    }
}

/*
 * Заменяет каждый 3ий символ в каждой строке на каждый 7ой с конца
 */
void decodeStep3(char **&content){
    int column = ((int*)(*content))[0];
    int row = ((int*)(*content))[1];
    int r, l;
    char buf;
    for (int i = 1; i <= row; i++){
        r = 2;
        l = column - 7;
        while ((r <= column) && (l >= 0)){
            buf = content[i][r];
            content[i][r] = content[i][l];
            content[i][l] = buf;
            r +=3;
            l -=7;
        }
    }
    
}

/*
 * Заменяет каждый 2ий символ в каждом столбце на каждый 11ой с конца
 */
void decodeStep4(char **&content){
    int column = ((int*)(*content))[0];
    int row = ((int*)(*content))[1];
    int up = 2;
    int down = row - 11;
    char buf;
    while ((up <= row) && (down >= 0)) {
        for (int j = 0; j <= column; j++){
            buf = content[up][j];
            content[up][j] = content[down][j];
            content[down][j] = buf;
        }
        up += 2;
        down -= 11;
    }
}

/*
 * Транспонирует массив строк(меняет строки и столбцы местами)
 */

void decodeStep5(char **&content){
    int column = ((int*)(*content))[0];
    int row = ((int*)(*content))[1];
    char transp[column][row];// new char* [column + 1];
    for (int i = 0; i <= column; i++){
        for (int j = 1; j <= row; j++){
            transp[i][j-1] = content[j][i];
        }
    }
    for (int i = 0; i <= row; i++){
        delete [] content[i]; //здесь на каком-то шаге SIGTRAP (Trace/breakpoint trap)
    }                           //Спасите, помогите
    delete [] content;
    content = new char* [column + 1];
    ((int*)(*content))[0] = row; //а еще однажды ему удалось пройти цикл выше и он сломался тут
    ((int*)(*content))[1] = column;
    for (int i = 1; i <= column; i++){
        content[i] = new char [row];
        content[i] = transp[i - 1];
    }
}


/*
 * Инвертирует порядок символов в чётных строках
 */
void decodeStep6(char **&content){
    int column = ((int*)(*content))[0];
    int row = ((int*)(*content))[1];
    char buf;
    for (int i = 1; i <= row; i++){
        if (i % 2 == 0){
            for (int j = 0; j < column - 1; j += 2){
                buf = content[i][j];
                content[i][j] = content[i][j + 1];
                content[i][j + 1] = buf;
            }
        }
    }

}

/*
 * Инвертирует порядок символов нечётных столбцов
 */
void decodeStep7(char **&content){
    int column = ((int*)(*content))[0];
    int row = ((int*)(*content))[1];
    char buf;
    for (int j = 0; j < column; j++) {
        if ((j + 1) % 2 == 1){
            for (int i = 1; i < row; i += 2){
                buf = content[i][j];
                content[i][j] = content[i + 1][j];
                content[i + 1][j] = buf;
            }
        }
    }
}

/*
 * Смещает символы стоящие на чётных (i+j) вправо на 13 символов в таблице ASCII
 */
void decodeStep8(char **&content){
    int column = ((int*)(*content))[0];
    int row = ((int*)(*content))[1];
    for (int i = 1; i <= row; i++){
        for (int j = 0; j < column; j++){
            if ((i + j + 1) % 2 == 0){
                content[i][j] = (char)((short)(content[i][j]) + 13);
            }
        }
    }
}

/*
 * Смещает символы стоящие на нечётных (i+j) влево на 5 символов в таблице ASCII
 */
void decodeStep9(char **&content){
    int column = ((int*)(*content))[0];
    int row = ((int*)(*content))[1];
    for (int i = 1; i <= row; i++){
        for (int j = 0; j < column; j++){
            if ((i + j + 1) % 2 == 1){
                content[i][j] = (char)((short)(content[i][j]) - 5);
            }
        }
    }
}
