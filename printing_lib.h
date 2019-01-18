#ifndef T1_PRINTING_LIB_H
#define T1_PRINTING_LIB_H
#include <iostream>

/*
 * Выводит в стандартный поток вывода контент
 */
void printContent(const char **content){
    int count = ((int*)(*content))[1];
    for (int i = 1; i <= count; i++){
        printf("%s\n", content[i]);
    }
}

#endif //T1_PRINTING_LIB_H
