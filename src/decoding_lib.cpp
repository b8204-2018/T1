//
// Created by maria on 16.02.19.
//


#include <iostream>

extern int w; //кол-во столбцов
extern int l; //кол-во строк


/*
 * Меняет местами чётные и нечётные строки
 */
void decodeStep1(char **&content) {
char buf;
for (int i = 0; i < l - 1; i++) {
for (int j = 0; j < w; j++) {
buf = content[i][j];
content[i][j] = content[i + 1][j];
content[i + 1][j] = buf;
}
}
}

/*
 * Меняет местами чётные и нечётные столбцы
 */
void decodeStep2(char **&content){
char buf;
for (int i = 0; i < w - 1; i++) {
for (int j = 0; j < l; j++) {
buf = content[j][i];
content[j][i] = content[j][i + 1];
content[j][i + 1] = buf;
}
}
}

/*
 * Заменяет каждый 3ий символ в каждой строке на каждый 7ой с конца
 */
void decodeStep3(char **&content){
for (int j = 0; j <= l - 1; j++) {
int k = 2;
int p = w - 7;
while ((k <= w - 1) && (p >= 0)) {
std::swap(content[j][k], content[j][p]);
k += 3;
p -= 7;
}
}
}


/*
 * Заменяет каждый 2ий символ в каждом столбце на каждый 11ой с конца
 */
void decodeStep4(char **&content);

/*
 * Транспонирует массив строк(меняет строки и столбцы местами)
 */
void decodeStep5(char **&content);

/*
 * Инвертирует порядок символов в чётных строках
 */
void decodeStep6(char **&content);

/*
 * Инвертирует порядок символов нечётных столбцов
 */
void decodeStep7(char **&content);

/*
 * Смещает символы стоящие на чётных (i+j) вправо на 13 символов в таблице ASCII
 */
void decodeStep8(char **&content);

/*
 * Смещает символы стоящие на нечётных (i+j) влево на 5 символов в таблице ASCII
 */
void decodeStep9(char **&content);

