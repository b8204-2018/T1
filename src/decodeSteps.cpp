#include <iostream>

extern int w; //кол-во столбцов
extern int l; //кол-во строк

void decodeStep1(char **content) {
    char buf;
    for (int i = 0; i < l - 1; i++) {
        for (int j = 0; j < w; j++) {
            buf = content[i][j];
            content[i][j] = content[i + 1][j];
            content[i + 1][j] = buf;
        }
    }
}

void decodeStep2(char **content) {
    char buf;
    for (int i = 0; i < w - 1; i++) {
        for (int j = 0; j < l; j++) {
            buf = content[j][i];
            content[j][i] = content[j][i + 1];
            content[j][i + 1] = buf;
        }
    }
}

void decodeStep3(char **content) {}

void decodeStep4(char **content) {}

void decodeStep5(char **content) {}

void decodeStep6(char **content) {}

void decodeStep7(char **content) {}

void decodeStep8(char **content) {}

void decodeStep9(char **content) {}
