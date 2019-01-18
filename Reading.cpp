#include <cstring>
#include <cstdio>
#include <fstream>
#include<string>
#include"reading_lib.h"
#include<iostream>

using namespace std;
int column, line;

char **readFile(const char *filepath) {
	
	string buff;
	ifstream infile("file_example.txt");
	if (infile) {
		column = 0;
		line = 0;

		infile >> column >> line;
		
		if ((column != 0) && (line != 0)) {
			char **str = new char *[line]; // создаем двойной указатель на char.
			for (int i = 0; i <= line; i++) {
				infile >> buff;
				str[i] = new char[column]; //для каждого line свой column
				for (int j = 0; j <= column; j++) {
					str[i][j] = buff[j];
				}
			}
			return str;
		}
	}
	else if (!infile) { cout << "не удалось открыть файл\n"; return nullptr; }
}
