#include <fstream>
#include <iostream>

using namespace std;
int w, l; //кол-во столбцов,кол-во строк
char **readFile(const char *filepath) {

    ifstream MyFile;

    MyFile.open(filepath, ios_base::in);
    if (MyFile.is_open()) {
        w = 0;
        l = w;
        cout << "File open successful" << endl;

        MyFile >> w;
        MyFile >> l;
        MyFile.get();

        string buf;

        if (w != 0 && l != 0) {
            char **res = new char *[l];
            for (int i = 0; i < l; i++) {
                getline(MyFile, buf);
                res[i] = new char[w];
                for (int j = 0; j < w; j++) {
                    res[i][j] = buf[j];
                }
            }
            MyFile.close();
            return res;

        } else {
            MyFile.close();
            return nullptr;
        }

    }
}
