
#include <iostream>
#include "printing_lib.h"

void printContent(const char **content){
    int count = ((int*)(*content))[1];
    for (int i = 1; i <= count; i++){
        printf("%s\n", content[i]);
    }
}
