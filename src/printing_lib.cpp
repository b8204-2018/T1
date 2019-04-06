//
// Created by maria on 16.02.19.
//



/*
 * Выводит в стандартный поток вывода контент
 */
#include <fstream>
#include <iostream>

using namespace std;

extern int w; //кол-во столбцов
extern int l; //кол-во строк

void printContent(const char *const *const &content) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            cout << content[i][j];
        }
        cout << "" << endl;
    }
}
