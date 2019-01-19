#ifndef T1_DECODING_LIB_H
#define T1_DECODING_LIB_H

/*
 * Меняет местами чётные и нечётные строки
 */
void decodeStep1(char **&content);

/*
 * Меняет местами чётные и нечётные столбцы
 */
void decodeStep2(char **&content);

/*
 * Заменяет каждый 3ий символ в каждой строке на каждый 7ой с конца
 */
void decodeStep3(char **&content);

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

#endif //T1_DECODING_LIB_H
