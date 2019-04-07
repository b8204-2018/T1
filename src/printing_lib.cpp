//
// Created by maria on 16.02.19.
//



/*
 * Выводит в стандартный поток вывода контент
 */
#include "src/printing_lib.h"
#include <iostream>

void printContent(const char** content){
    int row = ((int*)(*content))[1];
    for (int i = 1; i <= row; i++){
        printf("%s\n", content[i]);
    }
}
