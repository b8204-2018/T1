#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "src/reading_lib.h"
#include "src/decoding_lib.h"
#include "src/printing_lib.h"
using namespace std;

const int ERROR_NOT_ENOUGH_ARGS = -1;
const int ERROR_FILE_NOT_FOUND = -2;

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("filepath as argument expected");
        return ERROR_NOT_ENOUGH_ARGS;
    }

    char **content = readFile(argv[1]);

    if (content == nullptr) {
        return ERROR_FILE_NOT_FOUND;
    }
    cout << "Matrix in this file: " << endl;
    printContent((const char **) content);

    cout << "decodeStep1 done. Your matrix: "<< endl;
    decodeStep1(content);
    printContent((const char **) content);

    cout << "decodeStep2 done. Your matrix: "<< endl;
    decodeStep2(content);
    printContent((const char **) content);

    cout << "decodeStep3 done. Your matrix: "<< endl;
    decodeStep3(content);
    printContent((const char **) content);

    cout << "decodeStep4 done. Your matrix: "<< endl;
    decodeStep4(content);
    printContent((const char **) content);

  //  cout << "decodeStep5 done. Your matrix: "<< endl;
  //  decodeStep5(content);
  //  printContent((const char **) content);

    cout << "decodeStep6 done. Your matrix: "<< endl;
    decodeStep6(content);
    printContent((const char **) content);

    cout << "decodeStep7 done. Your matrix: "<< endl;
    decodeStep7(content);
    printContent((const char **) content);

    cout << "decodeStep8 done. Your matrix: "<< endl;
    decodeStep8(content);
    printContent((const char **) content);

    cout << "decodeStep9 done. Your matrix: "<< endl;
    decodeStep9(content);
    printContent((const char **) content);

    return 0;
}
