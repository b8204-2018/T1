#include <iostream>
#include "decoding_lib.h"
#include<string.h>

using namespace std;

void decodeStep1(char **content) {
    int count = ((int *) (*content))[1];
    if (count % 2 != 0) {
        for (int i = 1; (i + 1) <= count - 1; i += 2) {
            swap(content[i], content[i + 1]);
        }
    } else {
        for (int i = 1; (i + 1) <= count; i += 2) {
            swap(content[i], content[i + 1]);
        }
    }
}

void decodeStep2(char **content) {
    int len = ((int *) (*content))[0];
    int count = ((int *) (*content))[1];
    for (int j = 1; j <= count; j++) {
        for (int i = 0; i <= len; i += 2) {
            if (i + 1 < len) {
                swap(content[j][i + 1], content[j][i]);
            }
        }
    }

}

void decodeStep3(char **content) {
    int len = ((int *) (*content))[0];
    int count = ((int *) (*content))[1];
    int k = len - 7;
    int i = 3;
    for (int j = 1; j <= count; j++) {
        swap(content[j][i],
             content[j][k]);
    }
}

void decodeStep4(char **content) {
    int len = ((int *) (*content))[0];
    int count = ((int *) (*content))[1];
    int k = len - 11;
    int i = 1;
    for (int j = 1; j <= count; j++) {
        swap(content[j][i],
             content[j][k]);
    }
}

void decodeStep5(char **&content) {
    int len = ((int *) (*content))[0];
    int count = ((int *) (*content))[1];
    char **str = new char *[count + 1];
    for (int i = 0; i <= len; i++) {
        str[i] = new char[count];
        for (int j = 0; j < count; j++) {
            str[i][j] = content[j + 1][i];
        }
        str[i][count] = '\0';
    }

    for (int i = 0; i <= count; i++) {
        delete[] content[i];
    }
    delete[] content;

    count = count + len;
    len = count - len;
    count = count - len;

    content = new char *[count + 1];
    int N = sizeof(int) * 2;
    content[0] = new char[N];
    ((int *) (*content))[0] = len;
    ((int *) (*content))[1] = count;
    for (int i = 1; i <= count; i++) {
        content[i] = new char[len];
        content[i] = "";
        content[i] = str[i - 1];
    }
}


void decodeStep6(char **content) {
    int len = ((int *) (*content))[0];
    int count = ((int *) (*content))[1];
    for (int i = 2; i <= count; i += 2) {
        for (int j = 0, l = len - 1; j <= len / 2; j++, l--) {
            swap(content[i][j], content[i][l]);
        }
    }
}

void decodeStep7(char **content) {
    int len = ((int *) (*content))[0];
    int count = ((int *) (*content))[1];
    if ((len % 2) != 0) {
        for (int j = 0; j <= len / 2; j += 2) {
            for (int i = 1, l = count; i <= l; i++, l--) {
                swap(content[i][j], content[l][j]);
            }
        }
    }
}

void decodeStep8(char **content) {
    int len = ((int *) (*content))[0];
    int count = ((int *) (*content))[1];

    for (int i = 1; i <= count; i++) {
        for (int j = 0; j < len; j++) {
            if (((i + j) % 2) == 0) {
                int k = (int) content[i][j];
                k = k + 13;
                content[i][j] = (char) k;
            }

        }
    }
}

void decodeStep9(char **content) {
    int len = ((int *) (*content))[0];
    int count = ((int *) (*content))[1];
    for (int i = 1; i <= count; i++) {
        for (int j = 0; j < len; j++) {
            if (((i + j) % 2) != 0) {
                int k = (int) content[i][j];
                k = k - 5;
                content[i][j] = (char) k;
            }

        }
    }
}