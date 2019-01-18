
#include <cstring>
#include <cstdio>
#include "reading_lib.h"


char **readFile(const char *filepath) {
    int len, count;
    FILE *f = fopen(filepath, "r");//связывает переменную с файлом создает файл для записи 
    //проверяет пустой файл
	if (f == NULL){
        return nullptr;
    }
    fscanf(f, "%d\t%d\n", &len, &count); //len столбцы count строки 
    char **str = new char* [count + 1];//указатель на 2мерный массив 
    int n = sizeof(int)*2;//возращает  размер инт умнжт на 2 
    str[0] = new char[n];//создание первой строки 
    ((int*) (*str))[0] = len;//преобразовывает char к int 
    ((int*) (*str))[1] = count;//преобразовывает char к int 
    for (int i = 1; i <= count; i++){
        str[i] = new char [len];
        fscanf(f, "%s", str[i]);//считывает строку из файла и заносит в массив
    }
    fclose(f);
    return str;

}