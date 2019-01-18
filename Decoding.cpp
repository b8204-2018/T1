#include <iostream>
#include"decoding_lib.h"
#include"printing_lib.h"

using namespace std;
extern int line ;
extern int column;
/*
 * ������ ������� ������ � �������� ������
 */
void decodeStep1(char **&content) {
    for (int i = 1; i < line; i+=2) {
		swap(content[i], content[i - 1]);
	}
}

/*
 * ������ ������� ������ � �������� �������
 */
void decodeStep2(char **&content){
	for (int i = 0; i < line; i ++) {
		for (int j=1; j<column; j+=2)
		swap(content[i][j], content[i][j-1]);
	}

}

/*
 * �������� ������ 3�� ������ � ������ ������ �� ������ 7�� � �����
 */
void decodeStep3(char **&content) {
	setlocale(LC_ALL, "rus");
	int b = 7;
	
	for (int i = 0; i < line; i++) {
		try {
			if (column < 7) {
				throw -1;
			}
			for (int j = 2; j < column; j += 3) {
			
				content[i][j] = content[i][column - b];
				b += 7;
			}
		}
		catch (int j) {
			cout << "������ � " << j << " ����� �� ������� �������" << endl; return;
		}
	}
}

/*
 * �������� ������ 2�� ������ � ������ ������� �� ������ 11�� � �����
 */
void decodeStep4(char **&content) {
	setlocale(LC_ALL, "rus");
	int b = 11;

	for (int i = 2; i < line; i++) {
		try {
			if (line < 11) {
				throw - 1;
			}
			for (int j = 0; j < column; j++) {
				
				content[i][j] = content[line - b][j];
				b += 7;
			}
		}
		catch (int j) {
			cout << "������ � " << j << " ����� �� ������� �������" << endl; return;
		}
	}
}

/*
 * ������������� ������ �����(������ ������ � ������� �������)
 */


void decodeStep5(char **&content) {
	char **newcontent = new char *[column];
	int newline = column; //newline=6
	int newcolumn = line; //newcolumn=5
	

	for (int i = 0; i < column; i++) {
		newcontent[i] = new char[line];
	}
	for (int i = 0; i < newcolumn; i++) {
		
		for (int j = 0; j < newline; j++) {
			
			newcontent[j][i] = content[i][j];
		}
	}

	delete [] content;
	content = new char*[column];
	for (int i = 0; i < column; i++) {
		content[i] = new char[line];
		content[i] = newcontent[i];
	}
	
	column = newline;
	line = newcolumn;
	delete newcontent;
}

/*
 * ����������� ������� �������� � ������ �������
 */
void decodeStep6(char **&content) {
	for (int i = 1; i < line; i += 2) {
		for (int j = 0; j < column/2; j++) {
			swap(content[i][j], content[i][column - j - 1]);
		}
	}
}

/*
 * ����������� ������� �������� �������� ��������
 */
void decodeStep7(char **&content) {
	for (int i = 0; i < line/2; i += 2) {
		for (int j = 0; j < column / 2; j++) {
			swap(content[j][i], content[line - j - 1][i]);
		}
	}
}

/*
 * ������� ������� ������� �� ������ (i+j) ������ �� 13 �������� � ������� ASCII
 */
void decodeStep8(char **&content)
{
	for (int i = 0; i < line - 1; i++) {
		for (int j = 0; j < column - 1; j++)
			if ((i + j) % 2 == 0) {
				content[i][j] = (int)content[i][j] + 13;
			}
	}
}

/*
 * ������� ������� ������� �� �������� (i+j) ����� �� 5 �������� � ������� ASCII
 */
void decodeStep9(char **&content) {
	for (int i = 0; i < line - 1; i++) {
		for (int j = 0; j < column - 1; j++)
			if ((i + j) % 2 == 0) {
				content[i][j] = (int)content[i][j] -5;
			}
	}
}


