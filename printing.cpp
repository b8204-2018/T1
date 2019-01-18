#include<iostream>
using namespace std;


extern int line;
extern int column;


void printContent(const char *const *const &content) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			cout << content[i][j];
		}
		cout << endl;
	}
}