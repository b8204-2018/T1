#include <cstdio>  //стандартный заголовочный файл ввода-вывода
#include "reading_lib.h"
#include <cstring>  //определяет несколько функций для обработки Cи-строк и массивов

char **readFile(const char *filepath) {  //filepath - the way to the file
    int long_, kol_;
    FILE *f;
    f = fopen(filepath, "r");  //открываем только для чтения
    if (f == NULL){
        return nullptr;
    }
    fscanf(f, "%d\t%d\n", &long_, &kol_); //long_ - колв-во столбцов, длина строки; kol_ - кол-во строк
    char **str = new char* [sizeof(int)*2];
    memcpy(str[0], &long_, sizeof(int));
    memcpy(str[0] + sizeof(int), &kol_, sizeof(int));
    for (int i = 1; i <= kol_; i++){
        str[i] = new char [long_];
        fscanf(f, "%s", str[i]);
    }
    fclose(f);
    return str;
}