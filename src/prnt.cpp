#include <fstream>
#include <iostream>

using namespace std;

extern int w; //кол-во столбцов
extern int l; //кол-во строк

void printContent(const char **content) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            cout << content[i][j];
        }
        cout << "" << endl;
    }
}
