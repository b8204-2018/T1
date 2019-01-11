#include "reading_lib.h"
#include <cstdio>
#include <iostream>

char **readFile(const char *filepath) {
    FILE *f = fopen(filepath, "r");
    if (f == nullptr){
        return nullptr;
    }
    int line, column;
    fscanf(f, "%d\t%d\n", &column, &line);
    char **press = new char* [line + 1];
    press[0] = new  char [2 * sizeof(int)];
    ((int*)(*press))[0] = column;
    ((int*)(*press))[1] = line;
    for (int i = 1; i<= line; i++){
        press[i] = new char [column];
        fscanf(f, "%s\n", press[i]);
    }
    fclose(f);
    return press;
//
// Created by Настя on 11.01.2019.
//

