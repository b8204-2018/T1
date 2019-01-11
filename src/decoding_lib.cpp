#include <iostream>
#include "decoding_lib.h"
#include "printing_lib.h"

using namespace std;

/*
 * Меняет местами чётные и нечётные строки
 */
void decodeStep1(char **&content){

    int kol_ = ((int*)(*content))[1];
    if (kol_ == 1)
        cout << " Don't change" << endl;
    if (kol_ % 2 == 0)
    {
        for (int i = 2; i <= kol_; i = i + 2) {
            swap(content[i], content[i - 1]);
        }
    }
    else {
        for (int i = 2; i <= kol_ -1; i = i + 2) {
            swap(content[i], content[i - 1]);
        }
    }
}


