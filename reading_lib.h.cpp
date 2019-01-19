#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "reading_lib.h"

using namespace std;

char **readFile(const char *filepath){
    ifstream File;
    File.open(filepath, ios_base::in);
    if (File.is_open()){
        size_t sybolsInLine, numbString;
        File >> sybolsInLine;
        File >>  numbString;
        char **matrix = new char *[numbString + 1];
        size_t Razmernost = sizeof(size_t)*2;
        matrix[0] = new char[Razmernost];
        ((size_t*)(*matrix))[0] = sybolsInLine;
        ((size_t*)(*matrix))[1] = numbString;
        string str;
        getline(File, str);
        if (sybolsInLine != 0 && numbString != 0){
            for (size_t i = 1; i < numbString + 1; i++){
                getline(File, str);
                matrix[i] = new char[sybolsInLine + 1];
                for (size_t j = 1; j < sybolsInLine + 1; j++)
                    matrix[i][j] = str[j - 1];
            }
            File.close();
            return matrix;
        }
    }
    else{
        cout << "Error, File not found!";
        File.close();
        return nullptr;
    }
}