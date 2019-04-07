//
// Created by maria on 16.02.19.
//



/*
 * Считывает файл, возвращая "массив" строк
 */
#include "reading_lib.h"
#include <cstdio>
#include <iostream>

char **readFile(const char *filepath) {
    FILE *f = fopen(filepath, "r");
    if (f == nullptr){
        return nullptr;
    }
    int row, column;
    fscanf(f, "%d\t%d\n", &column, &row);
    char **output = new char* [row + 1];
    output[0] = new  char [2 * sizeof(int)];
    ((int*)(*output))[0] = column;
    ((int*)(*output))[1] = row;
    for (int i = 1; i<= row; i++){
        output[i] = new char [column];
        fscanf(f, "%s\n", output[i]);
    }
    fclose(f);
    return output;
}
