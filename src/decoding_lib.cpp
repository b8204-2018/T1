#include "decoding_lib.h"
#include <iostream>
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
 * Меняет местами чётные и нечётные столбцы
 */
void decodeStep2(char **&content){
    int long_ = ((int*)(*content))[0];
    int kol_ = ((int*)(*content))[1];
    if (long_ % 2 == 0) {
        for (int i = 1; i <= kol_; i++) {
            for (int j = 0; j <= long_; j = j + 2) {
                char dop = content[i][j];
                content[i][j] = content[i][j + 1];
                content[i][j + 1] = dop;
            }
        }
    } else if (long_ % 2 != 0) {
        for (int i = 1; i <= kol_; i++) {
            for (int j = 0; j < long_; j = j + 2) {
                char dop = content[i][j];
                content[i][j] = content[i][j + 1];
                content[i][j + 1] = dop;
            }
        }
    } else if (long_ == 1) {
        std::cout << "Nothing to change!" << std::endl;
    }
}

/*
 * Заменяет каждый 2ий символ в каждом столбце на каждый 11ой с конца
 */
void decodeStep4(char **&content) {
	int long_ = ((int*)*content)[0];
	int kol_ = ((int*)*content)[1];
	if (kol_ > 11) {
		for (int i = 0; i < long_; i++) {
			int l = 2;
			int r = kol__ - 11;
			while ((l < kol_) && (r >= 0)) {
				swap(content[l][i], content[r][i]);
				l += 2;
				r -= 11;
			}
		}
	}
}

/*
 * Инвертирует порядок символов в чётных строках
 */
void decodeStep6(char **&content) {
	int long_ = ((int*)*content)[0];
	int kol_ = ((int*)*content)[1];
	for (int i = 0; i < kol_; i += 2) {
		int l = 0;
		int r = long_;
		while (l < r) {
			swap(content[i][l], content[i][r]);
			l++;
			r--;
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

/*
 * Инвертирует порядок символов нечётных столбцов
 */
void decodeStep7(char **&content){
    int long_ = ((int*)(*content))[0];
    int kol_ = ((int*)(*content))[1];
    for (int i = 1; i <= long_; i = i + 2) { //столбец
        int num = kol_;
        for (int j = 1; j <= kol_ / 2; j++) {  //строка
            char dop = content[j][i];
            content[j][i] = content[num][i];
            content[num][i] = dop;
            num--;
        }
    }
}

/*
 * Смещает символы стоящие на чётных (i+j) вправо на 13 символов в таблице ASCII
 */
void decodeStep8(char **&content) {
    int long_ = ((int*)(*content))[0];
    int kol_ = ((int*)(*content))[1];
    for (int i = 1; i <= kol_; i++){
        for (int j = 0; j < long_; j++){
            if ((i + j) % 2 == 0){
                if (((int) content[i][j] + 12) <= 127) {
                    content[i][j] = (char)((int) content[i][j] + 12);
                } else {
                    cout << "Symbol " << content[i][j] << " + 13 symbols " << "doesn't exists in ASCII" << endl;
                }
            }
        }
    }
}

/*
 * Смещает символы стоящие на нечётных (i+j) влево на 5 символов в таблице ASCII
 */
void decodeStep9(char **&content){

    int long_ = ((int*)(*content))[0], kol_ = ((int*)(*content))[1];
    for (int i = 1; i <= kol_; i++){
        for (int j = 0; j < long_; j++){
            if ((i+j) % 2 == 1){
                content[i][j] = (char)((int) content[i][j] - 5);
            }
        }
    }
}