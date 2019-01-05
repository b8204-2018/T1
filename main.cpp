
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "src/reading_lib.h"
#include "src/decoding_lib.h"
#include "src/printing_lib.h"
/* Можете пожалуйста обьяснить как передавать аргументы в программу.
 * Argv и argc не использовал т.к не разобрался, поэтому просто указал в fopen путь к файлу
 *decode 5 почти работает, но первую строку превращает в нечитаемую кашу.
 * decode 8 & 9 нечитаемы.
 * на выходе с исходным файлом выводится недекодируемые символы и Signal
*/

using namespace std;

const int ERROR_NOT_ENOUGH_ARGS = -1;
const int ERROR_FILE_NOT_FOUND = -2;

int main(int argc, char **argv) {
   // if (argc <= 1) {
     //   printf("file path as argument expected");
       // return ERROR_NOT_ENOUGH_ARGS;
    //}

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
