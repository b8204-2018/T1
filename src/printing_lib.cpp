#include "reading_lib.h"
#include <iostream>
#include <cstdio>

using namespace std;

void printContent(const char **content) {
    int count = ((int *) (*content))[1];
    int len =((int*)(*content))[0];
    cout << count <<' '<<len<< endl;
    for (int i = 1; i <= count; i++) {
        printf("%s\n", content[i]);
    }

}

