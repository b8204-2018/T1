#ifndef T1_READING_LIB_H
#define T1_READING_LIB_H
#include <iostream>
#include <fstream>
#include <string>

char **readFile(const char *filepath);
{
    int w=0, l=0;
    ifstream File;
    File.open(filepath, ios_base::in);
    if (File.is_open()) {
        File >> w;
        File >> l;
        string str;
        if (w != 0 && l != 0) {
            char **data = new char *[l];
            for (int i = 0; i <= l; i++) {
                getline(File, str);
                data[i] = new char[w];
                for (int j = 0; j <= w; j++) {
                    data[i][j]=str[j];
                }
            }
        }
    }
    File.close();
    return NULL;
}

#endif //T1_READING_LIB_H
