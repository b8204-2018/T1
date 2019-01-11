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


/*
 * Заменяет каждый 3ий символ в каждой строке на каждый 7ой с конца
 */
void decodeStep3(char **&content) {

    int long_ = ((int *) (*content))[0], kol_ = ((int *) (*content))[1];
    int a = 2;
    int b = long_ - 6;
    if (long_ < 8) {
        cout << " Don't change" << endl;
    }
    else {
        for (int i = 1; i <= kol_; i++) {
           while (b >= 0)  {
                swap(content[i][a], content[i][b]);
                a = a + 3;
                b = b - 7;
            }
        }
    }
}