
#include <iostream>
#include "decoding_lib.h"
#include "printing_lib.h"

/*
 * Меняет местами чётные и нечётные строки
 */

void decodeStep1(char **&content){

    int count = ((int*)(*content))[1];//число строк 
    for (int i = 2; i<=count; i+=2){
        std :: swap(content[i], content[i-1]);
    }
}

/*
 * Меняет местами чётные и нечётные столбцы
 */
void decodeStep2(char **&content){

    int len = ((int*)(*content))[0], count = ((int*)(*content))[1];
    for (int i = 1; i < len; i+=2){
        for (int j = 1; j <= count; j++){
            std:: swap(content[j][i-1], content[j][i]);
        }
    }
}

/*
 * Заменяет каждый 3ий символ в каждой строке на каждый 7ой с конца
 */
void decodeStep3(char **&content){

    int len = ((int*)(*content))[0], count = ((int*)(*content))[1];
    for (int i = 1; i <=count ; i++){
        int j = 2, k = len - 7;
        while ((j < len) && (k >= 0)){
            content[i][j]= content[i][k]; //присваивает 3 элементу тут
            j += 3;
            k -= 7;
        }
    }
}

/*
 * Заменяет каждый 2ий символ в каждом столбце на каждый 11ой с конца
 */
void decodeStep4(char **&content){

    int len = ((int*)(*content))[0], count = ((int*)(*content))[1];
    for (int i = 0; i < len; i++){
        int j = 2, k = count - 11;
        while ((j <= count) && (k > 0)){
            content[j][i]= content[k][i];
            j += 2;
            k -= 11;
        }
    }
}

/*
 * Транспонирует массив строк(меняет строки и столбцы местами)
 */
void decodeStep5(char **&content) {

    int len = ((int *)(*content))[0], count = ((int *)(*content))[1];
    int len1 = count, count1 = len;
    int n = sizeof(int) * 2;
    char str [count1][len1+1];//новый массив 
    for (int i = 0; i < count1; i++){
                for (int j = 0; j < len1; j++) {
            str[i][j] = content[j + 1][i];
        }
        str[i][len1] = '\0';//конец строки
    }

    for (int i = 0; i <= count; i++){
        delete [] content[i];
    }
    delete [] content;

    content = new char* [count1 + 1];
    content[0] = new char [n];
    ((int*)(*content))[0] = len1;
    ((int*)(*content))[1] = count1;
    for (int i = 1; i <= count1; i++){
        content[i] = new char [len1];
        content[i] = (char*) "";//приведение типов
    }

    for (int i = 1; i <= count1; i++){
            content[i] = str[i-1];
    }
}

/*
 * Инвертирует порядок символов в чётных строках
 */
void decodeStep6(char **&content){

    int len = ((int*)(*content))[0], count = ((int*)(*content))[1];
    for (int i = 2; i <= count; i += 2){
		for (int j = 0, k = len - 1; j <= k; j++, k--) {
            std:: swap(content[i][j], content[i][k]);
        }
    }
}

/*
 * Инвертирует порядок символов нечётных столбцов
 */
void decodeStep7(char **&content){

    int len = ((int*)(*content))[0], count = ((int*)(*content))[1];
    for (int i = 0; i < len; i += 2){
        for (int j = 1, k = count; j <= k; j++, k--){
            std:: swap(content[j][i], content[k][i]);
        }
    }

}

/*
 * Смещает символы стоящие на чётных (i+j) вправо на 13 символов в таблице ASCII
 */
void decodeStep8(char **&content){

    int len = ((int*)(*content))[0], count = ((int*)(*content))[1];
    for (int i = 1; i <= count; i++){
        for (int j = 0; j < len; j++){
            if ((i+j) % 2 == 0){
                content[i][j] = (char)((short int) content[i][j] + 13);//short int выделение малой памяти
                //к числу прибавляем 13 и потом преобразуем в  char         
			}
        }
    }
}

/*
 * Смещает символы стоящие на нечётных (i+j) влево на 5 символов в таблице ASCII
 */
void decodeStep9(char **&content){

    int len = ((int*)(*content))[0], count = ((int*)(*content))[1];
    for (int i = 1; i <= count; i++){
        for (int j = 0; j < len; j++){
            if ((i+j) % 2 == 1){
                content[i][j] = (char)((int) content[i][j] - 5);
            }
        }
    }
}