#ifndef T1_DECODING_LIB_H
#define T1_DECODING_LIB_H

/*
 * Меняет местами чётные и нечётные строки
 */
void decodeStep1(char **&content) {

    int count = ((int *) (*content))[1];
    for (int i = 2; i <= count; i += 2) {
        std::swap(content[i], content[i - 1]);
    }
}
/*
 * Меняет местами чётные и нечётные столбцы
 */
void decodeStep2(char **&content){
    int count = ((int*)(*content))[0];
    for (int i = 2; i<=count; i+=2){
        std :: swap(content[i], content[i-1]);
}
}

/*
 * Заменяет каждый 3ий символ в каждой строке на каждый 7ой с конца
 */
void decodeStep3(char **&content){
    int str=((int *) (*content))[1];
    int stb= ((int*)(*content))[0];
    for (int i = 1; i<=str; i++){
        for (int j = 1; j<=stb; i++){
        if (j%3==0)&&(str>=7){
            content[i][j]=content[i][str-7];
        }
        }

    }
}


/*
 * Заменяет каждый 2ий символ в каждом столбце на каждый 11ой с конца
 */
void decodeStep4(char **&content) {
    int str = ((int *) (*content))[1];
    int stb = ((int *) (*content))[0];
    for (int j = 1; j <= stb; i++) {
        for (int i = 1; i <= str; i++) {
            if (j % 2 == 0)&&(str >= 11)
            {
                content[i][j] = content[i][str - 11];
            }
        }


    }
}

/*
 * Транспонирует массив строк(меняет строки и столбцы местами)
 */
void decodeStep5(char **&content){
    int stb = ((int *)(*content))[0], str = ((int *)(*content))[1];
    int stb1 = str, str1 = stb;
    int n = sizeof(int) * 2;
    char len [str1][stb1+1];//len str
    for (int i = 0; i < str1; i++){
        for (int j = 0; j < stb1; j++) {
            len[i][j] = content[j + 1][i];
        }
        len[i][stb1] = '\0';
    }

    for (int i = 0; i <= stb; i++){
        delete [] content[i];
    }
    delete [] content;

    content = new char* [str1 + 1];
    content[0] = new char [n];
    ((int*)(*content))[0] = len1;
    ((int*)(*content))[1] = str1;
    for (int i = 1; i <= str1; i++){
        content[i] = new char [stb1];
        content[i] = (char*) "";
    }

    for (int i = 1; i <= str1; i++){
        content[i] =len[i-1];
    }
}


/*
 * Инвертирует порядок символов в чётных строках
 */
void decodeStep6(char **&content){
    int str = ((int *) (*content))[1];
    int stb = ((int *) (*content))[0];
    for (int i = 2; i <= str; i += 2){
        for (int j = 0, k = stb - 1; j <= k; j++, k--){
            std:: swap(content[i][j], content[i][k]);
        }
    }


}

/*
 * Инвертирует порядок символов нечётных столбцов
 */
void decodeStep7(char **&content){
    int str = ((int *) (*content))[1];
    int stb = ((int *) (*content))[0];
    for (int j = 1; j <= stb; j += 2){
        for (int i = 0, k = str - 1; i <= k; i++, k--){
            std:: swap(content[i][j], content[k][j]);
        }
    }
}

/*
 * Смещает символы стоящие на чётных (i+j) вправо на 13 символов в таблице ASCII
 */
void decodeStep8(char **&content){
    int stb = ((int*)(*content))[0], str = ((int*)(*content))[1];
    for (int i = 1; i <= str; i++){
        for (int j = 0; j < stb; j++){
            if ((i+j) % 2 == 0){
                content[i][j] = (char)((short int) content[i][j] + 13);
            }
        }
    }
}

/*
 * Смещает символы стоящие на нечётных (i+j) влево на 5 символов в таблице ASCII
 */
void decodeStep9(char **&content){
    int stb = ((int*)(*content))[0], str = ((int*)(*content))[1];
    for (int i = 1; i <= str; i++){
        for (int j = 0; j < stb; j++){
            if ((i+j) % 2 == 1){
                content[i][j] = (char)((short int) content[i][j] - 5);
            }
        }
    }
}

#endif //T1_DECODING_LIB_H
