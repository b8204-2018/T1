#include <cstring>
#include <cstdio>
#include <cstdlib>

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

    decodeStep1(content);
    decodeStep2(content);
    decodeStep3(content);
    decodeStep4(content);
    decodeStep5(content);
    decodeStep6(content);
    decodeStep7(content);
    decodeStep8(content);
    decodeStep9(content);
    printContent((const char **) content);

    return 0;
}