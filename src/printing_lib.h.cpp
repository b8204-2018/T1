#include <iostream>
#include "printing_lib.h"

using namespace std;

void printContent(const char **content) {
    size_t sybolsInLine = ((size_t *)(*content))[0];
    size_t numbString = ((size_t*)(*content))[1];
    for (size_t i = 1; i < numbString + 1; i++) {
        for (size_t j = 1; j < sybolsInLine + 1; j++){
            cout << content[i][j];
        }
        cout << endl;
    }
}
