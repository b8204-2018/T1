#include <cstring>
#include <cstdio>
#ifndef T1_READING_LIB_H
#define T1_READING_LIB_H

/*
 * Считывает файл, возвращая "массив" строк
 */
char **readFile(const char *filepath){
    int len, count;
    FILE *f = fopen(filepath, "r");
    if (f == NULL){
        return nullptr;
    }
    fscanf(f, "%d\t%d\n", &len, &count);
    char **str = new char* [count + 1];
    int n = sizeof(int)*2;
    str[0] = new char[n];
    ((int*) (*str))[0] = len;
    ((int*) (*str))[1] = count;
    for (int i = 1; i <= count; i++){
        str[i] = new char [len];
        fscanf(f, "%s", str[i]);
    }
    fclose(f);
    return str;

}

#endif //T1_READING_LIB_H
