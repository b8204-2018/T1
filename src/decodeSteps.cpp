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

void decodeStep3(char **content) {

    for (int j = 0; j<= l-1; j++) {
        int k = 2;
        int p= w - 7;
        while ((k <= w-1) && (p >= 0)) {
            std:: swap(content[j][k], content[j][p]);
            k += 3;
            p -= 7;
        }
    }
}

void decodeStep4(char **content) {
    for (int i = 0; i<= w-1; i++) {
        int k = 1;
        int p= l - 11;
        while ((k <= l-1) && (p >= 0)) {
            std:: swap(content[k][i], content[p][i]);
            k += 2;
            p -= 11;
        }
    }
}

void decodeStep5(char **content) {}

void decodeStep6(char **content) {
    for (int i = 1; i <= l - 1; i += 2) {
        int j = 0;
        int k = 0;
        int p = w-1;
        while (j <= w / 2 - 1) {
            std:: swap(content[i][k],content[i][p]);
            k ++;
            p --;
            j++;
        }


    }

}

void decodeStep7(char **content) {}

void decodeStep8(char **content) {}

void decodeStep9(char **content) {}
